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
#include "ResourceCache.hpp"




PB_FUNCTION(void*) uh3_GetResource(Resource type, const unsigned short* name) {
	void* result = nullptr;

	switch (type)
	{
	case Sound:
		return (void*)PB_RESOURCECACHE->GetResource<Urho3D::Sound>(Urho3D::String((const wchar_t*)name));
		break;
	case Material:
		return (void*)PB_RESOURCECACHE->GetResource<Urho3D::Material>(Urho3D::String((const wchar_t*)name));
		break;
	case Model:
		return (void*)PB_RESOURCECACHE->GetResource<Urho3D::Model>(Urho3D::String((const wchar_t*)name));
		break;
	case ParticleEffect:
		return (void*)PB_RESOURCECACHE->GetResource<Urho3D::ParticleEffect>(Urho3D::String((const wchar_t*)name));
		break;
	case TMXFile:
		return (void*)PB_RESOURCECACHE->GetResource<Urho3D::TmxFile2D>(Urho3D::String((const wchar_t*)name));
		break;
	case XMLFile:
		return (void*)PB_RESOURCECACHE->GetResource<Urho3D::XMLFile>(Urho3D::String((const wchar_t*)name));
		break;
	case JSONFile:
		return (void*)PB_RESOURCECACHE->GetResource<Urho3D::JSONFile>(Urho3D::String((const wchar_t*)name));
		break;
	case Font:
		return (void*)PB_RESOURCECACHE->GetResource<Urho3D::Font>(Urho3D::String((const wchar_t*)name));
		break;
	case Image:
		return (void*)PB_RESOURCECACHE->GetResource<Urho3D::Image>(Urho3D::String((const wchar_t*)name));
		break;
	case Script:
		return (void*)PB_RESOURCECACHE->GetResource<Urho3D::ScriptFile>(Urho3D::String((const wchar_t*)name));
		break;
	case Technique:
		return (void*)PB_RESOURCECACHE->GetResource<Urho3D::Technique>(Urho3D::String((const wchar_t*)name));
		break;
	default:
		return nullptr;
		break;
	}
	
		
	

	return result;
}


PB_FUNCTION(int) uh3_GetResourceBackground(Resource type, const unsigned short* name) {
	
	switch (type)
	{
	case Sound:
		return (int)PB_RESOURCECACHE->BackgroundLoadResource<Urho3D::Sound>(Urho3D::String((const wchar_t*)name));
		break;
	case Material:
		return (int)PB_RESOURCECACHE->BackgroundLoadResource<Urho3D::Material>(Urho3D::String((const wchar_t*)name));
		break;
	case Model:
		return (int)PB_RESOURCECACHE->BackgroundLoadResource<Urho3D::Model>(Urho3D::String((const wchar_t*)name));
		break;
	case ParticleEffect:
		return (int)PB_RESOURCECACHE->BackgroundLoadResource<Urho3D::ParticleEffect>(Urho3D::String((const wchar_t*)name));
		break;
	case TMXFile:
		return (int)PB_RESOURCECACHE->BackgroundLoadResource<Urho3D::TmxFile2D>(Urho3D::String((const wchar_t*)name));
		break;
	case XMLFile:
		return (int)PB_RESOURCECACHE->BackgroundLoadResource<Urho3D::XMLFile>(Urho3D::String((const wchar_t*)name));
		break;
	case JSONFile:
		return (int)PB_RESOURCECACHE->BackgroundLoadResource<Urho3D::JSONFile>(Urho3D::String((const wchar_t*)name));
		break;
	case Font:
		return (int)PB_RESOURCECACHE->BackgroundLoadResource<Urho3D::Font>(Urho3D::String((const wchar_t*)name));
		break;
	case Image:
		return (int)PB_RESOURCECACHE->BackgroundLoadResource<Urho3D::Image>(Urho3D::String((const wchar_t*)name));
		break;
	case Script:
		return (int)PB_RESOURCECACHE->BackgroundLoadResource<Urho3D::ScriptFile>(Urho3D::String((const wchar_t*)name));
		break;
	case Technique:
		return (int)PB_RESOURCECACHE->BackgroundLoadResource<Urho3D::Technique>(Urho3D::String((const wchar_t*)name));
		break;
	default:
		return 0;
		break;
	}

	return 0;
}

PB_FUNCTION(void) uh3_AddManualResource(Urho3D::Resource* resource) {
	PB_RESOURCECACHE->AddManualResource(resource);
}

PB_FUNCTION(void) uh3_ReloadResource(Urho3D::Resource* resource) {
	PB_RESOURCECACHE->ReloadResource(resource);
}
