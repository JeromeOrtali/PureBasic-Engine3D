#include "Viewport.hpp"

PB_FUNCTION(Urho3D::Viewport*) uh3_CreateViewport(Urho3D::Scene* scene, Urho3D::Node* camera, int index) {
	Urho3D::Renderer* renderer = PB_ENGINE->GetSubsystem<Urho3D::Renderer>();
	Urho3D::Viewport* viewport = new Urho3D::Viewport(PB_ENGINE_CONTEXT, scene, camera->GetComponent<Urho3D::Camera>());
	renderer->SetViewport(index, viewport);
	return viewport; 
}

PB_FUNCTION(void) uh3_SetViewportBackgroundColor(Urho3D::Viewport* viewport, unsigned int color) {
	Urho3D::RenderPath * rp = viewport->GetRenderPath();
	for (int i = 0; i < rp->GetNumCommands(); i++)	{
		Urho3D::RenderPathCommand * cmd = rp->GetCommand(i);
		if (cmd->type_ == Urho3D::RenderCommandType::CMD_CLEAR)	{
			cmd->useFogColor_ = false;
			float r = ((color & 0xFF))/255.0f;
			float g = ((color >> 8) & 0xFF)/255.0f;
			float b = ((color >> 16) & 0xFF)/255.0f;
			cmd->clearColor_ = Urho3D::Color(r,g,b, 1.0f);
		}
	}
}

PB_FUNCTION(void) uh3_SetViewportRect(Urho3D::Viewport* viewport, int left, int top, int right, int bottom) {
	viewport->SetRect(Urho3D::IntRect(left, top, right, bottom));
}

PB_FUNCTION(void) uh3_SetViewportRenderPathXML(Urho3D::Viewport* viewport, Urho3D::XMLFile* resource) {
	viewport->SetRenderPath(resource);
}

