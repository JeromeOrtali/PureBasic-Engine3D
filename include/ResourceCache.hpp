#ifndef RESOURCECACHE_HPP
#define RESOURCECACHE_HPP


#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Resource/XMLFile.h>
#include <Urho3D/Resource/JSONFile.h>
#include <Urho3D/Resource/Image.h>
#include <Urho3D/Graphics/Model.h>
#include <Urho3D/Graphics/ParticleEffect.h>
#include <Urho3D/Graphics/Material.h>
#include <Urho3D/Audio/Sound.h>
#include <Urho3D/Urho2D/TmxFile2D.h>
#include <Urho3D/UI/Font.h>
#include <Urho3D/AngelScript/ScriptFile.h>
#include <Urho3D/AngelScript/Script.h>
#include <Urho3D/AngelScript/ScriptInstance.h>

extern Urho3D::ResourceCache* PB_RESOURCECACHE;

enum Resource {
	Sound,
	Material,
	Model,
	ParticleEffect,
	TMXFile,
	XMLFile,
	JSONFile,
	Font,
	Image,
	Script
};

#ifndef PB_FUNCTION
#define PB_FUNCTION(T) __declspec(dllexport) T
#endif 

extern "C" {
	PB_FUNCTION(void*) uh3_getResource(Resource type, const unsigned short* name);

	PB_FUNCTION(int) uh3_backgroundLoadResource(Resource type, const unsigned short* name);
}



#endif // !RESOURCECACHE_HPP
