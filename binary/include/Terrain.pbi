XIncludeFile "Config.pbi"

;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////

Enumeration
  #UH3_TERRAIN_NEIGHBO_NORTH
  #UH3_TERRAIN_NEIGHBO_SOUTH
  #UH3_TERRAIN_NEIGHBO_WEST
  #UH3_TERRAIN_NEIGHBO_EAST
EndEnumeration




;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////
IMPORT_FUNCTION(uh3_SetTerrainPatchSize,void,  *terrain _ size.l)
IMPORT_FUNCTION(uh3_GetTerrainPatchSize, .i, *terrain)
IMPORT_FUNCTION(uh3_SetTerrainSpacing,void, *terrain _ x.f _ y.f _ z.f)
IMPORT_FUNCTION(uh3_GetTerrainSpacing,void, *terrain _ *x _ *y _ *z)
IMPORT_FUNCTION(uh3_SetMaxLodLevel,void, *terrain _ levels.i)
IMPORT_FUNCTION(uh3_GetMaxLodLevel,.l, *terrain)
IMPORT_FUNCTION(uh3_SetTerrainSmoothing, void, *terrain _ enable.i)
IMPORT_FUNCTION(uh3_GetTerrainSmoothing, .i, *terrain)
IMPORT_FUNCTION(uh3_SetTerrainHeightMap, .i, *terrain _ *image)
IMPORT_FUNCTION(uh3_SetTerrainApplyHeightMap,void, *terrain)
IMPORT_FUNCTION(uh3_SetTerrainMaterial,void, *terrain _ *material)
IMPORT_FUNCTION(uh3_GetTerrainMaterial,.i, *terrain)
IMPORT_FUNCTION(uh3_SetTerrainNeighbor,void, *terrain _ *neighborTerrain _ neighborLocation.l)
IMPORT_FUNCTION(uh3_GetTerrainHeight, .f , *terrain _ x.f _ y.f _ z.f)
IMPORT_FUNCTION(uh3_GetTerrainNormal,void, *terrain _ x.f _ y.f _ z.f _ *nx _ *ny _  *nz)
IMPORT_FUNCTION(uh3_SetTerrainOccluder,void, *terrain _ state.l)
IMPORT_FUNCTION(uh3_GetTerrainOccluder,.l, *terrain)
IMPORT_FUNCTION(uh3_SetTerrainCastShadow,void, *terrain _ state.l)
IMPORT_FUNCTION(uh3_GetTerrainCastShadow,.l, *terrain)
IMPORT_FUNCTION(uh3_GetTerrainWorldToHeightmap,void, *terrain _ x.f _ y.f _ z.f _ *px _ *py) 
IMPORT_FUNCTION(uh3_SetTerrainLodBias,void, *terrain _ bias.f) 

; IDE Options = PureBasic 5.60 (Windows - x86)
; CursorPosition = 40
; EnableXP