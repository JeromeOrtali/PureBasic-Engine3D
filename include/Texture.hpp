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
#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Graphics/Renderer.h>
#include <Urho3D/Graphics/Graphics.h>
#include <Urho3D/Graphics/Texture.h>
#include <Urho3D/Graphics/Texture2D.h>
#include <Urho3D/Graphics/Texture3D.h>
#include <Urho3D/Graphics/Texture2DArray.h>
#include <Urho3D/Graphics/TextureCube.h>

extern Urho3D::Context*	PB_ENGINE_CONTEXT;

#ifndef PB_FUNCTION
	#define PB_FUNCTION(T) __declspec(dllexport) T
#endif 

enum Format {
	RGB,
	RGBA
};

extern "C" {


	PB_FUNCTION(Urho3D::Texture2D*) uh3_CreateTexture2D(int width, int height, int format, unsigned int level, int usage);

	PB_FUNCTION(void) uh3_FreeTexture2D(Urho3D::Texture2D* texture);

	PB_FUNCTION(int) uh3_SetTexture2DData(Urho3D::Texture2D* texture, int x, int y, int width, int height, unsigned int level, void* data);

	PB_FUNCTION(void) uh3_GetTexture2DData(Urho3D::Texture2D* texture, unsigned int level, void *dest);

	PB_FUNCTION(Urho3D::RenderSurface*) uh3_GetTexture2DRenderSurface(Urho3D::Texture2D* texture);

	PB_FUNCTION(void) uh3_SetTextureName(Urho3D::Texture* texture, const unsigned short* name);

	PB_FUNCTION(void) uh3_SetTextureFilterMode(Urho3D::Texture* texture, int mode);

	PB_FUNCTION(void) uh3_SetRenderSurfaceViewport(Urho3D::RenderSurface* surface, int index, Urho3D::Viewport* viewport);



}


#endif // !TEXTURE_HPP
