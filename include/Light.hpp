#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <Urho3D/Engine/Engine.h>
#include <Urho3D/Graphics/Graphics.h>
#include <Urho3D/Graphics/Camera.h>
#include <Urho3D/Graphics/Geometry.h>
#include <Urho3D/Graphics/Renderer.h>
#include <Urho3D/Graphics/DebugRenderer.h>
#include <Urho3D/Graphics/Octree.h>
#include <Urho3D/Graphics/Light.h>
#include <Urho3D/Graphics/Model.h>
#include <Urho3D/Graphics/StaticModel.h>
#include <Urho3D/Graphics/Material.h>
#include <Urho3D/Graphics/Skybox.h>


#ifndef PB_FUNCTION
	#define PB_FUNCTION(T) __declspec(dllexport) T
#endif 

enum LightType : int {
	LightDirectional,
	LightSpot,
	LightPoint
};


extern "C" {

	PB_FUNCTION(Urho3D::Light*) uh3_getLight(Urho3D::Node* node, int recursive);

	PB_FUNCTION(void) uh3_setLightType(Urho3D::Light* light, LightType type);

	PB_FUNCTION(void) uh3_setLightPerVertex(Urho3D::Light* light, int enable);

	PB_FUNCTION(void) uh3_setLightColor(Urho3D::Light* light, unsigned int color);

	PB_FUNCTION(void) uh3_setLightSpecularIntensity(Urho3D::Light* light, float specular);

	PB_FUNCTION(void) uh3_setLightRange(Urho3D::Light* light, float range);

	PB_FUNCTION(void) uh3_setLightFov(Urho3D::Light* light, float fov);

	PB_FUNCTION(void) uh3_setLightAspectRatio(Urho3D::Light* light, float aspectRatio);

	PB_FUNCTION(void) uh3_setLightFadeDistance(Urho3D::Light* light, float distance);

	PB_FUNCTION(void) uh3_setLightShadowFadeDistance(Urho3D::Light* light, float distance);

	PB_FUNCTION(void) uh3_setLightShadowBias(Urho3D::Light* light, float constantBias, float slopeScaledBias);

	PB_FUNCTION(void) uh3_setLightShadowCascade(Urho3D::Light* light, float split1, float split2, float split3, float split4, float fadeStart, float biasAutoAdjust);

	PB_FUNCTION(void) uh3_setLightShadowIntensity(Urho3D::Light* light, float intensity);

	PB_FUNCTION(void) uh3_setLightShadowResolution(Urho3D::Light* light, float resolution);

	PB_FUNCTION(void) uh3_setLightShadowNearFarRatio(Urho3D::Light* light, float nearFarRatio);

	PB_FUNCTION(void) uh3_setLightRampTexture(Urho3D::Light* light, Urho3D::Texture* texture);

	PB_FUNCTION(void) uh3_setLightShapeTexture(Urho3D::Light* light, Urho3D::Texture* texture);

}

#endif // !LIGHT_HPP
