#include "Light.hpp"


PB_FUNCTION(Urho3D::Light*) uh3_getLight(Urho3D::Node* node, int recursive) {
	return node->GetComponent < Urho3D::Light>((bool)recursive);
}

PB_FUNCTION(void) uh3_setLightType(Urho3D::Light* light, LightType type) {
	light->SetLightType(Urho3D::LightType(type));
}

PB_FUNCTION(void) uh3_setLightPerVertex(Urho3D::Light* light, int enable) {
	light->SetPerVertex((bool)enable);
}

PB_FUNCTION(void) uh3_setLightColor(Urho3D::Light* light, unsigned int color) {
	float r = ((color & 0xFF)) / 255.0f;
	float g = ((color >> 8) & 0xFF) / 255.0f;
	float b = ((color >> 16) & 0xFF) / 255.0f;
	light->SetColor(Urho3D::Color(r,g,b));
}

PB_FUNCTION(void) uh3_setLightSpecularIntensity(Urho3D::Light* light, float specular) {
	light->SetSpecularIntensity(specular);
}

PB_FUNCTION(void) uh3_setLightRange(Urho3D::Light* light, float range) {
	light->SetRange(range);
}

PB_FUNCTION(void) uh3_setLightFov(Urho3D::Light* light, float fov) {
	light->SetFov(fov);
}

PB_FUNCTION(void) uh3_setLightAspectRatio(Urho3D::Light* light, float aspectRatio) {
	light->SetAspectRatio(aspectRatio);
}

PB_FUNCTION(void) uh3_setLightFadeDistance(Urho3D::Light* light, float distance) {
	light->SetFadeDistance(distance);
}

PB_FUNCTION(void) uh3_setLightShadowFadeDistance(Urho3D::Light* light, float distance) {
	light->SetShadowFadeDistance(distance);
}

PB_FUNCTION(void) uh3_setLightShadowBias(Urho3D::Light* light, float constantBias, float slopeScaledBias) {
	light->SetShadowBias(Urho3D::BiasParameters(constantBias, slopeScaledBias));
}

PB_FUNCTION(void) uh3_setLightShadowCascade(Urho3D::Light* light, float split1, float split2, float split3, float split4, float fadeStart, float biasAutoAdjust) {
	light->SetShadowCascade(Urho3D::CascadeParameters(split1, split2, split3, split4, fadeStart, biasAutoAdjust));
}

PB_FUNCTION(void) uh3_setLightShadowIntensity(Urho3D::Light* light, float intensity) {
	light->SetShadowIntensity(intensity);
}

PB_FUNCTION(void) uh3_setLightShadowResolution(Urho3D::Light* light, float resolution) {
	light->SetShadowResolution(resolution);
}

PB_FUNCTION(void) uh3_setLightShadowNearFarRatio(Urho3D::Light* light, float nearFarRatio) {
	light->SetShadowNearFarRatio(nearFarRatio);
}

PB_FUNCTION(void) uh3_setLightRampTexture(Urho3D::Light* light, Urho3D::Texture* texture) {
	light->SetRampTexture(texture);
}

PB_FUNCTION(void) uh3_setLightShapeTexture(Urho3D::Light* light, Urho3D::Texture* texture) {
	light->SetShapeTexture(texture);
}