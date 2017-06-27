XIncludeFile "Config.pbi"

;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////
HELP_DESC("")
HELP_PARAM("")
IMPORT_FUNCTION(uh3_GetAnimatedModel, .i , *node)

HELP_DESC("")
HELP_PARAM("")
IMPORT_FUNCTION(uh3_GetAnimationController, .i , *AnimatedModel)

HELP_DESC("")
HELP_PARAM("")
HELP_PARAM("")
HELP_PARAM("")
HELP_PARAM("")
HELP_PARAM("")
IMPORT_FUNCTION(uh3_PlayAnimation, void , *controller _ name.s _ layer.a _ looped.l _ fadeTime.f)

HELP_DESC("")
HELP_PARAM("")
HELP_PARAM("")
HELP_PARAM("")
IMPORT_FUNCTION(uh3_SetAnimationSpeed, void , *controller _ name.s _ speed.f)

HELP_DESC("")
HELP_PARAM("")
HELP_PARAM("")
IMPORT_FUNCTION(uh3_StopAllAnimation, void, *controller _ fadeTime.f)

HELP_DESC("")
HELP_PARAM("")
HELP_PARAM("")
IMPORT_FUNCTION(uh3_AnimationIsEnd, .l , *controller _ name.s)

; IDE Options = PureBasic 5.60 (Windows - x86)
; CursorPosition = 36
; EnableXP