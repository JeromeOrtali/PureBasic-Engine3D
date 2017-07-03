#include "Camera.hpp"


PB_FUNCTION(void) uh3_SetCameraFov(Urho3D::Camera* camera, float fov) {
	camera->SetFov(fov);
}

PB_FUNCTION(float) uh3_GetCameraFov(Urho3D::Camera* camera) {
	return camera->GetFov();
}

PB_FUNCTION(void) uh3_SetCameraNearClip(Urho3D::Camera* camera, float value) {
	camera->SetNearClip(value);
}

PB_FUNCTION(float) uh3_GetCameraNearClip(Urho3D::Camera* camera) {
	return camera->GetNearClip();
}

PB_FUNCTION(void) uh3_SetCameraFarClip(Urho3D::Camera* camera, float value) {
	camera->SetFarClip(value);
}

PB_FUNCTION(float) uh3_GetCameraFarClip(Urho3D::Camera* camera) {
	return camera->GetFarClip();
}

PB_FUNCTION(void) uh3_SetCameraViewMask(Urho3D::Camera* camera, unsigned int viewMask) {
	camera->SetViewMask(viewMask);
}

PB_FUNCTION(unsigned int) uh3_GetCameraViewMask(Urho3D::Camera* camera) {
	return camera->GetViewMask();
}

PB_FUNCTION(void) uh3_SetCameraAutoAspectRatio(Urho3D::Camera* camera, int enable) {
	camera->SetAutoAspectRatio((bool)enable);
}

PB_FUNCTION(void) uh3_SetCameraUseReflection(Urho3D::Camera* camera, int enable) {
	camera->SetUseReflection((bool)enable);
}

PB_FUNCTION(void) uh3_SetCameraReflectionPlane(Urho3D::Camera* camera, Urho3D::Plane* plane) {
	camera->SetReflectionPlane(*plane);
}

PB_FUNCTION(void) uh3_SetCameraUseClipping(Urho3D::Camera* camera, int enable) {
	camera->SetUseClipping((bool)enable);
}

PB_FUNCTION(void) uh3_SetCameraClipPlane(Urho3D::Camera* camera, Urho3D::Plane* plane) {
	camera->SetClipPlane(*plane);
}

PB_FUNCTION(void) uh3_SetCameraAspectRatio(Urho3D::Camera* camera, float aspectRatio) {
	camera->SetAspectRatio(aspectRatio);
}


PB_FUNCTION(Urho3D::Plane*) uh3_CreatePlane(float nx, float ny, float nz, float px, float py, float pz) {
	return new Urho3D::Plane(Urho3D::Vector3(nx, ny, nz), Urho3D::Vector3(px, py, pz));
}

PB_FUNCTION(Urho3D::Plane*) uh3_CreatePlane2(Urho3D::Node* node, float nx, float ny, float nz, float px, float py, float pz) {
	return new Urho3D::Plane(node->GetWorldRotation() * Urho3D::Vector3(nx, ny, nz), node->GetWorldPosition() - Urho3D::Vector3(px, py, pz));
}

PB_FUNCTION(void) uh3_FreePlane(Urho3D::Plane* plane) {
	delete plane;
}