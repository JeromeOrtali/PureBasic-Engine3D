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
#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <Urho3D/Engine/Engine.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Scene/Component.h>
#include <Urho3D/Graphics/Graphics.h>
#include <Urho3D/Graphics/Camera.h>

#ifndef PB_FUNCTION
	#define PB_FUNCTION(T) __declspec(dllexport) T
#endif 

extern Urho3D::Context*						PB_ENGINE_CONTEXT;
extern Urho3D::SharedPtr<Urho3D::Engine>	PB_ENGINE;

extern "C" {

	PB_FUNCTION(void) uh3_SetCameraFov(Urho3D::Camera* camera, float fov);
	PB_FUNCTION(float) uh3_GetCameraFov(Urho3D::Camera* camera);
	PB_FUNCTION(void) uh3_SetCameraNearClip(Urho3D::Camera* camera, float value);
	PB_FUNCTION(float) uh3_GetCameraNearClip(Urho3D::Camera* camera);
	PB_FUNCTION(void) uh3_SetCameraFarClip(Urho3D::Camera* camera, float value);
	PB_FUNCTION(float) uh3_GetCameraFarClip(Urho3D::Camera* camera);
	PB_FUNCTION(void) uh3_SetCameraViewMask(Urho3D::Camera* camera, unsigned int viewMask);
	PB_FUNCTION(unsigned int) uh3_GetCameraViewMask(Urho3D::Camera* camera);
	PB_FUNCTION(void) uh3_SetCameraAutoAspectRatio(Urho3D::Camera* camera, int enable);
	PB_FUNCTION(void) uh3_SetCameraUseReflection(Urho3D::Camera* camera, int enable);
	PB_FUNCTION(void) uh3_SetCameraReflectionPlane(Urho3D::Camera* camera, Urho3D::Plane* plane);
	PB_FUNCTION(void) uh3_SetCameraUseClipping(Urho3D::Camera* camera, int enable);
	PB_FUNCTION(void) uh3_SetCameraClipPlane(Urho3D::Camera* camera, Urho3D::Plane* plane);
	PB_FUNCTION(void) uh3_SetCameraAspectRatio(Urho3D::Camera* camera, float aspectRatio);

	PB_FUNCTION(Urho3D::Plane*) uh3_CreatePlane(float nx, float ny, float nz, float px, float py, float pz);
	PB_FUNCTION(Urho3D::Plane*) uh3_CreatePlane2(Urho3D::Node* node, float nx, float ny, float nz, float px, float py, float pz);

	PB_FUNCTION(void) uh3_FreePlane(Urho3D::Plane* plane);

}

#endif