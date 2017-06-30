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
#include "Material.hpp"

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
PB_FUNCTION(Urho3D::Material*) uh3_CreateMaterial() {
	return new Urho3D::Material(PB_ENGINE_CONTEXT);
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
PB_FUNCTION(void) uh3_SetMaterialTechnique(Urho3D::Material* material, unsigned int index,  Urho3D::Technique* technique, unsigned int quality, float lodDistance) {
	material->SetTechnique(index, technique, quality, lodDistance);
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
PB_FUNCTION(void) uh3_SetMaterialTexture(Urho3D::Material* material, Urho3D::Texture* texture, int textureUnit) {
	material->SetTexture((Urho3D::TextureUnit)textureUnit,texture);
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
PB_FUNCTION(void) uh3_SetMaterialUVTransform(Urho3D::Material* material, float offset_x, float offset_y, float rotation, float repeat_x, float repeat_y) {
	material->SetUVTransform(Urho3D::Vector2(offset_x, offset_y), rotation, Urho3D::Vector2(repeat_x, repeat_y));
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
PB_FUNCTION(int) uh3_SaveMaterial(Urho3D::Material* material, const unsigned short* name, MaterialFormat format) {
	Urho3D::File file(PB_ENGINE_CONTEXT, Urho3D::String((const wchar_t*)name), Urho3D::FILE_WRITE);
	switch (format){
	case MaterialFormat::XML:
		{
			Urho3D::XMLFile xmlfile(PB_ENGINE_CONTEXT);
			material->Save(xmlfile.GetRoot());
			return (int)xmlfile.Save(file);
		}
		break;
	case MaterialFormat::JSON:
		{
			Urho3D::JSONFile jsonfile(PB_ENGINE_CONTEXT);
			material->Save(jsonfile.GetRoot());
			return (int)jsonfile.Save(file);
		}
		break;
	}	
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
PB_FUNCTION(int) uh3_LoadMaterialFromFile(Urho3D::Material* material, const unsigned short* name, MaterialFormat format) {
	Urho3D::File file(PB_ENGINE_CONTEXT, Urho3D::String((const wchar_t*)name), Urho3D::FILE_READ);
	switch (format) {
	case MaterialFormat::XML:
		{
			Urho3D::XMLFile xmlfile(PB_ENGINE_CONTEXT);
			material->Load(xmlfile.GetRoot());
			return (int)xmlfile.Load(file);
		}
		break;
	case MaterialFormat::JSON:
	{
		Urho3D::JSONFile jsonfile(PB_ENGINE_CONTEXT);
		material->Load(jsonfile.GetRoot());
		return (int)jsonfile.Load(file);
	}
		break;
	}

	return 0;
}

PB_FUNCTION(void) uh3_SetMaterialShaderParameterInteger(Urho3D::Material* material, const unsigned short* name, int value) {
	material->SetShaderParameter(Urho3D::String((const wchar_t*)name) , value);
}

PB_FUNCTION(void) uh3_SetMaterialShaderParameterFloat(Urho3D::Material* material, const unsigned short* name, float value) {
	material->SetShaderParameter(Urho3D::String((const wchar_t*)name), value);
}

PB_FUNCTION(void) uh3_SetMaterialShaderParameterVector2(Urho3D::Material* material, const unsigned short* name, float x, float y) {
	material->SetShaderParameter(Urho3D::String((const wchar_t*)name), Urho3D::Vector2(x,y));
}

PB_FUNCTION(void) uh3_SetMaterialShaderParameterVector3(Urho3D::Material* material, const unsigned short* name, float x, float y, float z) {
	material->SetShaderParameter(Urho3D::String((const wchar_t*)name), Urho3D::Vector3(x, y, z));
}

PB_FUNCTION(void) uh3_SetMaterialShaderParameterVector4(Urho3D::Material* material, const unsigned short* name, float x, float y, float z, float w) {
	material->SetShaderParameter(Urho3D::String((const wchar_t*)name), Urho3D::Vector4(x, y, z, w));
}


PB_FUNCTION(void) uh3_GetMaterialShaderParameterInteger(Urho3D::Material* material, const unsigned short* name, int* value) {
	*value = material->GetShaderParameter(Urho3D::String((const wchar_t*)name)).GetInt();
}

PB_FUNCTION(void) uh3_GetMaterialShaderParameterFloat(Urho3D::Material* material, const unsigned short* name, float* value) {
	*value = material->GetShaderParameter(Urho3D::String((const wchar_t*)name)).GetFloat();
}

PB_FUNCTION(void) uh3_GetMaterialShaderParameterVector2(Urho3D::Material* material, const unsigned short* name, float* x, float* y) {
	Urho3D::Vector2 r = material->GetShaderParameter(Urho3D::String((const wchar_t*)name)).GetVector2();
	*x = r.x_;
	*y = r.y_;
}

PB_FUNCTION(void) uh3_GetMaterialShaderParameterVector3(Urho3D::Material* material, const unsigned short* name, float* x, float* y, float* z) {
	Urho3D::Vector3 r = material->GetShaderParameter(Urho3D::String((const wchar_t*)name)).GetVector3();
	*x = r.x_;
	*y = r.y_;
	*z = r.z_;
}

PB_FUNCTION(void) uh3_GetMaterialShaderParameterVector4(Urho3D::Material* material, const unsigned short* name, float* x, float* y, float* z, float* w) {
	Urho3D::Vector4 r = material->GetShaderParameter(Urho3D::String((const wchar_t*)name)).GetVector4();
	*x = r.x_;
	*y = r.y_;
	*z = r.z_;
	*w = r.w_;
}

PB_FUNCTION(void) uh3_SetMaterialCullMode(Urho3D::Material* material, int cullMode) {
	material->SetCullMode((Urho3D::CullMode)cullMode);
}

PB_FUNCTION(int) uh3_GetMaterialCullMode(Urho3D::Material* material) {
	return (int)material->GetCullMode();
}

PB_FUNCTION(void) uh3_SetMaterialShadowCullMode(Urho3D::Material* material, int cullMode) {
	material->SetShadowCullMode((Urho3D::CullMode)cullMode);
}

PB_FUNCTION(int) uh3_GetMaterialShadowCullMode(Urho3D::Material* material) {
	return (int)material->GetShadowCullMode();
}

PB_FUNCTION(void) uh3_SetMaterialFillMode(Urho3D::Material* material, int fillMode) {
	material->SetFillMode((Urho3D::FillMode)fillMode);
}

PB_FUNCTION(int) uh3_GetMaterialFillMode(Urho3D::Material* material) {
	return material->GetFillMode();
}

PB_FUNCTION(void) uh3_SetMaterialDepthBias(Urho3D::Material* material, float constantBias, float slopeScaledBias, float normalOffset) {
	material->SetDepthBias(Urho3D::BiasParameters(constantBias, slopeScaledBias, normalOffset));
}

PB_FUNCTION(void) uh3_GetMaterialDepthBias(Urho3D::Material* material, float* constantBias, float* slopeScaledBias, float* normalOffset) {
	Urho3D::BiasParameters param = material->GetDepthBias();
	*constantBias		= param.constantBias_;
	*slopeScaledBias	= param.slopeScaledBias_;
	*normalOffset		= param.normalOffset_;
}

PB_FUNCTION(void) uh3_SetMaterialRenderOrder(Urho3D::Material* material, unsigned char order) {
	material->SetRenderOrder(order);
}

PB_FUNCTION(unsigned char) uh3_GetMaterialRenderOrder(Urho3D::Material* material) {
	return material->GetRenderOrder();
}

PB_FUNCTION(unsigned int) uh3_GetMaterialTechniqueNumber(Urho3D::Material* material) {
	return material->GetNumTechniques();
}

PB_FUNCTION(Urho3D::Technique*) uh3_GetMaterialTechnique(Urho3D::Material* material, unsigned int index) {
	return material->GetTechnique(index);
}