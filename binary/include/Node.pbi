XIncludeFile "Config.pbi"

;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////
Enumeration ; different component for node
  #NodeComponent_camera
  #NodeComponent_staticModel  
  #NodeComponent_animatedModel  
  #NodeComponent_skybox  
  #NodeComponent_light
  #NodeComponent_terrain
  #NodeComponent_script
  ;...
  ; more will be arrive...
  ;...
EndEnumeration

;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////
Enumeration
  #TS_LOCAL
  #TS_PARENT
  #TS_WORLD
EndEnumeration

;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////
HELP_DESC("")
HELP_PARAM("")
HELP_PARAM("")
IMPORT_FUNCTION(uh3_CreateNodeComponent, .i , *node _ component.l )

HELP_DESC("")
HELP_PARAM("")
HELP_PARAM("")
HELP_PARAM("")
IMPORT_FUNCTION(uh3_GetChildByName, .i, *node _ name.s _ recursive.b )

HELP_DESC("")
HELP_PARAM("")
HELP_PARAM("")
IMPORT_FUNCTION(uh3_GetChildByID, .i, *node _ id.l )

HELP_DESC("")
HELP_PARAM("")
HELP_PARAM("")
HELP_PARAM("")
HELP_PARAM("")
IMPORT_FUNCTION(uh3_SetNodePosition, void , *node _ x.f _ y.f _ z.f )

HELP_DESC("")
HELP_PARAM("")
HELP_PARAM("")
HELP_PARAM("")
HELP_PARAM("")
HELP_PARAM("")
IMPORT_FUNCTION(uh3_NodeTranslate, void , *node _ x.f _ y.f _ z.f _ mode.l)

HELP_DESC("")
HELP_PARAM("")
HELP_PARAM("")
HELP_PARAM("")
HELP_PARAM("")
IMPORT_FUNCTION(uh3_SetNodeRotation, void , *node _ x.f _ y.f _ z.f )

HELP_DESC("")
HELP_PARAM("")
HELP_PARAM("")
HELP_PARAM("")
HELP_PARAM("")
HELP_PARAM("")
IMPORT_FUNCTION(uh3_NodeRotate, void , *node _ x.f _ y.f _ z.f _ mode.l )


; IDE Options = PureBasic 5.60 (Windows - x86)
; CursorPosition = 73
; FirstLine = 28
; EnableXP