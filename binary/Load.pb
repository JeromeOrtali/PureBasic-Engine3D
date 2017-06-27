XIncludeFile "Engine3D.pbi"

Structure Animation
  name.s
  timeToAnim.l
EndStructure

Structure Soldier
  *AnimationController
  Anim.Animation[4]
  AnimState.l
EndStructure

Dim Soldiers.Soldier(3)






Global *cameraPivot

OpenConsole()
PB_InitEngine3D(#Null,#Null)
ExamineDesktops()

PB_OpenScreen3D(DesktopWidth(0),DesktopHeight(0),#False,"Urho3D-PureBasic",#False)

Global CameraYaw.f
Global CameraPitch.f
Global *cameranode

*scene          = PB_CreateScene()

 PB_LoadScene(*scene ,"SceneDemo.json",#SceneFormat_json)

*octree         = PB_CreateSceneComponent(*scene, #SceneComponent_octree)
*debugRenderer  = PB_CreateSceneComponent(*scene, #SceneComponent_debugRenderer)

*cameraPivot    = PB_CreateNode(*scene, "CameraPivot")

*cameranode     = PB_CreateNode(*cameraPivot, "CameraNode")
*camera         = PB_CreateNodeComponent(*cameranode,#NodeComponent_camera)

PB_SetNodePosition(*cameranode,0,1,-10)
*viewport   = PB_CreateViewport(*scene,*cameranode)


*soldier0 = PB_GetChildByName(*scene,"Soldier0",#True)
*soldier1 = PB_GetChildByName(*scene,"Soldier1",#True)
*soldier2 = PB_GetChildByName(*scene,"Soldier2",#True)

*SoldierAnimatedModel0 = PB_GetAnimatedModel(*soldier0) ; Retrieve animatedModel
*SoldierAnimatedModel1 = PB_GetAnimatedModel(*soldier1)
*SoldierAnimatedModel2 = PB_GetAnimatedModel(*soldier2)

Soldiers(0)\AnimationController = PB_GetAnimationController(*SoldierAnimatedModel0) ; Retrieve AnimationController component
Soldiers(1)\AnimationController = PB_GetAnimationController(*SoldierAnimatedModel1)
Soldiers(2)\AnimationController = PB_GetAnimationController(*SoldierAnimatedModel2)


For i = 0 To 2
  Soldiers(i)\Anim[0]\name = "Models/Swat/Swat_SprintFwd.ani"
  Soldiers(i)\Anim[1]\name = "Models/Swat/Swat_WalkFwd.ani"
  Soldiers(i)\Anim[2]\name = "Models/Swat/Swat_RunFwd.ani"
  Soldiers(i)\Anim[3]\name = "Models/Swat/Swat_DeathFromFrontHeadshot.ani"
  Soldiers(i)\AnimState    = Random(3,0)
  For j = 0 To 3
    Soldiers(i)\Anim[j]\timeToAnim =  ElapsedMilliseconds() + Random(2000,500)
  Next  

  PB_PlayAnimation(Soldiers(i)\AnimationController , Soldiers(i)\Anim[Soldiers(i)\AnimState]\name,0,#True,5.0)
  PB_SetAnimationSpeed(Soldiers(i)\AnimationController,Soldiers(i)\Anim[Soldiers(i)\AnimState]\name,0.5)
  
Next 



ProcedureC _MoveCamera(*ev.Event)
  CameraYaw +  *ev\mousemove\dx * 0.05
  CameraPitch + *ev\mousemove\dy * 0.05
  PB_SetNodeRotation(*cameraPivot,CameraPitch,CameraYaw,0)
EndProcedure

ProcedureC _ZoomCamera(*ev.Event)
  PB_NodeTranslate(*cameranode,0,0,  *ev\mousewheel\wheel  ,0)
EndProcedure



ProcedureC _Loaded(*ev.Event)
  Debug "load : " + *ev\backgroundResourceLoaded\name
EndProcedure


PB_BindEvent(#Event_MouseMove,@_MoveCamera())
PB_BindEvent(#Event_MouseWheel,@_ZoomCamera())
PB_BindEvent(#Event_BackgroundResourceLoaded,@_Loaded())



While( PB_EngineRun() )
  event.Event
  While(PB_EnginePoolEvent(@event))
    If event\type = #Event_KeyDown
      If event\key\key = 27
        PB_EngineExit()
        Break 2 
      EndIf 
    EndIf 
  Wend

  For i = 0 To 2  
    If Soldiers(i)\Anim[Soldiers(i)\AnimState]\timeToAnim < ElapsedMilliseconds()
      Soldiers(i)\Anim[Soldiers(i)\AnimState]\timeToAnim = ElapsedMilliseconds() + Random(2000,500)
      Soldiers(i)\AnimState =  Random(3,0) 
      
      If Soldiers(i)\AnimState = 3      
        PB_PlayAnimation(Soldiers(i)\AnimationController , Soldiers(i)\Anim[Soldiers(i)\AnimState]\name,0,#False,2.0)
      Else
        PB_PlayAnimation(Soldiers(i)\AnimationController , Soldiers(i)\Anim[Soldiers(i)\AnimState]\name,0,#True,2.0)
      EndIf
      
      PB_SetAnimationSpeed(Soldiers(i)\AnimationController,Soldiers(i)\Anim[Soldiers(i)\AnimState]\name,0.5)
      
      
      
    EndIf 
    
    If Soldiers(i)\AnimState = 3
      If PB_AnimationIsEnd(Soldiers(i)\AnimationController,Soldiers(i)\Anim[3]\name)
        PB_StopAllAnimation(Soldiers(i)\AnimationController,2)
      EndIf
    EndIf
    
      
    
  Next
  
  

    PB_EngineRenderFrame()

Wend 




; IDE Options = PureBasic 5.60 (Windows - x86)
; ExecutableFormat = Console
; CursorPosition = 96
; FirstLine = 54
; Folding = -
; EnableXP