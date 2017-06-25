XIncludeFile "Engine3D.pbi"



PB_InitEngine3D(#Null,#Null)

PB_OpenScreen3D(1024,768,#False,"Urho3D-PureBasic",#False)

Global CameraYaw.f
Global CameraPitch.f

*scene          = PB_CreateScene()
*octree         = PB_CreateSceneComponent(*scene, #SceneComponent_octree)
*debugRenderer  = PB_CreateSceneComponent(*scene, #SceneComponent_debugRenderer) ; easy draw debug ( futur implementation )
Global *cameranode     = PB_CreateNode(*scene, "Camera")
*camera         = PB_CreateNodeComponent(*cameranode,#NodeComponent_camera)



*skynode = PB_CreateNode(*scene, "sky")
*skybox  = PB_CreateNodeComponent(*skynode,#NodeComponent_skybox)
PB_SetModel(*skybox, PB_getResource(#Resource_Model,"Models/Box.mdl") )
PB_SetMaterial(*skybox,PB_getResource(#Resource_Material,"Materials/Skybox.xml"))


*box            = PB_CreateNode(*scene, "box")
*model          = PB_CreateNodeComponent(*box,#NodeComponent_staticModel)
PB_SetModel(*model, PB_getResource(#Resource_Model,"Models/Box.mdl") )
PB_SetNodePosition(*box,0,0,3)
PB_SetMaterial(*model,PB_getResource(#Resource_Material,"Materials/Stone.xml"))


*light = PB_CreateNode(*scene,"Light")
PB_CreateNodeComponent(*light,#NodeComponent_light)
PB_SetNodePosition(*light,0,10,0)


*viewport       = PB_CreateViewport(*scene,*cameranode)


ProcedureC _MoveCamera(*ev.Event)
  CameraYaw +  *ev\mousemove\dx * 0.05
  CameraPitch + *ev\mousemove\dy * 0.05
  PB_SetNodeRotation(*cameranode,CameraPitch,CameraYaw,0)
EndProcedure

PB_BindEvent(#Event_MouseMove,@_MoveCamera())


PB_SaveScene(*scene,"test.xml",#SceneFormat_XML)    ; can be loaded with the editor !
PB_SaveScene(*scene,"test.json",#SceneFormat_JSON)  ; can be loaded with the editor !
PB_SaveScene(*scene,"test.bin",#SceneFormat_BINARY) ; can be loaded with the editor !


While( PB_EngineRun() )
  
  event.Event
  While(PB_EnginePoolEvent(@event))
    If event\type = #Event_KeyDown
      If event\key\key = 27
        PB_EngineExit()
        End 
      EndIf 
    EndIf 
  Wend
  
  angle.f + 0.5
  
  PB_SetNodeRotation(*box,angle/2,angle,angle/4)
  
  
  
  PB_EngineRenderFrame()
  
Wend 


PB_EngineExit()




; IDE Options = PureBasic 5.60 (Windows - x86)
; CursorPosition = 17
; FirstLine = 8
; Folding = -
; EnableXP