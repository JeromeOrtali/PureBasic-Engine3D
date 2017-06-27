#include "Viewport.hpp"

PB_FUNCTION(Urho3D::Viewport*) PB_CreateViewport(Urho3D::Scene* scene, Urho3D::Node* camera) {
	Urho3D::Renderer* renderer = PB_ENGINE->GetSubsystem<Urho3D::Renderer>();
	Urho3D::Viewport* viewport = new Urho3D::Viewport(PB_ENGINE_CONTEXT, scene, camera->GetComponent<Urho3D::Camera>());
	renderer->SetViewport(0, viewport);
	return viewport; 
}