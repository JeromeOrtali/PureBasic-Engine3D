#ifndef ANIMATEDMODEL_HPP
#define ANIMATEDMODEL_HPP

#include <Urho3D/Engine/Engine.h>
#include <Urho3D/Graphics/Graphics.h>
#include <Urho3D/Graphics/Camera.h>
#include <Urho3D/Graphics/Geometry.h>
#include <Urho3D/Graphics/Renderer.h>
#include <Urho3D/Graphics/DebugRenderer.h>
#include <Urho3D/Graphics/Octree.h>
#include <Urho3D/Graphics/Light.h>
#include <Urho3D/Graphics/Model.h>
#include <Urho3D/Graphics/StaticModel.h>
#include <Urho3D/Graphics/Material.h>
#include <Urho3D/Graphics/Skybox.h>

#include <Urho3D/Graphics/AnimatedModel.h>
#include <Urho3D/Graphics/AnimationController.h>

#ifndef PB_FUNCTION
	#define PB_FUNCTION(T) __declspec(dllexport) T
#endif 

extern "C" {
	PB_FUNCTION(Urho3D::AnimatedModel*)			uh3_GetAnimatedModel(Urho3D::Node* node, int recursive);
	PB_FUNCTION(Urho3D::AnimationController*)	uh3_GetAnimationController(Urho3D::AnimatedModel* model);
	PB_FUNCTION(void)							uh3_PlayAnimation(Urho3D::AnimationController* controller, const unsigned short* name, unsigned char layer, int looped, float fadeTime);
	PB_FUNCTION(void)							uh3_SetAnimationSpeed(Urho3D::AnimationController* controller, const unsigned short* name, float speed);
	PB_FUNCTION(void)							uh3_StopAllAnimation(Urho3D::AnimationController* controller, float fadeTime);
	PB_FUNCTION(int)							uh3_AnimationIsEnd(Urho3D::AnimationController* controller, const unsigned short* name);
}

#endif // !ANIMATEDMODEL_HPP
