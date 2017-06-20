#include "Scene.hpp"

PB_FUNCTION(Urho3D::Scene*) PB_CreateScene() {
	return new Urho3D::Scene(PB_ENGINE_CONTEXT);
}

PB_FUNCTION(void) PB_FreeScene(Urho3D::Scene* scene) {
	delete scene;
}