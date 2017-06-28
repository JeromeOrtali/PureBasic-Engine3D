#include "Viewport.hpp"

PB_FUNCTION(Urho3D::Viewport*) uh3_CreateViewport(Urho3D::Scene* scene, Urho3D::Node* camera) {
	Urho3D::Renderer* renderer = PB_ENGINE->GetSubsystem<Urho3D::Renderer>();
	Urho3D::Viewport* viewport = new Urho3D::Viewport(PB_ENGINE_CONTEXT, scene, camera->GetComponent<Urho3D::Camera>());
	renderer->SetViewport(0, viewport);
	return viewport; 
}

PB_FUNCTION(void) uh3_BackgroundColor(Urho3D::Viewport* viewport, unsigned char red, unsigned char green, unsigned char blue) {
	Urho3D::RenderPath * rp = viewport->GetRenderPath();
	for (int i = 0; i < rp->GetNumCommands(); i++)
	{
		Urho3D::RenderPathCommand * cmd = rp->GetCommand(i);
		if (cmd->type_ == Urho3D::RenderCommandType::CMD_CLEAR)
		{
			cmd->useFogColor_ = false;
			cmd->clearColor_ = Urho3D::Color((float)red/255.0f, (float)green/255.0f,(float)blue/255.0f, 1.0f);
		}
	}
}