#include "Model.hpp"

PB_FUNCTION(Urho3D::StaticModel*) uh3_getStaticModel(Urho3D::Node* node, int recursive) {
	return node->GetComponent<Urho3D::StaticModel>((bool)recursive);
}

PB_FUNCTION(void) uh3_SetModel(Urho3D::StaticModel* node, Urho3D::Model* model) {
	node->SetModel(model);
}

PB_FUNCTION(void) uh3_SetMaterial(Urho3D::StaticModel* node, Urho3D::Material* material) {
	node->SetMaterial(material);
}

