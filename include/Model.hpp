#ifndef MODEL_HPP
#define MODEL_HPP

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



#ifndef PB_FUNCTION
	#define PB_FUNCTION(T) __declspec(dllexport) T
#endif 

extern Urho3D::ResourceCache* PB_RESOURCECACHE;

extern "C" {

	PB_FUNCTION(void) PB_SetModel(Urho3D::StaticModel* node, Urho3D::Model* model);

	PB_FUNCTION(void) PB_SetMaterial(Urho3D::StaticModel* node, Urho3D::Material* material);

}


#endif 