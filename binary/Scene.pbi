XIncludeFile "Config.pbi"

Enumeration
  #SceneComponent_debugRenderer  
  #SceneComponent_octree  
  #SceneComponent_physicWorld  
  #SceneComponent_physicWorld2D  
EndEnumeration

Enumeration
  #SceneFormat_JSON
  #SceneFormat_XML
  #SceneFormat_BINARY
EndEnumeration

	
IMPORT_FUNCTION(PB_CreateScene, .i , void)
IMPORT_FUNCTION(PB_FreeScene, .i , *scene)
IMPORT_FUNCTION(PB_CreateSceneComponent, .i , *scene _ component.l)
IMPORT_FUNCTION(PB_CreateNode, .i , *scene _ name.s)
IMPORT_FUNCTION(PB_SaveScene, .i , *scene _ name.s _ format.l)
IMPORT_FUNCTION(PB_LoadScene, .i , *scene _ name.s _ format.l)
IMPORT_FUNCTION(PB_LoadScene2, .i , *scene _ *resource _ format.l)
IMPORT_FUNCTION(PB_UpdateScene, void , *scene _ timestep.f)



; IDE Options = PureBasic 5.60 (Windows - x86)
; CursorPosition = 22
; EnableXP