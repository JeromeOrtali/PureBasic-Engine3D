#ifndef VIEWPORT_HPP
#define VIEWPORT_HPP

#include <Urho3D/Engine/Engine.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Scene/Component.h>
#include <Urho3D/Graphics/Graphics.h>
#include <Urho3D/Graphics/Camera.h>
#include <Urho3D/Graphics/Geometry.h>
#include <Urho3D/Graphics/Renderer.h>
#include <Urho3D/Graphics/DebugRenderer.h>

#ifndef PB_FUNCTION
	#define PB_FUNCTION(T) __declspec(dllexport) T
#endif 

extern Urho3D::Context*						PB_ENGINE_CONTEXT;
extern Urho3D::SharedPtr<Urho3D::Engine>	PB_ENGINE;

extern "C" {
	PB_FUNCTION(Urho3D::Viewport*) PB_CreateViewport(Urho3D::Scene* scene, Urho3D::Node* camera);
}


#endif // !VIEWPORT_HPP
