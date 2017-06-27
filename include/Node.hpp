#ifndef NODE_HPP
#define NODE_HPP

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
#include <Urho3D/Graphics/AnimatedModel.h>
#include <Urho3D/Graphics/Material.h>
#include <Urho3D/Graphics/Skybox.h>
#include <Urho3D/Graphics/Terrain.h>
#include <Urho3D/AngelScript/Script.h>
#include <Urho3D/AngelScript/ScriptInstance.h>

#ifndef PB_FUNCTION
#define PB_FUNCTION(T) __declspec(dllexport) T
#endif 

enum NodeComponent {
	camera,
	staticModel,
	animatedModel,
	skybox,
	light,
	terrain,
	scriptInstance
};


extern "C" {

	PB_FUNCTION(void*) uh3_CreateNodeComponent(Urho3D::Node* node, NodeComponent component);

	PB_FUNCTION(Urho3D::Node*) uh3_GetChildByName(Urho3D::Node* node, const unsigned short* name, int recursive);

	PB_FUNCTION(Urho3D::Node*) uh3_GetChildByID(Urho3D::Node* node, unsigned int id);

	PB_FUNCTION(void) uh3_SetNodePosition(Urho3D::Node* node, float x, float y, float z);

	PB_FUNCTION(void) uh3_NodeTranslate(Urho3D::Node* node, float x, float y, float z, int mode);

	PB_FUNCTION(void) uh3_SetNodeRotation(Urho3D::Node* node, float x, float y, float z);

	PB_FUNCTION(void) uh3_NodeRotate(Urho3D::Node* node, float x, float y, float z, int mode);

}



#endif