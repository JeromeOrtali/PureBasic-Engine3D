#ifndef SCENE_HPP
#define SCENE_HPP

#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Scene/SceneEvents.h>

#ifndef PB_FUNCTION
	#define PB_FUNCTION(T) __declspec(dllexport) T
#endif 

extern Urho3D::Context*	PB_ENGINE_CONTEXT;

extern "C" {

	PB_FUNCTION(Urho3D::Scene*) PB_CreateScene();

	PB_FUNCTION(void) PB_FreeScene(Urho3D::Scene*);

}







#endif