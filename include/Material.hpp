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
#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <Urho3D/Graphics/Graphics.h>
#include <Urho3D/Graphics/Material.h>
#include <Urho3D/IO/Serializer.h>
#include <Urho3D/IO/File.h>
#include <Urho3D/Resource/XMLFile.h>
#include <Urho3D/Resource/JSONFile.h>

extern Urho3D::Context*	PB_ENGINE_CONTEXT;

enum MaterialFormat : int {
	XML,
	JSON
};

#ifndef PB_FUNCTION
	#define PB_FUNCTION(T) __declspec(dllexport) T
#endif 

extern "C" {

	PB_FUNCTION(Urho3D::Material*) uh3_CreateMaterial();
	PB_FUNCTION(void) uh3_SetMaterialTechnique(Urho3D::Material* material, unsigned int index, Urho3D::Technique* technique, unsigned int quality, float lodDistance);
	PB_FUNCTION(void) uh3_SetMaterialTexture(Urho3D::Material* material, Urho3D::Texture* texture, int textureUnit);
	PB_FUNCTION(void) uh3_SetMaterialUVTransform(Urho3D::Material* material, float offset_x, float offset_y, float rotation, float repeat_x, float repeat_y);
	PB_FUNCTION(int) uh3_SaveMaterial(Urho3D::Material* material, const unsigned short* name, MaterialFormat format);
	PB_FUNCTION(int) uh3_LoadMaterialFromFile(Urho3D::Material* material, const unsigned short* name, MaterialFormat format);
	PB_FUNCTION(void) uh3_SetMaterialShaderParameterInteger(Urho3D::Material* material, const unsigned short* name, int value);
	PB_FUNCTION(void) uh3_SetMaterialShaderParameterFloat(Urho3D::Material* material, const unsigned short* name, float value);
	PB_FUNCTION(void) uh3_SetMaterialShaderParameterVector2(Urho3D::Material* material, const unsigned short* name, float x, float y);
	PB_FUNCTION(void) uh3_SetMaterialShaderParameterVector3(Urho3D::Material* material, const unsigned short* name, float x, float y, float z);
	PB_FUNCTION(void) uh3_SetMaterialShaderParameterVector4(Urho3D::Material* material, const unsigned short* name, float x, float y, float z, float w);
	PB_FUNCTION(void) uh3_GetMaterialShaderParameterInteger(Urho3D::Material* material, const unsigned short* name, int* value);
	PB_FUNCTION(void) uh3_GetMaterialShaderParameterFloat(Urho3D::Material* material, const unsigned short* name, float* value);
	PB_FUNCTION(void) uh3_GetMaterialShaderParameterVector2(Urho3D::Material* material, const unsigned short* name, float* x, float* y);
	PB_FUNCTION(void) uh3_GetMaterialShaderParameterVector3(Urho3D::Material* material, const unsigned short* name, float* x, float* y, float* z);
	PB_FUNCTION(void) uh3_GetMaterialShaderParameterVector4(Urho3D::Material* material, const unsigned short* name, float* x, float* y, float* z, float* w);
	PB_FUNCTION(void) uh3_SetMaterialCullMode(Urho3D::Material* material, int cullMode);
	PB_FUNCTION(int) uh3_GetMaterialCullMode(Urho3D::Material* material);
	PB_FUNCTION(void) uh3_SetMaterialShadowCullMode(Urho3D::Material* material, int cullMode);
	PB_FUNCTION(int) uh3_GetMaterialShadowCullMode(Urho3D::Material* material);
	PB_FUNCTION(void) uh3_SetMaterialFillMode(Urho3D::Material* material, int fillMode);
	PB_FUNCTION(int) uh3_GetMaterialFillMode(Urho3D::Material* material);
	PB_FUNCTION(void) uh3_SetMaterialDepthBias(Urho3D::Material* material, float constantBias, float slopeScaledBias, float normalOffset);
	PB_FUNCTION(void) uh3_GetMaterialDepthBias(Urho3D::Material* material, float* constantBias, float* slopeScaledBias, float* normalOffset);
	PB_FUNCTION(void) uh3_SetMaterialRenderOrder(Urho3D::Material* material, unsigned char order);
	PB_FUNCTION(unsigned char) uh3_GetMaterialRenderOrder(Urho3D::Material* material);
	PB_FUNCTION(unsigned int) uh3_GetMaterialTechniqueNumber(Urho3D::Material* material);
	PB_FUNCTION(Urho3D::Technique*) uh3_GetMaterialTechnique(Urho3D::Material* material, unsigned int index);

}

#endif // !MATERIAL_HPP