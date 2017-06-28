XIncludeFile "Config.pbi"

;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////
IMPORT_FUNCTION(uh3_GetAnimatedModel, .i , *node)
IMPORT_FUNCTION(uh3_GetAnimationController, .i , *AnimatedModel)
IMPORT_FUNCTION(uh3_PlayAnimation, void , *controller _ name.s _ layer.a _ looped.l _ fadeTime.f)
IMPORT_FUNCTION(uh3_SetAnimationSpeed, void , *controller _ name.s _ speed.f)
IMPORT_FUNCTION(uh3_StopAllAnimation, void, *controller _ fadeTime.f)
IMPORT_FUNCTION(uh3_AnimationIsEnd, .l , *controller _ name.s)

; IDE Options = PureBasic 5.60 (Windows - x86)
; CursorPosition = 11
; EnableXP