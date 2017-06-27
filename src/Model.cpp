#include "Model.hpp"


PB_FUNCTION(void) PB_SetModel(Urho3D::StaticModel* node, Urho3D::Model* model) {
	node->SetModel(model);
}

PB_FUNCTION(void) PB_SetMaterial(Urho3D::StaticModel* node, Urho3D::Material* material) {
	node->SetMaterial(material);
}





PB_FUNCTION(Urho3D::AnimatedModel*) PB_GetAnimatedModel(Urho3D::Node* node) {
	return node->GetComponent<Urho3D::AnimatedModel>();
}

PB_FUNCTION(Urho3D::AnimationController*) PB_GetAnimationController(Urho3D::AnimatedModel* model) {
	return model->GetComponent<Urho3D::AnimationController>();
}

PB_FUNCTION(void) PB_PlayAnimation(Urho3D::AnimationController* controller, const unsigned short* name, unsigned char layer, int looped, float fadeTime) {
	controller->Play(Urho3D::String((const wchar_t*)name), layer, (bool)looped, fadeTime);
}

PB_FUNCTION(void) PB_SetAnimationSpeed(Urho3D::AnimationController* controller, const unsigned short* name, float speed) {
	controller->SetSpeed(Urho3D::String((const wchar_t*)name), speed);
}

PB_FUNCTION(void) PB_StopAllAnimation(Urho3D::AnimationController* controller, float fadeTime) {
	controller->StopAll(fadeTime);
}

PB_FUNCTION(int) PB_AnimationIsEnd(Urho3D::AnimationController* controller, const unsigned short* name) {
	return controller->IsAtEnd(Urho3D::String((const wchar_t*)name));
}