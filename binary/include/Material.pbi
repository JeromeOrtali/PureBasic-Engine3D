XIncludeFile "Config.pbi"

;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////

Enumeration
  #UH3_TU_DIFFUSE = 0
  #UH3_TU_ALBEDOBUFFER = 0
  #UH3_TU_NORMAL = 1
  #UH3_TU_NORMALBUFFER = 1
  #UH3_TU_SPECULAR = 2
  #UH3_TU_EMISSIVE = 3
  #UH3_TU_ENVIRONMENT = 4
  #UH3_TU_VOLUMEMAP = 5
  #UH3_TU_CUSTOM1 = 6
  #UH3_TU_CUSTOM2 = 7
  #UH3_TU_LIGHTRAMP = 8
  #UH3_TU_LIGHTSHAPE = 9
  #UH3_TU_SHADOWMAP = 10
  #UH3_TU_FACESELECT = 11
  #UH3_TU_INDIRECTION = 12
  #UH3_TU_DEPTHBUFFER = 13
  #UH3_TU_LIGHTBUFFER = 14
  #UH3_TU_ZONE = 15
  #UH3_MAX_MATERIAL_TEXTURE_UNITS = 8
  #UH3_MAX_TEXTURE_UNITS = 16
EndEnumeration


IMPORT_FUNCTION(uh3_CreateMaterial,.i,void)
IMPORT_FUNCTION(uh3_SetMaterialTechnique,void, *material _ index.l _ *technique _ quality.l = 0 _ lodDistance.f = 0.0)
IMPORT_FUNCTION(uh3_SetMaterialTexture,void, *material _ *texture _ textureUnit.l)
IMPORT_FUNCTION(uh3_SetMaterialUVTransform,void, *material _ offset_x.f _ offset_y.f _ rotation.f _ repeat_x.f _ repeat_y.f)

; IDE Options = PureBasic 5.60 (Windows - x86)
; CursorPosition = 33
; EnableXP