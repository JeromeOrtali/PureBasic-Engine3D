#include "Scene.hpp"

PB_FUNCTION(Urho3D::Scene*) PB_CreateScene() {
	return  new Urho3D::Scene(PB_ENGINE_CONTEXT);
}

PB_FUNCTION(void) PB_FreeScene(Urho3D::Scene* scene) {
	delete scene;
}

PB_FUNCTION(Urho3D::Component*) PB_CreateSceneComponent(Urho3D::Scene* scene, SceneComponent component) {
	switch (component)
	{
	case debugRenderer:
		return scene->CreateComponent<Urho3D::DebugRenderer>();
		break;	
	case octree:
		return scene->CreateComponent<Urho3D::Octree>();
		break;
	case physicWorld:
		return scene->CreateComponent<Urho3D::PhysicsWorld>();
		break;
	case physicWorld2D:
		return scene->CreateComponent<Urho3D::PhysicsWorld2D>();
		break;
	default:
		return (Urho3D::Component*)nullptr;
		break;
	}
}

PB_FUNCTION(Urho3D::Node*) PB_CreateNode(Urho3D::Scene* scene, const unsigned short* name) {
	return scene->CreateChild(Urho3D::String((const wchar_t*)name));
}

PB_FUNCTION(int) PB_SaveScene(Urho3D::Scene* scene, const unsigned short* name, SceneFormat format) {
	Urho3D::File file(PB_ENGINE_CONTEXT, Urho3D::String((const wchar_t*)name), Urho3D::FILE_WRITE);
	switch (format)
	{
	case JSON:
		return (int)scene->SaveJSON(file);
		break;
	case XML:
		return (int)scene->SaveXML(file);
		break;
	case BINARY:
		return (int)scene->Save(file);
		break;
	default:
		return 0;
		break;
	}
}


PB_FUNCTION(int) PB_LoadScene(Urho3D::Scene* scene, const unsigned short* name, SceneFormat format) {
	Urho3D::File file(PB_ENGINE_CONTEXT, Urho3D::String((const wchar_t*)name), Urho3D::FILE_READ);
	switch (format)
	{
	case JSON:
		return (int)scene->LoadJSON(file);
		break;
	case XML:
		return (int)scene->LoadXML(file);
		break;
	case BINARY:
		return (int)scene->Load(file);
		break;
	default:
		return 0;
		break;
	}
}