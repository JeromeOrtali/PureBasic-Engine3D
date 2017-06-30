XIncludeFile "Config.pbi"

;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////
IMPORT_FUNCTION(uh3_SetStaticModel, void , *node _ *model)
IMPORT_FUNCTION(uh3_SetStaticModelMaterial, void , *model _ *material)
IMPORT_FUNCTION(uh3_SetStaticModelCastShadow, void , *model _ enable.l)
IMPORT_FUNCTION(uh3_GetStaticModelCastShadow, .l , *model)



; IDE Options = PureBasic 5.60 (Windows - x86)
; CursorPosition = 7
; EnableXP