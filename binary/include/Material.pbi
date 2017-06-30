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

Enumeration
  #UH3_MATERIAL_XML  
  #UH3_MATERIAL_JSON  
EndEnumeration

Enumeration ; cull mode
  #UH3_CULL_NONE
  #UH3_CULL_CCW
  #UH3_CULL_CW
EndEnumeration

Enumeration
  #UH3_FILL_SOLID
  #UH3_FILL_WIREFRAME
  #UH3_FILL_POINT
EndEnumeration

IMPORT_FUNCTION(uh3_CreateMaterial,.i,void)
IMPORT_FUNCTION(uh3_SetMaterialTechnique,void, *material _ index.l _ *technique _ quality.l = 0 _ lodDistance.f = 0.0)
IMPORT_FUNCTION(uh3_SetMaterialTexture,void, *material _ *texture _ textureUnit.l)
IMPORT_FUNCTION(uh3_SetMaterialUVTransform,void, *material _ offset_x.f _ offset_y.f _ rotation.f _ repeat_x.f _ repeat_y.f)
IMPORT_FUNCTION(uh3_SaveMaterial,.l  ,*material _  name.s _  format.l)
IMPORT_FUNCTION(uh3_LoadMaterialFromFile,.l  ,*material _  name.s _  format.l)
IMPORT_FUNCTION(uh3_SetMaterialShaderParameterInteger,void,*material _  name.s _  value.l)
IMPORT_FUNCTION(uh3_SetMaterialShaderParameterFloat,void,*material _  name.s _  value.f)
IMPORT_FUNCTION(uh3_SetMaterialShaderParameterVector2,void,*material _  name.s _  x.f _  y.f)
IMPORT_FUNCTION(uh3_SetMaterialShaderParameterVector3,void,*material _  name.s _  x.f _  y.f _  z.f)
IMPORT_FUNCTION(uh3_SetMaterialShaderParameterVector4,void,*material _  name.s _  x.f _  y.f _  z.f _  w.f)
IMPORT_FUNCTION(uh3_GetMaterialShaderParameterInteger,void,*material _  name.s _  *value)
IMPORT_FUNCTION(uh3_GetMaterialShaderParameterFloat,void,*material _  name.s _  *value)
IMPORT_FUNCTION(uh3_GetMaterialShaderParameterVector2,void,*material _  name.s _  *x _  *y)
IMPORT_FUNCTION(uh3_GetMaterialShaderParameterVector3,void,*material _  name.s _  *x _  *y _  *z)
IMPORT_FUNCTION(uh3_GetMaterialShaderParameterVector4,void,*material _  name.s _  *x _  *y _  *z _  *w)
IMPORT_FUNCTION(uh3_SetMaterialCullMode,void,*material _ cullMode.l)
IMPORT_FUNCTION(uh3_GetMaterialCullMode,.l,*material)
IMPORT_FUNCTION(uh3_SetMaterialShadowCullMode,void,*material _  cullMode.l)
IMPORT_FUNCTION(uh3_GetMaterialShadowCullMode,.l,*material)
IMPORT_FUNCTION(uh3_SetMaterialFillMode,void,*material _  fillMode.l)
IMPORT_FUNCTION(uh3_GetMaterialFillMode,.l,*material)
IMPORT_FUNCTION(uh3_SetMaterialDepthBias,void,*material _ constantBias.f _ slopeScaledBias.f _ normalOffset.f)
IMPORT_FUNCTION(uh3_GetMaterialDepthBias,void,*material _ *constantBias _  *slopeScaledBias _  *normalOffset)
IMPORT_FUNCTION(uh3_SetMaterialRenderOrder,void,*material _  order.a)
IMPORT_FUNCTION(uh3_GetMaterialRenderOrder,.a,*material)
IMPORT_FUNCTION(uh3_GetMaterialTechniqueNumber,.l,*material)
IMPORT_FUNCTION(uh3_GetMaterialTechnique,.i,*material _  index.l)
; IDE Options = PureBasic 5.60 (Windows - x86)
; CursorPosition = 62
; FirstLine = 25
; EnableXP