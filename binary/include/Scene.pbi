XIncludeFile "Config.pbi"
;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////
Enumeration
  #SceneComponent_debugRenderer  
  #SceneComponent_octree  
  #SceneComponent_physicWorld  
  #SceneComponent_physicWorld2D  
EndEnumeration

;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////
Enumeration
  #SceneFormat_JSON
  #SceneFormat_XML
  #SceneFormat_BINARY
EndEnumeration


;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////
HELP_DESC("")
IMPORT_FUNCTION(uh3_CreateScene, .i , void)

HELP_DESC("")
HELP_PARAM("")
IMPORT_FUNCTION(uh3_FreeScene, .i , *scene)


HELP_DESC("")
HELP_PARAM("")
HELP_PARAM("")
IMPORT_FUNCTION(uh3_CreateSceneComponent, .i , *scene _ component.l)

HELP_DESC("")
HELP_PARAM("")
HELP_PARAM("")
IMPORT_FUNCTION(uh3_CreateNode, .i , *scene _ name.s)

HELP_DESC("")
HELP_PARAM("")
HELP_PARAM("")
HELP_PARAM("")
IMPORT_FUNCTION(uh3_SaveScene, .i , *scene _ name.s _ format.l)

HELP_DESC("")
HELP_PARAM("")
HELP_PARAM("")
HELP_PARAM("")
IMPORT_FUNCTION(uh3_LoadScene, .i , *scene _ name.s _ format.l)

HELP_DESC("")
HELP_PARAM("")
HELP_PARAM("")
HELP_PARAM("")
IMPORT_FUNCTION(uh3_LoadScene2, .i , *scene _ *resource _ format.l)

HELP_DESC("")
HELP_PARAM("")
HELP_PARAM("")
IMPORT_FUNCTION(uh3_UpdateScene, void , *scene _ timestep.f)




; IDE Options = PureBasic 5.60 (Windows - x86)
; CursorPosition = 62
; FirstLine = 19
; EnableXP