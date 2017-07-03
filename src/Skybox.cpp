#include "Skybox.hpp"


PB_FUNCTION(void) uh3_SetSkyboxModel(Urho3D::Skybox* skybox, Urho3D::Model* model) {
	skybox->SetModel(model);
}

PB_FUNCTION(void) uh3_SetSkyboxMaterial(Urho3D::Skybox* skybox, Urho3D::Material* material) {
	skybox->SetMaterial(material);
}