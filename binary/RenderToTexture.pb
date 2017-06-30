XIncludeFile "Engine3D.pbi"

Global *cameraPivot,CameraYaw.f
Global *cameranode

uh3_InitEngine3D(#Null,#Null)
ExamineDesktops()
uh3_OpenScreen3D(DesktopWidth(0),DesktopHeight(0),#False,"Urho3D-PureBasic",#False)

uh3_SetDrawShadow(#True)
; uh3_SetShadowMapSize(2048)
; uh3_SetShadowMapQuality(#UH3_SHADOWQUALITY_SIMPLE_16BIT)

 
 
*scene   = uh3_CreateScene()
*octree  = uh3_CreateSceneComponent(*scene, #UH3_SCENECOMPONENT_OCTREE)

*cameraPivot    = uh3_CreateNode(*scene, "Camera")
*cameranode     = uh3_CreateNode(*cameraPivot, "Camera")
*camera         = uh3_CreateNodeComponent(*cameranode,#UH3_NODECOMPONENT_CAMERA)
uh3_SetNodePosition(*cameranode,-0.5,0.5,-0.5)
uh3_NodeLookAt(*cameranode,0,0.2,0)
uh3_SetCameraNearClip(*camera,0.1)
uh3_SetCameraFarClip(*camera,10)

*cameraRTTPivot    = uh3_CreateNode(*scene, "Camera")
*cameraNodeRTT     =  uh3_CreateNode(*cameraRTTPivot, "Camera")
*cameraRTT         =  uh3_CreateNodeComponent(*cameraNodeRTT,#UH3_NODECOMPONENT_CAMERA)
uh3_SetNodePosition(*cameraNodeRTT,-0.5,0.5,-0.5)
uh3_NodeLookAt(*cameraNodeRTT,0,0,0)
uh3_SetCameraFov(*cameraRTT,50)
 uh3_SetCameraNearClip(*cameraRTT,0.1)
 uh3_SetCameraFarClip(*cameraRTT,10)


*lightnode = uh3_CreateNode(*scene,"Light")
*light = uh3_CreateNodeComponent(*lightnode,#UH3_NODECOMPONENT_LIGHT)
; uh3_setLightRange(*light,15)
uh3_setLightType(*light,#UH3_DIRECTIONAL)
uh3_SetLightCastShadow(*light,#True) ; TODO engine parma
uh3_SetNodePosition(*lightnode,-4,2,-4)
uh3_SetNodeRotation(*lightnode,38,34,0)

; uh3_SetLightShadowResolution(*light,1)
; 
; uh3_SetLightShadowFocus(*light,#True,#True,#True,0.5,3.0)
; uh3_SetLightShadowCascade(*light,10,20,100,0,0.02,0.0)
;  uh3_SetLightShadowBias(*light,0.0002,0.5)
;  uh3_SetLightShadowNearFarRatio(*light,0.01)
;                                 
; *Texture = uh3_CreateTexture2D(512,512)
; uh3_SetTexture2DData(*Texture,0,0,512,512,0, *Pixels_RGBA)
; uh3_SetTextureFilterMode(*Texture,#UH3_FILTER_BILINEAR)

*Material = uh3_GetResource(#UH3_RESOURCE_MATERIAL,"Materials/Stone.xml")


*planeNode = uh3_CreateNode(*scene,"plane")
*plane      = uh3_CreateNodeComponent(*planeNode,#UH3_NODECOMPONENT_STATICMODEL)
uh3_SetStaticModel(*plane, uh3_GetResource(#UH3_RESOURCE_MODEL,"Models/Plane.mdl"))
uh3_SetStaticModelMaterial(*plane,*Material)


*cubeNode = uh3_CreateNode(*scene,"cube")
*cube     = uh3_CreateNodeComponent(*cubeNode,#UH3_NODECOMPONENT_STATICMODEL)
uh3_SetStaticModel(*cube, uh3_GetResource(#UH3_RESOURCE_MODEL,"Models/box.mdl"))
uh3_SetStaticModelMaterial(*cube,*Material)
uh3_SetNodePosition(*cubeNode,0,0.05,0)
uh3_SetNodeScale(*cubeNode,0.1,0.1,0.1)

*cubeNode2 = uh3_CreateNode(*scene,"cube2")
*cube2     = uh3_CreateNodeComponent(*cubeNode2,#UH3_NODECOMPONENT_STATICMODEL)
uh3_SetStaticModel(*cube2, uh3_GetResource(#UH3_RESOURCE_MODEL,"Models/box.mdl"))
uh3_SetStaticModelMaterial(*cube2,*Material)
uh3_SetNodePosition(*cubeNode2,0,0.25,0.0501)
uh3_SetNodeScale(*cubeNode2,0.41,0.26,0.1)


uh3_SetStaticModelCastShadow(*plane,#True)
uh3_SetStaticModelCastShadow(*cube,#True)
uh3_SetStaticModelCastShadow(*cube2,#True)


*planeRTTnode = uh3_CreateNode(*scene,"plane2")
*planeRTT     = uh3_CreateNodeComponent(*planeRTTnode,#UH3_NODECOMPONENT_STATICMODEL)
uh3_SetStaticModel(*planeRTT, uh3_GetResource(#UH3_RESOURCE_MODEL,"Models/Plane.mdl"))
uh3_SetNodeScale(*planeRTTnode,0.4,0.1,0.25)
uh3_SetNodePosition(*planeRTTnode,0,0.25,0)
uh3_SetNodeRotation(*planeRTTnode,-90,0,0)


*TextureRTT = uh3_CreateTexture2D(1024,768,#UH3_TEXTURE_RGB , 1 , #UH3_TEXTURE_RENDERTARGET) 
uh3_SetTextureFilterMode(*TextureRTT,#UH3_FILTER_BILINEAR)

*MatRTT = uh3_CreateMaterial()
uh3_SetMaterialTechnique(*MatRTT,0, uh3_GetResource(#UH3_RESOURCE_TECHNIQUE,"Techniques/DiffUnlit.xml"))
uh3_SetMaterialTexture(*MatRTT,*TextureRTT,#UH3_TU_DIFFUSE)

uh3_SetStaticModelMaterial(*planeRTT,*MatRTT)


*viewport2  = uh3_CreateViewport(*scene,*cameraNodeRTT,1)
*viewport   = uh3_CreateViewport(*scene,*cameraNode)


*renderSurface = uh3_GetTexture2DRenderSurface(*TextureRTT)
uh3_SetRenderSurfaceViewport(*renderSurface,1,*viewport2)
 

uh3_SaveScene(*scene,"out.xml",#UH3_SCENEFORMAT_XML)

 
 ProcedureC _MoveCamera(*ev.uh3_Event)
  CameraYaw +  *ev\mousemove\dx * 0.05
  uh3_SetNodeRotation(*cameraPivot,0,CameraYaw,0)
EndProcedure

uh3_BindEvent(#UH3_EVENT_MOUSEMOVE,@_MoveCamera())
 

 
While( uh3_EngineRun() )
  event.uh3_Event
  While(uh3_PoolEvent(@event))
    If event\type = #UH3_EVENT_KEYDOWN
      If event\key\key = 27
        uh3_EngineExit()
        Break 2 
      EndIf 
    EndIf 
  Wend
  
   uh3_NodeRotate(*cameraRTTPivot,0,0.1,0)
;   uh3_NodeLookAt(*cameraRTTPivot,0,0,0)
  
  
    uh3_EngineRenderFrame()

Wend 
; IDE Options = PureBasic 5.60 (Windows - x86)
; CursorPosition = 48
; FirstLine = 34
; Folding = -
; EnableXP