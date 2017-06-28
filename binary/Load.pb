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
uh3_InitEngine3D(#Null,#Null)
ExamineDesktops()

uh3_OpenScreen3D(DesktopWidth(0),DesktopHeight(0),#False,"Urho3D-PureBasic",#False)

Global CameraYaw.f
Global CameraPitch.f
Global *cameranode

*scene   = uh3_CreateScene()

 uh3_LoadSceneFromFile(*scene ,"SceneDemo.json",#UH3_SCENEFORMAT_JSON)

*octree         = uh3_CreateSceneComponent(*scene, #UH3_SCENECOMPONENT_OCTREE)
*debugRenderer  = uh3_CreateSceneComponent(*scene, #UH3_SCENECOMPONENT_DEBUGRENDERER)

*cameraPivot    = uh3_CreateNode(*scene, "CameraPivot")

*cameranode     = uh3_CreateNode(*cameraPivot, "CameraNode")
*camera         = uh3_CreateNodeComponent(*cameranode,#UH3_NODECOMPONENT_CAMERA)

*cameranode2     = uh3_CreateNode(*scene, "CameraNode")
*camera2         = uh3_CreateNodeComponent(*cameranode2,#UH3_NODECOMPONENT_CAMERA)


uh3_SetNodePosition(*cameranode,0,1,-10)
 *viewport   = uh3_CreateViewport(*scene,*cameranode,0)
 uh3_SetViewportRect(*viewport,0,0,DesktopWidth(0),DesktopHeight(0)/2)

*viewport2   = uh3_CreateViewport(*scene,*cameranode2,1)
uh3_SetViewportRect(*viewport2,0,DesktopHeight(0)/2,DesktopWidth(0),DesktopHeight(0))

Cam2X.f = 10
uh3_SetNodeWorldPosition(*cameranode2,0,4,Cam2X)
uh3_NodeLookAt(*cameranode2,0,0,0)

*soldier0 = uh3_GetNodeChildByName(*scene,"Soldier0",#True)
*soldier1 = uh3_GetNodeChildByName(*scene,"Soldier1",#True)
*soldier2 = uh3_GetNodeChildByName(*scene,"Soldier2",#True)

*SoldierAnimatedModel0 = uh3_GetAnimatedModel(*soldier0) ; Retrieve animatedModel
*SoldierAnimatedModel1 = uh3_GetAnimatedModel(*soldier1)
*SoldierAnimatedModel2 = uh3_GetAnimatedModel(*soldier2)

Soldiers(0)\AnimationController = uh3_GetAnimationController(*SoldierAnimatedModel0) ; Retrieve AnimationController component
Soldiers(1)\AnimationController = uh3_GetAnimationController(*SoldierAnimatedModel1)
Soldiers(2)\AnimationController = uh3_GetAnimationController(*SoldierAnimatedModel2)


For i = 0 To 2
  Soldiers(i)\Anim[0]\name = "Models/Swat/Swat_SprintFwd.ani"
  Soldiers(i)\Anim[1]\name = "Models/Swat/Swat_WalkFwd.ani"
  Soldiers(i)\Anim[2]\name = "Models/Swat/Swat_RunFwd.ani"
  Soldiers(i)\Anim[3]\name = "Models/Swat/Swat_DeathFromFrontHeadshot.ani"
  Soldiers(i)\AnimState    = Random(3,0)
  For j = 0 To 3
    Soldiers(i)\Anim[j]\timeToAnim =  ElapsedMilliseconds() + Random(2000,500)
  Next  

  uh3_PlayAnimation(Soldiers(i)\AnimationController , Soldiers(i)\Anim[Soldiers(i)\AnimState]\name,0,#True,5.0)
  uh3_SetAnimationSpeed(Soldiers(i)\AnimationController,Soldiers(i)\Anim[Soldiers(i)\AnimState]\name,0.5)
  
Next 



ProcedureC _MoveCamera(*ev.Event)
  CameraYaw +  *ev\mousemove\dx * 0.05
  CameraPitch + *ev\mousemove\dy * 0.05
  uh3_SetNodeRotation(*cameraPivot,CameraPitch,CameraYaw,0)
EndProcedure

ProcedureC _ZoomCamera(*ev.Event)
  uh3_NodeTranslate(*cameranode,0,0,  *ev\mousewheel\wheel  ,0)
EndProcedure



uh3_BindEvent(#UH3_EVENT_MOUSEMOVE,@_MoveCamera())
uh3_BindEvent(#UH3_EVENT_MOUSEWHEEL,@_ZoomCamera())



While( uh3_EngineRun() )
  event.Event
  While(uh3_PoolEvent(@event))
    If event\type = #UH3_EVENT_KEYDOWN
      If event\key\key = 27
        uh3_EngineExit()
        Break 2 
      EndIf 
    EndIf 
  Wend

  For i = 0 To 2  
    If Soldiers(i)\Anim[Soldiers(i)\AnimState]\timeToAnim < ElapsedMilliseconds()
      Soldiers(i)\Anim[Soldiers(i)\AnimState]\timeToAnim = ElapsedMilliseconds() + Random(2000,500)
      Soldiers(i)\AnimState =  Random(3,0) 
      
      If Soldiers(i)\AnimState = 3      
        uh3_PlayAnimation(Soldiers(i)\AnimationController , Soldiers(i)\Anim[Soldiers(i)\AnimState]\name,0,#False,2.0)
      Else
        uh3_PlayAnimation(Soldiers(i)\AnimationController , Soldiers(i)\Anim[Soldiers(i)\AnimState]\name,0,#True,2.0)
      EndIf
      
      uh3_SetAnimationSpeed(Soldiers(i)\AnimationController,Soldiers(i)\Anim[Soldiers(i)\AnimState]\name,0.5)
      
      
      
    EndIf 
    
    If Soldiers(i)\AnimState = 3
      If uh3_AnimationIsEnd(Soldiers(i)\AnimationController,Soldiers(i)\Anim[3]\name)
        uh3_StopAllAnimation(Soldiers(i)\AnimationController,2)
      EndIf
    EndIf
    
      
    
  Next
  
  Cam2X = 20 * Cos(ElapsedMilliseconds()/1000)
  
  uh3_SetNodeWorldPosition(*cameranode2,0,4,Cam2X)
  uh3_NodeLookAt(*cameranode2,0,0,0)
  
    uh3_EngineRenderFrame()

Wend 




; IDE Options = PureBasic 5.60 (Windows - x86)
; ExecutableFormat = Console
; CursorPosition = 148
; FirstLine = 106
; Folding = -
; EnableXP