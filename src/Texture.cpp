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
#include "Texture.hpp"

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
PB_FUNCTION(Urho3D::Texture2D*) uh3_CreateTexture2D(int width, int height, int format, unsigned int levels, int usage) {
	Urho3D::Texture2D* texture = new Urho3D::Texture2D(PB_ENGINE_CONTEXT);
	texture->SetNumLevels(levels);

	switch ((Format)format)
	{
	case RGB:
		texture->SetSize(width, height, Urho3D::Graphics::GetRGBFormat(), (Urho3D::TextureUsage)usage);
		break;
	case RGBA:
		texture->SetSize(width, height, Urho3D::Graphics::GetRGBAFormat(), (Urho3D::TextureUsage)usage);
		break;
	default:
		break;
	}
	


	return texture;
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
PB_FUNCTION(void) uh3_FreeTexture2D(Urho3D::Texture2D* texture) {
	delete texture;
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
PB_FUNCTION(int) uh3_SetTexture2DData(Urho3D::Texture2D* texture, int x, int y, int width, int height, unsigned int level, void* data) {
	return (int)texture->SetData(level, x, y, width, height, data);
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
PB_FUNCTION(void) uh3_GetTexture2DData(Urho3D::Texture2D* texture, unsigned int level, void *dest) {
	texture->GetData(level, dest);
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
PB_FUNCTION(Urho3D::RenderSurface*) uh3_GetTexture2DRenderSurface(Urho3D::Texture2D* texture) {
	return texture->GetRenderSurface();
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
PB_FUNCTION(void) uh3_SetTextureName(Urho3D::Texture* texture, const unsigned short* name) {
	texture->SetName(Urho3D::String((const wchar_t*)name));
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
PB_FUNCTION(void) uh3_SetTextureFilterMode(Urho3D::Texture* texture, int mode) {
	texture->SetFilterMode((Urho3D::TextureFilterMode)mode);
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
PB_FUNCTION(void) uh3_SetRenderSurfaceViewport(Urho3D::RenderSurface* surface, int index , Urho3D::Viewport* viewport) {
	surface->SetViewport(index, viewport);
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
PB_FUNCTION(void) uh3_SetTextureAddressMode(Urho3D::Texture* texture) {
//	texture->SetAddressMode(Urho3D::TextureCoordinate::COORD_U, Urho3D::TextureAddressMode::)
}