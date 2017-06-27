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

