#ifndef ENGINE3D_HPP
#define ENGINE3D_HPP

#include <Urho3D/Engine/Application.h>
#include <Urho3D/Engine/Engine.h>
#include <Urho3D/Input/InputEvents.h>
#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Graphics/Renderer.h>
#include <Urho3D/IO/IOEvents.h>
#include <Urho3D/AngelScript/Script.h>
#include <Urho3D/AngelScript/ScriptInstance.h>
#include "Event.hpp"
#include <Urho3D/IO/Log.h>
Urho3D::SharedPtr<Urho3D::Engine>	PB_ENGINE;
Urho3D::Context*					PB_ENGINE_CONTEXT;		// do not forget to delete RAW pointer at exit function !!!
Urho3D::VariantMap*					PB_ENGINE_PARAMETERS;
Urho3D::ResourceCache*				PB_RESOURCECACHE;
PB_EventHandler*					PB_URHOEVENT;
std::queue<Event>*					PB_EVENT;


#ifndef PB_FUNCTION
	#define PB_FUNCTION(T) __declspec(dllexport) T
#endif 

void register_script();
extern "C" {

	PB_FUNCTION(void) PB_InitEngine3D(int argc, char **argv);

	PB_FUNCTION(void) PB_OpenScreen3D(int width, int height, int fullscreen, const unsigned short* title, int resizable);

	PB_FUNCTION(void) PB_EmbedScreen(void *window);

	PB_FUNCTION(int) PB_EngineRun();

	PB_FUNCTION(void) PB_EngineExit();

	PB_FUNCTION(void) PB_EngineRenderFrame();
}






#endif