#ifndef SCENE_HPP
#define SCENE_HPP

#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Graphics/Renderer.h>
#include <Urho3D/Graphics/DebugRenderer.h>
#include <Urho3D/Scene/Component.h>
#include <Urho3D/Graphics/Octree.h>
#include <Urho3D/Physics/PhysicsWorld.h>
#include <Urho3D/Urho2D/PhysicsWorld2D.h>
#include <Urho3D/Scene/SceneEvents.h>
#include <Urho3D/IO/Serializer.h>
#include <Urho3D/IO/File.h>
#include <Urho3D/Resource/XMLFile.h>
#include <Urho3D/Resource/JSONFile.h>


#include <Urho3D/AngelScript/Script.h>
#include <Urho3D/AngelScript/ScriptInstance.h>



#ifndef PB_FUNCTION
	#define PB_FUNCTION(T) __declspec(dllexport) T
#endif 

extern Urho3D::Context*			PB_ENGINE_CONTEXT;

enum SceneComponent {
	debugRenderer,
	octree,
	physicWorld,
	physicWorld2D
};

enum SceneFormat {
	JSON,
	XML,
	BINARY
};

extern Urho3D::Context*	PB_ENGINE_CONTEXT;
void register_script();

extern "C" {

	PB_FUNCTION(Urho3D::Scene*) PB_CreateScene();

	PB_FUNCTION(void) PB_FreeScene(Urho3D::Scene* scene);

	PB_FUNCTION(Urho3D::Component*) PB_CreateSceneComponent(Urho3D::Scene* scene, SceneComponent component);

	PB_FUNCTION(Urho3D::Node*) PB_CreateNode(Urho3D::Scene* scene, const unsigned short* name);

	PB_FUNCTION(int) PB_SaveScene(Urho3D::Scene* scene, const unsigned short* name, SceneFormat format);

	PB_FUNCTION(int) PB_LoadScene(Urho3D::Scene* scene, const unsigned short* name, SceneFormat format);
	
	PB_FUNCTION(int) PB_LoadScene2(Urho3D::Scene* scene, void* resource, SceneFormat format);

	PB_FUNCTION(void) PB_UpdateScene(Urho3D::Scene* scene, float timestep);

}







#endif