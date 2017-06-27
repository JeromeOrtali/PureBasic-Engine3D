XIncludeFile "Engine3D.pbi"



uh3_InitEngine3D(#Null,#Null)

uh3_OpenScreen3D(1024,768,#False,"Urho3D-PureBasic",#False)

Global CameraYaw.f
Global CameraPitch.f

*scene          = uh3_CreateScene()
*octree         = uh3_CreateSceneComponent(*scene, #SceneComponent_octree)
*debugRenderer  = uh3_CreateSceneComponent(*scene, #SceneComponent_debugRenderer) ; easy draw debug ( futur implementation )
Global *cameranode     = uh3_CreateNode(*scene, "Camera")
*camera         = uh3_CreateNodeComponent(*cameranode,#NodeComponent_camera)

uh3_SetNodePosition(*cameranode,0,1,0)

*skynode = uh3_CreateNode(*scene, "sky")
*skybox  = uh3_CreateNodeComponent(*skynode,#NodeComponent_skybox)
uh3_SetModel(*skybox, uh3_getResource(#Resource_Model,"Models/Box.mdl") )
uh3_SetMaterial(*skybox,uh3_getResource(#Resource_Material,"Materials/Skybox.xml"))


*box            = uh3_CreateNode(*scene, "box")
*model          = uh3_CreateNodeComponent(*box,#NodeComponent_staticModel)
uh3_SetModel(*model, uh3_getResource(#Resource_Model,"Models/Box.mdl") )
uh3_SetNodePosition(*box,0,0,3)
uh3_SetMaterial(*model,uh3_getResource(#Resource_Material,"Materials/Stone.xml"))




*light = uh3_CreateNode(*scene,"Light")
uh3_CreateNodeComponent(*light,#NodeComponent_light)
uh3_SetNodePosition(*light,10,10,10)


*lightSpotNode = uh3_CreateNode(*scene,"LightSpot")
*lightComponent = uh3_CreateNodeComponent(*lightSpotNode,#NodeComponent_light)
uh3_setLightType(*lightComponent,#LightSpot)
uh3_SetNodePosition(*lightSpotNode,0,0,0)
uh3_SetNodeRotation(*lightSpotNode,0,0,90)
uh3_setLightFov(*lightComponent,20)
uh3_setLightColor(*lightComponent,255,128,64)

*viewport       = uh3_CreateViewport(*scene,*cameranode)


ProcedureC _MoveCamera(*ev.Event)
  CameraYaw +  *ev\mousemove\dx * 0.05
  CameraPitch + *ev\mousemove\dy * 0.05
  uh3_SetNodeRotation(*cameranode,CameraPitch,CameraYaw,0)
EndProcedure

uh3_BindEvent(#Event_MouseMove,@_MoveCamera())




While( uh3_EngineRun() )
  
  event.Event
  While(uh3_PoolEvent(@event))
    If event\type = #Event_KeyDown
      If event\key\key = 27
        uh3_EngineExit()
        End 
      EndIf 
    EndIf 
  Wend
  
  angle.f + 0.5
  
  uh3_SetNodeRotation(*box,0,angle,0)
  
  
  
  uh3_EngineRenderFrame()
  
Wend 


uh3_EngineExit()




; IDE Options = PureBasic 5.60 (Windows - x86)
; CursorPosition = 44
; FirstLine = 13
; Folding = -
; EnableXP