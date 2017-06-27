#include "AnimatedModel.hpp"


PB_FUNCTION(Urho3D::AnimatedModel*) uh3_GetAnimatedModel(Urho3D::Node* node, int recursive) {
	return node->GetComponent<Urho3D::AnimatedModel>((bool)recursive);
}

PB_FUNCTION(Urho3D::AnimationController*) uh3_GetAnimationController(Urho3D::AnimatedModel* model) {
	return model->GetComponent<Urho3D::AnimationController>();
}

PB_FUNCTION(void) uh3_PlayAnimation(Urho3D::AnimationController* controller, const unsigned short* name, unsigned char layer, int looped, float fadeTime) {
	controller->Play(Urho3D::String((const wchar_t*)name), layer, (bool)looped, fadeTime);
}

PB_FUNCTION(void) uh3_SetAnimationSpeed(Urho3D::AnimationController* controller, const unsigned short* name, float speed) {
	controller->SetSpeed(Urho3D::String((const wchar_t*)name), speed);
}

PB_FUNCTION(void) uh3_StopAllAnimation(Urho3D::AnimationController* controller, float fadeTime) {
	controller->StopAll(fadeTime);
}

PB_FUNCTION(int) uh3_AnimationIsEnd(Urho3D::AnimationController* controller, const unsigned short* name) {
	return controller->IsAtEnd(Urho3D::String((const wchar_t*)name));
}
