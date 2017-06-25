#include "Model.hpp"


PB_FUNCTION(void) PB_SetModel(Urho3D::StaticModel* node, Urho3D::Model* model) {
	node->SetModel(model);
}

PB_FUNCTION(void) PB_SetMaterial(Urho3D::StaticModel* node, Urho3D::Material* material) {
	node->SetMaterial(material);
}

