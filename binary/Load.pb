XIncludeFile "Engine3D.pbi"



PB_InitEngine3D(#Null,#Null)

PB_OpenScreen3D(1024,768,#False,"Urho3D-PureBasic",#False)

Global CameraYaw.f
Global CameraPitch.f
Global *cameranode

*scene          = PB_CreateScene()

Debug PB_LoadScene(*scene ,"test.json",#SceneFormat_JSON)

*cameranode = PB_GetChildByName(*scene,"Camera",#True)
*box        = PB_GetChildByName(*scene,"Box",#True)

*viewport       = PB_CreateViewport(*scene,*cameranode)


ProcedureC _MoveCamera(*ev.Event)
  CameraYaw +  *ev\mousemove\dx * 0.05
  CameraPitch + *ev\mousemove\dy * 0.05
  PB_SetNodeRotation(*cameranode,CameraPitch,CameraYaw,0)
EndProcedure

PB_BindEvent(#Event_MouseMove,@_MoveCamera())



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
; CursorPosition = 46
; FirstLine = 3
; Folding = -
; EnableXP