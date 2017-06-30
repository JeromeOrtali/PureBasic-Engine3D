XIncludeFile "Config.pbi"

;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////
Enumeration ; Scene component
  #UH3_SCENECOMPONENT_DEBUGRENDERER
  #UH3_SCENECOMPONENT_OCTREE
  #UH3_SCENECOMPONENT_PHYSICWORLD
  #UH3_SCENECOMPONENT_PHYSICWORLD2D
EndEnumeration

;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////
Enumeration
  #UH3_SCENEFORMAT_JSON
  #UH3_SCENEFORMAT_XML
  #UH3_SCENEFORMAT_BINARY
EndEnumeration

;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////
Enumeration
  #UH3_NODEREPLICATED
  #UH3_NODELOCAL
EndEnumeration




;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////

IMPORT_FUNCTION(uh3_CreateScene, .i , void)
IMPORT_FUNCTION(uh3_FreeScene, .i , *scene)
IMPORT_FUNCTION(uh3_CreateSceneComponent, .i , *scene _ component.l)
IMPORT_FUNCTION(uh3_CreateNode, .i , *scene _ name.s _ createMode.l = #UH3_NODELOCAL)
IMPORT_FUNCTION(uh3_SaveScene, .i , *scene _ name.s _ format.l)
IMPORT_FUNCTION(uh3_LoadSceneFromFile, .i , *scene _ name.s _ format.l)
IMPORT_FUNCTION(uh3_LoadSceneFromResource, .i , *scene _ *resource _ format.l)
IMPORT_FUNCTION(uh3_UpdateScene, void , *scene _ timestep.f)




; IDE Options = PureBasic 5.60 (Windows - x86)
; CursorPosition = 29
; EnableXP