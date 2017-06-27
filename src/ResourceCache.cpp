#include "ResourceCache.hpp"




PB_FUNCTION(void*) uh3_getResource(Resource type, const unsigned short* name) {
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
	default:
		break;
	}
	
		
	

	return result;
}


PB_FUNCTION(int) uh3_backgroundLoadResource(Resource type, const unsigned short* name) {
	
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
	default:
		break;
	}

	return 0;
}