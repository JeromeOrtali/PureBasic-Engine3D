XIncludeFile "Engine3D.pbi"





uh3_InitEngine3D(#Null,#Null)
ExamineDesktops()
uh3_OpenScreen3D(DesktopWidth(0),DesktopHeight(0),#False,"Urho3D-PureBasic",#False)


*scene   = uh3_CreateScene()
*octree  = uh3_CreateSceneComponent(*scene, #UH3_SCENECOMPONENT_OCTREE)

*cameraPivot    = uh3_CreateNode(*scene, "Camera")
*cameranode     = uh3_CreateNode(*cameraPivot, "Camera")
*camera         = uh3_CreateNodeComponent(*cameranode,#UH3_NODECOMPONENT_CAMERA)

uh3_SetNodePosition(*cameranode,-1,2,-1)
uh3_NodeLookAt(*cameranode,0,0,0)

*lightnode = uh3_CreateNode(*scene,"Light")
*light = uh3_CreateNodeComponent(*lightnode,#UH3_NODECOMPONENT_LIGHT)
uh3_setLightRange(*light,5)
uh3_setLightType(*light,#UH3_POINT)
uh3_SetNodePosition(*lightnode,-1,2,-1)

;
; TEXTURE 1
;
CreateImage(0,512,512,32,$BADF00D)

StartDrawing(ImageOutput(0))
  DrawingMode(#PB_2DDrawing_AllChannels)
  *Pixels_RGBA = DrawingBuffer()
  Box(0,0,256,256,RGBA(255,128,64,255)) ; READ BGRA !!!!
  Box(256,256,256,256,RGBA(255,128,64,255)) ; READ BGRA !!!!
  Circle(256,256,64,RGBA(0,0,0,0))
  DrawText(10,10,"Texture hard coded by PB !")
StopDrawing()


;
; TEXTURE 2 (RANDOM)
;
*RandomPixel = AllocateMemory(64*64*4)
RandomData(*RandomPixel,64*64*4)


; 1 CREATE TEXTURE
*Texture0 = uh3_CreateTexture2D(512,512,#UH3_TEXTURE_RGBA, 1 , #UH3_TEXTURE_DYNAMIC)
uh3_SetTexture2DData(*Texture0,0,0,512,512,0, *Pixels_RGBA)
uh3_SetTextureFilterMode(*Texture0,#UH3_FILTER_BILINEAR)

; 2 CREATE MATERIAL
*Material0 = uh3_CreateMaterial()
uh3_SetMaterialTechnique(*Material0,0, uh3_GetResource(#UH3_RESOURCE_TECHNIQUE,"Techniques/DiffAlpha.xml"))  
uh3_SetMaterialTexture(*Material0,*Texture0,#UH3_TU_DIFFUSE)
uh3_SetMaterialUVTransform(*Material0,0,0,0,1,-1) ; Revert texture ( OpenGL reversed coordinnates )

; 3 CREATE MODEL AND ASIGN MATERIAL
*planeNode = uh3_CreateNode(*scene,"plane")
*plane      = uh3_CreateNodeComponent(*planeNode,#UH3_NODECOMPONENT_STATICMODEL)
uh3_SetStaticModel(*plane, uh3_GetResource(#UH3_RESOURCE_MODEL,"Models/Plane.mdl"))
uh3_SetStaticModelMaterial(*plane,*Material0)





*Texture = uh3_CreateTexture2D(64,64)
uh3_SetTexture2DData(*Texture,0,0,64,64,0, *RandomPixel)
uh3_SetTextureFilterMode(*Texture,#UH3_FILTER_BILINEAR)

*Material = uh3_CreateMaterial()
uh3_SetMaterialTechnique(*Material,0, uh3_GetResource(#UH3_RESOURCE_TECHNIQUE,"Techniques/Diff.xml"))  
uh3_SetMaterialTexture(*Material,*Texture,#UH3_TU_DIFFUSE)
uh3_SetMaterialUVTransform(*Material,0,0,0,1,-10)

*cylinderNode = uh3_CreateNode(*scene,"cylinder")
*cylinder = uh3_CreateNodeComponent(*cylinderNode,#UH3_NODECOMPONENT_STATICMODEL)
uh3_SetStaticModel(*cylinder, uh3_GetResource(#UH3_RESOURCE_MODEL,"Models/Cylinder.mdl"))
uh3_SetNodeScale(*cylinderNode,0.15,10.0,0.15)
uh3_SetStaticModelMaterial(*cylinder,*Material)



 *viewport   = uh3_CreateViewport(*scene,*cameranode)
 
;  uh3_SetViewportBackgroundColor(*viewport,RGB(255,255,255))
 
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
  
  uh3_NodeRotate(*cameraPivot,0,0.1,0)
  
  uh3_NodeLookAt(*cameranode,0,0,0)
  
  
  PokeI(*Pixels_RGBA + ((Random(511)*4) + 512 * (Random(511)*4)),RGBA(0,0,0,0)) 
  uh3_SetTexture2DData(*Texture0,0,0,512,512,0, *Pixels_RGBA)

  
    uh3_EngineRenderFrame()

Wend 
; IDE Options = PureBasic 5.60 (Windows - x86)
; CursorPosition = 50
; FirstLine = 30
; EnableXP