/*	PureBasic Engine3D licence
*	--------------------------
*
*	MIT License
*
*	Copyright (c) 2017 Jerome Ortali
*
*	Permission is hereby granted, free of charge, to any person obtaining a copy
*	of this software and associated documentation files (the "Software"), to deal
*	in the Software without restriction, including without limitation the rights
*	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*	copies of the Software, and to permit persons to whom the Software is
*	furnished to do so, subject to the following conditions:
*
*	The above copyright notice and this permission notice shall be included in all
*	copies or substantial portions of the Software.
*
*	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
*	SOFTWARE.
*/
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

	PB_FUNCTION(Urho3D::Light*) uh3_GetLight(Urho3D::Node* node, int recursive);

	PB_FUNCTION(void) uh3_SetLightType(Urho3D::Light* light, LightType type);

	PB_FUNCTION(void) uh3_SetLightCastShadow(Urho3D::Light* light, int enable);

	PB_FUNCTION(void) uh3_SetLightPerVertex(Urho3D::Light* light, int enable);

	PB_FUNCTION(void) uh3_SetLightColor(Urho3D::Light* light, unsigned int color);

	PB_FUNCTION(void) uh3_SetLightSpecularIntensity(Urho3D::Light* light, float specular);

	PB_FUNCTION(void) uh3_SetLightRange(Urho3D::Light* light, float range);

	PB_FUNCTION(void) uh3_SetLightFov(Urho3D::Light* light, float fov);

	PB_FUNCTION(void) uh3_SetLightAspectRatio(Urho3D::Light* light, float aspectRatio);

	PB_FUNCTION(void) uh3_SetLightFadeDistance(Urho3D::Light* light, float distance);

	PB_FUNCTION(void) uh3_SetLightShadowFadeDistance(Urho3D::Light* light, float distance);

	PB_FUNCTION(void) uh3_SetLightShadowBias(Urho3D::Light* light, float constantBias, float slopeScaledBias);

	PB_FUNCTION(void) uh3_SetLightShadowCascade(Urho3D::Light* light, float split1, float split2, float split3, float split4, float fadeStart, float biasAutoAdjust);

	PB_FUNCTION(void) uh3_SetLightShadowIntensity(Urho3D::Light* light, float intensity);

	PB_FUNCTION(void) uh3_SetLightShadowResolution(Urho3D::Light* light, float resolution);

	PB_FUNCTION(void) uh3_SetLightShadowNearFarRatio(Urho3D::Light* light, float nearFarRatio);

	PB_FUNCTION(void) uh3_SetLightRampTexture(Urho3D::Light* light, Urho3D::Texture* texture);

	PB_FUNCTION(void) uh3_SetLightShapeTexture(Urho3D::Light* light, Urho3D::Texture* texture);

}

#endif // !LIGHT_HPP
