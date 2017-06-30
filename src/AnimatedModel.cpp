/*	PureBasic Engine3D licence
*	--------------------------
*
*	MIT License
*
*	Copyright (c) 2017 Jerome Ortali
*
*	Permission is hereby granted, free of charge, to any person obtaining a copy
*	of this software and associated documentation files (the "Software"), to deal
*	in the Software without restriction, including without limitation the rights
*	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*	copies of the Software, and to permit persons to whom the Software is
*	furnished to do so, subject to the following conditions:
*
*	The above copyright notice and this permission notice shall be included in all
*	copies or substantial portions of the Software.
*
*	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
*	SOFTWARE.
*/
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
