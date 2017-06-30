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
#include "Light.hpp"


PB_FUNCTION(Urho3D::Light*) uh3_GetLight(Urho3D::Node* node, int recursive) {
	return node->GetComponent < Urho3D::Light>((bool)recursive);
}

PB_FUNCTION(void) uh3_SetLightType(Urho3D::Light* light, LightType type) {
	light->SetLightType(Urho3D::LightType(type));
}

PB_FUNCTION(void) uh3_SetLightCastShadow(Urho3D::Light* light, int enable) {
	light->SetCastShadows((bool)enable);
}

PB_FUNCTION(void) uh3_SetLightPerVertex(Urho3D::Light* light, int enable) {
	light->SetPerVertex((bool)enable);
}

PB_FUNCTION(void) uh3_SetLightColor(Urho3D::Light* light, unsigned int color) {
	float r = ((color & 0xFF)) / 255.0f;
	float g = ((color >> 8) & 0xFF) / 255.0f;
	float b = ((color >> 16) & 0xFF) / 255.0f;
	light->SetColor(Urho3D::Color(r,g,b));

	

}

PB_FUNCTION(void) uh3_SetLightSpecularIntensity(Urho3D::Light* light, float specular) {
	light->SetSpecularIntensity(specular);
}

PB_FUNCTION(void) uh3_SetLightRange(Urho3D::Light* light, float range) {
	light->SetRange(range);
}

PB_FUNCTION(void) uh3_SetLightFov(Urho3D::Light* light, float fov) {
	light->SetFov(fov);
}

PB_FUNCTION(void) uh3_SetLightAspectRatio(Urho3D::Light* light, float aspectRatio) {
	light->SetAspectRatio(aspectRatio);
}

PB_FUNCTION(void) uh3_SetLightFadeDistance(Urho3D::Light* light, float distance) {
	light->SetFadeDistance(distance);
}

PB_FUNCTION(void) uh3_SetLightShadowFadeDistance(Urho3D::Light* light, float distance) {
	light->SetShadowFadeDistance(distance);
}

PB_FUNCTION(void) uh3_SetLightShadowBias(Urho3D::Light* light, float constantBias, float slopeScaledBias) {
	light->SetShadowBias(Urho3D::BiasParameters(constantBias, slopeScaledBias));
}

PB_FUNCTION(void) uh3_SetLightShadowCascade(Urho3D::Light* light, float split1, float split2, float split3, float split4, float fadeStart, float biasAutoAdjust) {
	light->SetShadowCascade(Urho3D::CascadeParameters(split1, split2, split3, split4, fadeStart, biasAutoAdjust));
}

PB_FUNCTION(void) uh3_SetLightShadowIntensity(Urho3D::Light* light, float intensity) {
	light->SetShadowIntensity(intensity);
}

PB_FUNCTION(void) uh3_SetLightShadowResolution(Urho3D::Light* light, float resolution) {
	light->SetShadowResolution(resolution);
}

PB_FUNCTION(void) uh3_SetLightShadowNearFarRatio(Urho3D::Light* light, float nearFarRatio) {
	light->SetShadowNearFarRatio(nearFarRatio);
}

PB_FUNCTION(void) uh3_SetLightRampTexture(Urho3D::Light* light, Urho3D::Texture* texture) {
	light->SetRampTexture(texture);
}

PB_FUNCTION(void) uh3_SetLightShapeTexture(Urho3D::Light* light, Urho3D::Texture* texture) {
	light->SetShapeTexture(texture);
}

PB_FUNCTION(void) uh3_SetLightShadowFocus(Urho3D::Light* light, int focus, int nonUniform, int autoSize, float quantize, float minView) {
	light->SetShadowFocus(Urho3D::FocusParameters((bool)focus, (bool)nonUniform, (bool)autoSize, quantize, minView));
}