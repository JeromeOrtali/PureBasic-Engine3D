#include "Script.hpp"
#include <iostream> 
#include <stdexcept> 

///--- CHANGE NAME ???
PB_FUNCTION(void) uh3_NodeLoadScript(Urho3D::ScriptInstance* script, Urho3D::ScriptFile* resource, const unsigned short* classname) {
	script->CreateObject(resource, Urho3D::String((const wchar_t*)classname));
}