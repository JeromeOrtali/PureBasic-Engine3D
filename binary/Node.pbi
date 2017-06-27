XIncludeFile "Config.pbi"

Enumeration
  #NodeComponent_camera
  #NodeComponent_staticModel  
  #NodeComponent_animatedModel  
  #NodeComponent_skybox  
  #NodeComponent_light
  #NodeComponent_terrain
  #NodeComponent_script
EndEnumeration

Enumeration
  #TS_LOCAL
  #TS_PARENT
  #TS_WORLD
EndEnumeration


IMPORT_FUNCTION(PB_CreateNodeComponent, .i , *node _ component.l )
IMPORT_FUNCTION(PB_GetChildByName, .i, *node _ name.s _ recursive.b )
IMPORT_FUNCTION(PB_GetChildByID, .i, *node _ id.l )
IMPORT_FUNCTION(PB_SetNodePosition, void , *node _ x.f _ y.f _ z.f )
IMPORT_FUNCTION(PB_NodeTranslate, void , *node _ x.f _ y.f _ z.f _ mode.l)
IMPORT_FUNCTION(PB_SetNodeRotation, void , *node _ x.f _ y.f _ z.f )
IMPORT_FUNCTION(PB_NodeRotate, void , *node _ x.f _ y.f _ z.f _ mode.l )

; to script.pbi
IMPORT_FUNCTION(PB_NodeLoadScript, void, *node _ *resourceFile _ class.s)

; to go to Model.pbi
IMPORT_FUNCTION(PB_SetModel, void , *model _ *resource)
IMPORT_FUNCTION(PB_SetMaterial, void , *model _ *resource)

; to go to AnimatedModel.pbi
IMPORT_FUNCTION(PB_GetAnimatedModel, .i , *node)
IMPORT_FUNCTION(PB_GetAnimationController, .i , *AnimatedModel)
IMPORT_FUNCTION(PB_PlayAnimation, void , *controller _ name.s _ layer.a _ looped.l _ fadeTime.f)
IMPORT_FUNCTION(PB_SetAnimationSpeed, void , *controller _ name.s _ speed.f)
IMPORT_FUNCTION(PB_StopAllAnimation, void, *controller _ fadeTime.f)
IMPORT_FUNCTION(PB_AnimationIsEnd, .l , *controller _ name.s)
; IDE Options = PureBasic 5.60 (Windows - x86)
; CursorPosition = 15
; EnableXP