XIncludeFile "Config.pbi"

;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////
Enumeration ; LightType
  #UH3_DIRECTIONAL
  #UH3_SPOT
  #UH3_POINT
EndEnumeration

;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////

IMPORT_FUNCTION(uh3_GetLight,.i,*node _ recursive = #False)
IMPORT_FUNCTION(uh3_SetLightType,void,*light _ type.l)
IMPORT_FUNCTION(uh3_SetLightCastShadow,void,*light _ enable.b)
IMPORT_FUNCTION(uh3_SetLightPerVertex,void,*light _ enable.b)
IMPORT_FUNCTION(uh3_SetLightColor,void,*light _ color.l)
IMPORT_FUNCTION(uh3_SetLightSpecularIntensity,void,*light _ specular.f)
IMPORT_FUNCTION(uh3_SetLightRange,void,*light _  range.f)
IMPORT_FUNCTION(uh3_SetLightFov,void,*light _  fov.f)
IMPORT_FUNCTION(uh3_SetLightAspectRatio,void,*light _  aspectRatio.f)
IMPORT_FUNCTION(uh3_SetLightFadeDistance,void,*light _  distance.f)
IMPORT_FUNCTION(uh3_SetLightShadowFadeDistance,void,*light _  distance.f)
IMPORT_FUNCTION(uh3_SetLightShadowBias,void, *light _ constantBias.f _  slopeScaledBias.f)
IMPORT_FUNCTION(uh3_SetLightShadowCascade,void,*light _ split1.f _ split2.f _ split3.f _ split4.f _ fadeStart.f _ biasAutoAdjust.f)
IMPORT_FUNCTION(uh3_SetLightShadowIntensity,void,*light _ intensity.f )
IMPORT_FUNCTION(uh3_SetLightShadowResolution,void,*light _ resolution.f)
IMPORT_FUNCTION(uh3_SetLightShadowNearFarRatio,void,*light _ nearFarRatio.f)
IMPORT_FUNCTION(uh3_SetLightRampTexture,void,*light _ *texture)
IMPORT_FUNCTION(uh3_SetLightShapeTexture,void,*light _ *texture)
IMPORT_FUNCTION(uh3_SetLightShadowFocus,void, *light _ focus.l _ nonUniform.l _ autoSize.l _ quantize.f _ minView.f)
; IDE Options = PureBasic 5.60 (Windows - x86)
; CursorPosition = 33
; EnableXP