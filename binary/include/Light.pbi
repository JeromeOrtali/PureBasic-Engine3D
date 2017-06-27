XIncludeFile "Config.pbi"

;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////
Enumeration
  #LightDirectional
	#LightSpot
	#LightPoint
EndEnumeration

;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////

IMPORT_FUNCTION(uh3_getLight,.i,*node _ recursive = #False)
IMPORT_FUNCTION(uh3_setLightType,void,*light _ type.l)
IMPORT_FUNCTION(uh3_setLightPerVertex,void,*light _ enable.b)
IMPORT_FUNCTION(uh3_setLightColor,void,*light _ red.a _ green.a _ blue.a)
IMPORT_FUNCTION(uh3_setLightSpecularIntensity,void,*light _ specular.f)
IMPORT_FUNCTION(uh3_setLightRange,void,*light _  range.f)
IMPORT_FUNCTION(uh3_setLightFov,void,*light _  fov.f)
IMPORT_FUNCTION(uh3_setLightAspectRatio,void,*light _  aspectRatio.f)
IMPORT_FUNCTION(uh3_setLightFadeDistance,void,*light _  distance.f)
IMPORT_FUNCTION(uh3_setLightShadowFadeDistance,void,*light _  distance.f)
IMPORT_FUNCTION(uh3_setLightShadowBias,void, constantBias.f _  slopeScaledBias.f)
IMPORT_FUNCTION(uh3_setLightShadowCascade,void,*light _ split1.f _ split2.f _ split3.f _ split4.f _ fadeStart.f _ biasAutoAdjust.f)
IMPORT_FUNCTION(uh3_setLightShadowIntensity,void,*light _ intensity.f )
IMPORT_FUNCTION(uh3_setLightShadowResolution,void,*light _ resolution.f)
IMPORT_FUNCTION(uh3_setLightShadowNearFarRatio,void,*light _ nearFarRatio.f)
IMPORT_FUNCTION(uh3_setLightRampTexture,void,*light _ *texture)
IMPORT_FUNCTION(uh3_setLightShapeTexture,void,*light _ *texture)

; IDE Options = PureBasic 5.60 (Windows - x86)
; CursorPosition = 21
; EnableXP