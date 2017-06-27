#ifndef SCRIPT_HPP
#define SCRIPT_HPP

#include <Urho3D/Engine/Engine.h>
#include <Urho3D/Graphics/Graphics.h>
#include <Urho3D/AngelScript/Script.h>
#include <Urho3D/AngelScript/ScriptInstance.h>
#include <Urho3D/AngelScript/ScriptFile.h>

#ifndef PB_FUNCTION
	#define PB_FUNCTION(T) __declspec(dllexport) T
#endif 

extern "C" {

	PB_FUNCTION(void) PB_NodeLoadScript(Urho3D::ScriptInstance* script, Urho3D::ScriptFile* resource, const unsigned short* classname);


}


#endif // !SCRIPT_HPP
