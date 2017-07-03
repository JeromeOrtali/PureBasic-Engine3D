XIncludeFile "Engine3D.pbi"



Define *Scene
Define *Octree,*Debug
Define *ZoneNode, *Zone
Global *CameraNode,*Camera
Define *CameraReflectionNode,*CameraReflection
Define *SkyboxNode,*Skybox
Define *BoxNode,*Box
Define *TerrainNode,*Terrain
Define *Waterplane,*WaterClipPlane
Define *WaterNode,*Water,*WaterMat
Define *LightNode,*Light
Define *RenderTexture,*RenderSurface
Define *Viewport,*RttViewport
Define Event.uh3_Event
Global CameraPitch.f
Global CameraYaw.f
Global MoveForward.b
Global MoveBackward.b

Declare MoveCameraCallback(*ev.uh3_Event)

;
; Init engine
;



uh3_InitEngine3D(0,0)

ExamineDesktops()
uh3_OpenScreen3D(DesktopWidth(0),DesktopHeight(0),#False,"Urho3D-PureBasic",#False)
uh3_SetHDRRendering(#True)
;
; Create main scene
;
*Scene   = uh3_CreateScene()
*Octree  = uh3_CreateSceneComponent(*Scene,#UH3_SCENECOMPONENT_OCTREE)
*Debug   = uh3_CreateSceneComponent(*scene, #UH3_SCENECOMPONENT_DEBUGRENDERER)

*ZoneNode           = uh3_CreateNode(*scene,"Zone")
*Zone               = uh3_CreateNodeComponent(*ZoneNode,#UH3_NODECOMPONENT_ZONE)
uh3_SetZoneSize(*Zone,-10000,-10000,-10000,10000,10000,10000)
uh3_SetZoneAmbientColor(*Zone,RGB(16,8,4))
uh3_SetZonefogColor(*Zone,$FFFFFFFF)
uh3_SetZoneFogStart(*Zone,500)
uh3_SetZoneFogEnd(*Zone,2500)



;
; Create Camera (node + component) and Camera reflection used by water ( render to texture )
;
*CameraNode           = uh3_CreateNode(*scene,"Camera")
*Camera               = uh3_CreateNodeComponent(*CameraNode,#UH3_NODECOMPONENT_CAMERA)
uh3_SetNodePosition(*CameraNode,300,300,-1250)
uh3_SetCameraFarClip(*Camera,2000)
; uh3_SetCameraNearClip(*Camera,0.01)
uh3_NodeLookAt(*CameraNode,0,1,0)
CameraPitch = uh3_GetNodeRotationX(*CameraNode)
CameraYaw  =  uh3_GetNodeRotationY(*CameraNode)








;
;
;

;
; Create directionnal light
;
*LightNode           = uh3_CreateNode(*scene,"DirectionalLight")
uh3_SetNodeDirection(*LightNode,0.6,-1.0,0.8)
*Light               = uh3_CreateNodeComponent(*LightNode,#UH3_NODECOMPONENT_LIGHT)
uh3_SetLightType(*Light,#UH3_DIRECTIONAL)
uh3_SetLightCastShadow(*Light,#True)
uh3_SetLightShadowBias(*Light,0.00025,0.5)
uh3_SetLightShadowCascade(*light,10,50,800,0,0.8,1)
uh3_SetLightSpecularIntensity(*Light,0.5)
uh3_SetLightColor(*Light,$FFFFFFFF)
uh3_SetLightShadowFadeDistance(*Light,100)

;
; Skybox
;
*SkyboxNode           = uh3_CreateNode(*scene,"Skybox")
*Skybox               = uh3_CreateNodeComponent(*SkyboxNode,#UH3_NODECOMPONENT_STATICMODEL) ; bug with skybox component & reflection ? why not reflect ??
uh3_SetNodePosition(*SkyboxNode,0,0,0)
uh3_SetNodeScale(*SkyboxNode,50000,50000,50000)
uh3_SetSkyboxModel(*Skybox,uh3_GetResource(#UH3_RESOURCE_MODEL,"Models/Box.mdl"))
uh3_SetSkyboxMaterial(*Skybox, uh3_GetResource(#UH3_RESOURCE_MATERIAL,"Materials/Skybox.xml"))


;
; Water model
;
*WaterNode           = uh3_CreateNode(*scene,"Water")
*Water               = uh3_CreateNodeComponent(*WaterNode,#UH3_NODECOMPONENT_STATICMODEL)
uh3_SetNodeScale(*WaterNode,4096,1,4096)
uh3_SetNodePosition(*WaterNode,0,220,0)
uh3_SetStaticModel(*Water, uh3_GetResource(#UH3_RESOURCE_MODEL,"Models/Plane.mdl"))
*WaterMat = uh3_GetResource(#UH3_RESOURCE_MATERIAL,"Materials/Water.xml")
uh3_SetStaticModelMaterial(*Water, *WaterMat)
uh3_SetStaticModelViewMask(*water,$80000000)


;
; Terrain
;
*TerrainNode          = uh3_CreateNode(*scene,"Terrain")
*Terrain              = uh3_CreateNodeComponent(*TerrainNode,#UH3_NODECOMPONENT_TERRAIN)
uh3_SetTerrainPatchSize(*Terrain,64)
uh3_SetTerrainSpacing(*Terrain,2,2,2) ; space between vertices
uh3_SetTerrainSmoothing(*Terrain,#True)
uh3_SetTerrainHeightMap(*Terrain, uh3_GetResource(#UH3_RESOURCE_IMAGE,"Textures/HeightMap_2048_2.png"))
uh3_SetTerrainMaterial(*Terrain, uh3_GetResource(#UH3_RESOURCE_MATERIAL,"Materials/Terrain.xml"))
uh3_SetTerrainOccluder(*Terrain,#True)
uh3_SetTerrainCastShadow(*Terrain,#True)


;
; Water plane , Create a mathematical plane to represent the water in calculations
;
*Waterplane     = uh3_CreatePlane2(*WaterNode,0,1,0,0,0,0)
*WaterClipPlane = uh3_CreatePlane2(*WaterNode,0,1,0,0,0,0)

;
; Camera reflection, attached to the regular camera
;
*CameraReflectionNode           = uh3_CreateNode(*CameraNode,"CameraReflection")
*CameraReflection               = uh3_CreateNodeComponent(*CameraReflectionNode,#UH3_NODECOMPONENT_CAMERA)
uh3_SetCameraFarClip(*CameraReflection,2000)
uh3_SetCameraViewMask(*CameraReflection,$7FFFFFFF)
uh3_SetCameraAutoAspectRatio(*CameraReflection,#False)
uh3_SetCameraUseReflection(*CameraReflection,#True)
uh3_SetCameraReflectionPlane(*CameraReflection,*Waterplane)
uh3_SetCameraUseClipping(*CameraReflection,#True)
uh3_SetCameraClipPlane(*CameraReflection,*WaterClipPlane)
uh3_SetCameraAspectRatio(*CameraReflection,DesktopWidth(0) / DesktopHeight(0))
 


;
; Render texture , to render reflection...
;
*RenderTexture = uh3_CreateTexture2D(1024,1024,#UH3_TEXTURE_RGB,1,#UH3_TEXTURE_RENDERTARGET)
uh3_SetTextureFilterMode(*RenderTexture,#UH3_FILTER_BILINEAR)
*RenderSurface = uh3_GetTexture2DRenderSurface(*RenderTexture)
*RttViewport = uh3_CreateUnasignedViewport(*Scene,*CameraReflectionNode)
uh3_SetRenderSurfaceViewport(*RenderSurface,0,*RttViewport)
uh3_SetMaterialTexture(*WaterMat,*RenderTexture,#UH3_TU_DIFFUSE)

uh3_SetMaterialShaderParameterVector3(*WaterMat,"WaterTint",0.5,0.8,0.4)
uh3_SetMaterialShaderParameterFloat(*WaterMat,"FresnelPower",1)
uh3_SetMaterialShaderParameterFloat(*WaterMat,"NoiseTiling",500)
uh3_SetMaterialShaderParameterFloat(*WaterMat,"NoiseStrength",0.025)
uh3_SetMaterialShaderParameterVector4(*WaterMat,"MatSpecColor",1,0,0,1)

;
; random box
;
For i = 0 To 10000
  *BoxNode             = uh3_CreateNode(*scene,"Water")
  *Box                 = uh3_CreateNodeComponent(*BoxNode,#UH3_NODECOMPONENT_STATICMODEL)
  
  bx.f = Random(2000)-1000
  bz.f = Random(2000)-1000
  by.f = uh3_GetTerrainHeight(*Terrain,bx,0,bz)
  
  
  nx.f
  ny.f
  nz.f  
  uh3_GetTerrainNormal(*Terrain,bx,by,bz,@nx,@ny,@nz)
  
  uh3_setNodeScale(*BoxNode,5,20,5)
  uh3_SetNodePosition(*BoxNode,bx,by+10,bz)
  uh3_SetNodeDirection(*BoxNode,nx,ny,nz)
  uh3_SetNodePitch(*BoxNode,90)
  
  uh3_SetStaticModel(*Box, uh3_GetResource(#UH3_RESOURCE_MODEL,"Models/Box.mdl"))
  uh3_SetStaticModelMaterial(*Box, uh3_GetResource(#UH3_RESOURCE_MATERIAL,"Materials/Stone.xml"))
  uh3_SetStaticModelCastShadow(*Box,#True)
Next 
*Viewport = uh3_CreateViewport(*Scene,*CameraNode)



; H.f = uh3_GetTerrainHeight(*terrain,uh3_GetNodePositionX(*CameraNode),0,uh3_GetNodePositionZ(*CameraNode))
; uh3_SetNodePosition(*CameraNode,uh3_GetNodePositionX(*CameraNode),H+1,uh3_GetNodePositionZ(*CameraNode))


uh3_BindEvent(#UH3_EVENT_MOUSEMOVE,@MoveCameraCallback())
uh3_BindEvent(#UH3_EVENT_KEYDOWN,@MoveCameraCallback())
uh3_BindEvent(#UH3_EVENT_KEYUP,@MoveCameraCallback())

While( uh3_EngineRun() )

  While(uh3_PoolEvent(Event))
    If Event\type = #UH3_EVENT_KEYDOWN
      If Event\key\key = 27
        uh3_EngineExit()
        Break 2 
      EndIf 
    EndIf 
  Wend
;  uh3_DrawDebugGeometry(#UH3_NODECOMPONENT_STATICMODEL,*BoxNode,*Debug,0)
  
  If MoveForward
    uh3_NodeTranslate(*CameraNode,0,0,1)
  EndIf 
  
  If MoveBackward
    uh3_NodeTranslate(*CameraNode,0,0,-1)
  EndIf
  
  
  
  uh3_EngineRenderFrame() ; to be removed

Wend 



ProcedureC MoveCameraCallback(*ev.uh3_Event)
  
  If *ev\type = #UH3_EVENT_MOUSEMOVE
    CameraYaw   +  *ev\mousemove\dx * 0.05
    CameraPitch +  *ev\mousemove\dy * 0.05
    uh3_SetNodeRotation(*CameraNode,CameraPitch,CameraYaw,0)
  ElseIf *ev\type = #UH3_EVENT_KEYDOWN
    
    If *ev\key\key = 1073741906 ; up 
      MoveForward = #True
    EndIf 
    
    If *ev\key\key = 1073741905 ; down
      MoveBackward = #True 
    EndIf 
  ElseIf *ev\type = #UH3_EVENT_KEYUP
;     
;     Debug uh3_GetNodePositionX(*CameraNode)
;     Debug uh3_GetNodePositionY(*CameraNode)
;     Debug uh3_GetNodePositionZ(*CameraNode)
;     Debug uh3_GetNodeRotationX(*CameraNode)
;     Debug uh3_GetNodeRotationy(*CameraNode)
;     Debug uh3_GetNodeRotationz(*CameraNode)
;     Debug ""
    
    If *ev\key\key = 1073741906 ; up 
      MoveForward = #False 
    EndIf 
    
    If *ev\key\key = 1073741905 ; down
      MoveBackward = #False 
    EndIf 
  EndIf 
EndProcedure

; IDE Options = PureBasic 5.60 (Windows - x86)
; ExecutableFormat = Console
; CursorPosition = 184
; FirstLine = 156
; Folding = -
; EnableXP
; DisableDebugger
; CompileSourceDirectory