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

extern Urho3D::Context*	PB_ENGINE_CONTEXT;

#ifndef PB_FUNCTION
	#define PB_FUNCTION(T) __declspec(dllexport) T
#endif 

extern "C" {

	PB_FUNCTION(Urho3D::Material*) uh3_CreateMaterial();

	PB_FUNCTION(void) uh3_SetMaterialTechnique(Urho3D::Material* material, unsigned int index, Urho3D::Technique* technique, unsigned int quality, float lodDistance);

	PB_FUNCTION(void) uh3_SetMaterialTexture(Urho3D::Material* material, Urho3D::Texture* texture, int textureUnit);

	PB_FUNCTION(void) uh3_SetMaterialUVTransform(Urho3D::Material* material, float offset_x, float offset_y, float rotation, float repeat_x, float repeat_y);
}

#endif // !MATERIAL_HPP
