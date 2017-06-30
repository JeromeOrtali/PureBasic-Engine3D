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
#include "Engine3D.hpp"


void register_script() {
	PB_ENGINE_CONTEXT->RegisterSubsystem(new Urho3D::Script(PB_ENGINE_CONTEXT));
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
PB_FUNCTION(void) uh3_InitEngine3D(int argc, char **argv) {

	Urho3D::ParseArguments(argc, argv);
	PB_ENGINE_PARAMETERS	= new Urho3D::VariantMap();
	PB_ENGINE_CONTEXT		= new Urho3D::Context();
	PB_ENGINE				= new Urho3D::Engine(PB_ENGINE_CONTEXT);
	*PB_ENGINE_PARAMETERS	= Urho3D::Engine::ParseParameters(Urho3D::GetArguments());
	PB_URHOEVENT			= new PB_EventHandler(PB_ENGINE_CONTEXT);
	PB_EVENT				= new std::queue<Event>;
	PB_RESOURCECACHE		= PB_ENGINE_CONTEXT->GetSubsystem<Urho3D::ResourceCache>();// Urho3D::GetSubsystem<ResourceCache>();//new Urho3D::ResourceCache(PB_ENGINE_CONTEXT);

	//PB_ENGINE_CONTEXT->RegisterFactory<Urho3D::ScriptInstance>("ScriptInstance");
	
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
PB_FUNCTION(void) uh3_OpenScreen3D(int width, int height, int fullscreen, const unsigned short* title, int resizable) {

	Urho3D::VariantMap & map = *PB_ENGINE_PARAMETERS;

	if (fullscreen == 1) {
		map["FullScreen"] = true;
	}
	else {
		map["FullScreen"] = false;
	}

	map["WindowWidth"]		= width;
	map["WindowHeight"]		= height;
	map["WindowTitle"]		= Urho3D::String((const wchar_t*)title);
	map["LogLevel "]		= Urho3D::LOG_DEBUG;
	if (resizable == 1) {
		map["WindowResizable"] = true;
	}else{
		map["WindowResizable"] = false;
	}

	PB_ENGINE->Initialize(*PB_ENGINE_PARAMETERS);
	PB_ENGINE_CONTEXT->RegisterSubsystem(new Urho3D::Script(PB_ENGINE_CONTEXT));

	PB_ENGINE->GetSubsystem<Urho3D::Renderer>()->SetReuseShadowMaps(false);
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
PB_FUNCTION(void) uh3_EmbedScreen(void *window) {
	Urho3D::VariantMap & map = *PB_ENGINE_PARAMETERS;
	map["ExternalWindow"] = window;
	map["LogLevel "] = Urho3D::LOG_DEBUG;
	PB_ENGINE->Initialize(*PB_ENGINE_PARAMETERS);
	PB_ENGINE_CONTEXT->RegisterSubsystem(new Urho3D::Script(PB_ENGINE_CONTEXT));
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
PB_FUNCTION(int) uh3_EngineRun() {
	return PB_ENGINE->IsExiting() ? false : true;
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
PB_FUNCTION(void) uh3_EngineExit() {
	PB_ENGINE->Exit();

	delete PB_ENGINE_CONTEXT;
	delete PB_ENGINE_PARAMETERS;
	//delete PB_RESOURCECACHE;
	delete PB_EVENT;

}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
PB_FUNCTION(void) uh3_EngineRenderFrame() {
	PB_ENGINE->Update();
	PB_ENGINE->RunFrame();
}

PB_FUNCTION(void) uh3_SetDrawShadow(int enable) {
	PB_ENGINE->GetSubsystem<Urho3D::Renderer>()->SetDrawShadows((int)enable);
}

PB_FUNCTION(int) uh3_GetDrawShadow() {
	return (int)PB_ENGINE->GetSubsystem<Urho3D::Renderer>()->GetDrawShadows();
}

PB_FUNCTION(void) uh3_SetHDRRendering(int enable) {
	PB_ENGINE->GetSubsystem<Urho3D::Renderer>()->SetHDRRendering((int)enable);
}

PB_FUNCTION(int) uh3_GetHDRRendering() {
	return (int)PB_ENGINE->GetSubsystem<Urho3D::Renderer>()->GetHDRRendering();
}

PB_FUNCTION(void) uh3_SetSpecularLighting(int enable) {
	PB_ENGINE->GetSubsystem<Urho3D::Renderer>()->SetSpecularLighting((int)enable);
}

PB_FUNCTION(int) uh3_GetSpecularLighting() {
	return (int)PB_ENGINE->GetSubsystem<Urho3D::Renderer>()->GetSpecularLighting();
}

PB_FUNCTION(void) uh3_SetShadowMapSize(int size) {
	PB_ENGINE->GetSubsystem<Urho3D::Renderer>()->SetShadowMapSize(size);
}

PB_FUNCTION(int) uh3_GetShadowMapSize() {
	return (int)PB_ENGINE->GetSubsystem<Urho3D::Renderer>()->GetShadowMapSize();
}

PB_FUNCTION(void) uh3_SetShadowMapQuality(int quality) {
	PB_ENGINE->GetSubsystem<Urho3D::Renderer>()->SetShadowQuality((Urho3D::ShadowQuality)quality);
}

PB_FUNCTION(int) uh3_GetShadowMapQuality() {
	return (int)PB_ENGINE->GetSubsystem<Urho3D::Renderer>()->GetShadowQuality();
}