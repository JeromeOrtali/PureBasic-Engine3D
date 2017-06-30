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
#ifndef SCENE_HPP
#define SCENE_HPP

#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Graphics/Renderer.h>
#include <Urho3D/Graphics/DebugRenderer.h>
#include <Urho3D/Scene/Component.h>
#include <Urho3D/Graphics/Octree.h>
#include <Urho3D/Graphics/GraphicsDefs.h>
#include <Urho3D/Graphics/RenderPath.h>
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


enum NodeType {
	replicated,
	local
};

extern Urho3D::Context*	PB_ENGINE_CONTEXT;
void register_script();

extern "C" {

	PB_FUNCTION(Urho3D::Scene*) uh3_CreateScene();

	PB_FUNCTION(void) uh3_FreeScene(Urho3D::Scene* scene);

	PB_FUNCTION(Urho3D::Component*) uh3_CreateSceneComponent(Urho3D::Scene* scene, SceneComponent component);

	PB_FUNCTION(Urho3D::Node*) uh3_CreateNode(Urho3D::Scene* scene, const unsigned short* name, NodeType type);

	PB_FUNCTION(int) uh3_SaveScene(Urho3D::Scene* scene, const unsigned short* name, SceneFormat format);

	PB_FUNCTION(int) uh3_LoadSceneFromFile(Urho3D::Scene* scene, const unsigned short* name, SceneFormat format);
	
	PB_FUNCTION(int) uh3_LoadSceneFromResource(Urho3D::Scene* scene, void* resource, SceneFormat format);

	PB_FUNCTION(void) uh3_UpdateScene(Urho3D::Scene* scene, float timestep);

}







#endif