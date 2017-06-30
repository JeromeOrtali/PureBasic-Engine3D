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
	PB_FUNCTION(void) uh3_InitEngine3D(int argc, char **argv);
	PB_FUNCTION(void) uh3_OpenScreen3D(int width, int height, int fullscreen, const unsigned short* title, int resizable);
	PB_FUNCTION(void) uh3_EmbedScreen(void *window);
	PB_FUNCTION(int)  uh3_EngineRun();
	PB_FUNCTION(void) uh3_EngineExit();
	PB_FUNCTION(void) uh3_EngineRenderFrame();
	
}






#endif