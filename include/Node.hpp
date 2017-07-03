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
#include <Urho3D/Graphics/AnimatedModel.h>
#include <Urho3D/Graphics/AnimationController.h>
#include <Urho3D/Graphics/Zone.h>
#include "Scene.hpp"

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
	scriptInstance,
	animationController,
	zone
};


extern "C" {

	PB_FUNCTION(void*) uh3_CreateNodeComponent(Urho3D::Node* node, NodeComponent component);

	PB_FUNCTION(void*) uh3_GetNodeComponent(Urho3D::Node* node, NodeComponent component);

	PB_FUNCTION(Urho3D::Node*) uh3_GetNodeChildByName(Urho3D::Node* node, const unsigned short* name, int recursive);

	PB_FUNCTION(Urho3D::Node*) uh3_GetNodeChildByID(Urho3D::Node* node, unsigned int id);

	PB_FUNCTION(void) uh3_SetNodeTemporary(Urho3D::Node* node, int state);

	PB_FUNCTION(void) uh3_SetNodePosition(Urho3D::Node* node, float x, float y, float z);

	PB_FUNCTION(void) uh3_NodeTranslate(Urho3D::Node* node, float x, float y, float z, int mode);

	PB_FUNCTION(void) uh3_SetNodeRotation(Urho3D::Node* node, float x, float y, float z);

	PB_FUNCTION(void) uh3_NodeRotate(Urho3D::Node* node, float x, float y, float z, int mode);
	
	PB_FUNCTION(void) uh3_SetNodeDirection(Urho3D::Node* node, float x, float y, float z);

	PB_FUNCTION(void) uh3_SetNodeUniformScale(Urho3D::Node* node, float scale);

	PB_FUNCTION(void) uh3_SetNodeScale(Urho3D::Node* node, float x, float y, float z);

	PB_FUNCTION(void) uh3_SetNodeWorldPosition(Urho3D::Node* node, float x, float y, float z);

	PB_FUNCTION(void) uh3_NodeLookAt(Urho3D::Node* node, float x, float y, float z, float ux, float uy, float uz, int mode);

	PB_FUNCTION(void) uh3_SetNodePitch(Urho3D::Node* node, float pitch, int mode);

	PB_FUNCTION(void) uh3_SetNodeYaw(Urho3D::Node* node, float yaw, int mode);

	PB_FUNCTION(void) uh3_SetNodeRoll(Urho3D::Node* node, float roll, int mode);

	PB_FUNCTION(float) uh3_GetNodePositionX(Urho3D::Node* node);

	PB_FUNCTION(float) uh3_GetNodePositionY(Urho3D::Node* node);

	PB_FUNCTION(float) uh3_GetNodePositionZ(Urho3D::Node* node);

	PB_FUNCTION(float) uh3_GetNodeRotationX(Urho3D::Node* node);

	PB_FUNCTION(float) uh3_GetNodeRotationY(Urho3D::Node* node);

	PB_FUNCTION(float) uh3_GetNodeRotationZ(Urho3D::Node* node);

	PB_FUNCTION(float) uh3_GetNodeDirectionX(Urho3D::Node* node);

	PB_FUNCTION(float) uh3_GetNodeDirectionY(Urho3D::Node* node);

	PB_FUNCTION(float) uh3_GetNodeDirectionZ(Urho3D::Node* node);

	PB_FUNCTION(float) uh3_GetNodeWorldDirectionX(Urho3D::Node* node);

	PB_FUNCTION(float) uh3_GetNodeWorldDirectionY(Urho3D::Node* node);

	PB_FUNCTION(float) uh3_GetNodeWorldDirectionZ(Urho3D::Node* node);

	PB_FUNCTION(float) uh3_GetNodeWorldPositionX(Urho3D::Node* node);

	PB_FUNCTION(float) uh3_GetNodeWorldPositionY(Urho3D::Node* node);

	PB_FUNCTION(float) uh3_GetNodeWorldPositionZ(Urho3D::Node* node);

	PB_FUNCTION(float) uh3_GetNodeWorldRotationX(Urho3D::Node* node);

	PB_FUNCTION(float) uh3_GetNodeWorldRotationY(Urho3D::Node* node);

	PB_FUNCTION(float) uh3_GetNodeWorldRotationZ(Urho3D::Node* node);

	PB_FUNCTION(Urho3D::Node*) uh3_NodeCreateChild(Urho3D::Node* node, const unsigned short* name, NodeType type);

	PB_FUNCTION(Urho3D::Node*) uh3_NodeCreateTemporaryChild(Urho3D::Node* node, const unsigned short* name, NodeType type);

	PB_FUNCTION(void) uh3_NodeAttach(Urho3D::Node* nodeParent, Urho3D::Node* nodeChild);

	PB_FUNCTION(void) uh3_NodeRemoveChild(Urho3D::Node* node, Urho3D::Node* nodeToRemove);

	PB_FUNCTION(void) uh3_NodeRemoveAllChild(Urho3D::Node* node);

	PB_FUNCTION(void) uh3_NodeRemoveChildren(Urho3D::Node* node, int replicated, int local, int recursive);

	PB_FUNCTION(void) uh3_SetNodeParent(Urho3D::Node* node, Urho3D::Node* parent);

	PB_FUNCTION(void) uh3_SetNodeEnabled(Urho3D::Node* node, int state); // without recursion

	PB_FUNCTION(void) uh3_SetNodeDeepEnabled(Urho3D::Node* node, int state); // with recursion

}





#endif