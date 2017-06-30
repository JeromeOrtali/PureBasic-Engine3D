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
#include "Scene.hpp"

PB_FUNCTION(Urho3D::Scene*) uh3_CreateScene() {
	return  new Urho3D::Scene(PB_ENGINE_CONTEXT);
}

PB_FUNCTION(void) uh3_FreeScene(Urho3D::Scene* scene) {
	delete scene;
}

PB_FUNCTION(Urho3D::Component*) uh3_CreateSceneComponent(Urho3D::Scene* scene, SceneComponent component) {
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

PB_FUNCTION(Urho3D::Node*) uh3_CreateNode(Urho3D::Scene* scene, const unsigned short* name, NodeType type) {
	return scene->CreateChild(Urho3D::String((const wchar_t*)name), (Urho3D::CreateMode)type);
}

PB_FUNCTION(int) uh3_SaveScene(Urho3D::Scene* scene, const unsigned short* name, SceneFormat format) {
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


PB_FUNCTION(int) uh3_LoadSceneFromFile(Urho3D::Scene* scene, const unsigned short* name, SceneFormat format) {
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

PB_FUNCTION(int) uh3_LoadSceneFromResource(Urho3D::Scene* scene, void* resource ,SceneFormat format) {
	int result = 0;
	switch (format)
	{
	case JSON:
	{
		Urho3D::JSONFile* file = (Urho3D::JSONFile*)resource;
		result = (int)scene->LoadJSON(file->GetRoot());
		break;
	}
	case XML:
	{
		Urho3D::XMLFile* file = (Urho3D::XMLFile*)resource;
		result = (int)scene->LoadXML(file->GetRoot());
		break;
	}
	case BINARY:
	{
		Urho3D::File* file = (Urho3D::File*)resource;
		result =  (int)scene->LoadJSON(file);
		break;
	}
	default:
		break;
	}

	return result;
}


PB_FUNCTION(void) uh3_UpdateScene(Urho3D::Scene* scene, float timestep) {
	scene->Update(timestep);
}