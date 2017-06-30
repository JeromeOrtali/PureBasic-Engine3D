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
#include "Viewport.hpp"

PB_FUNCTION(Urho3D::Viewport*) uh3_CreateViewport(Urho3D::Scene* scene, Urho3D::Node* camera, int index) {
	Urho3D::Renderer* renderer = PB_ENGINE->GetSubsystem<Urho3D::Renderer>();
	Urho3D::Viewport* viewport = new Urho3D::Viewport(PB_ENGINE_CONTEXT, scene, camera->GetComponent<Urho3D::Camera>());
	renderer->SetViewport(index, viewport);
	return viewport; 
}

PB_FUNCTION(void) uh3_SetViewportBackgroundColor(Urho3D::Viewport* viewport, unsigned int color) {
	Urho3D::RenderPath * rp = viewport->GetRenderPath();
	for (unsigned int i = 0; i < rp->GetNumCommands(); i++)	{
		Urho3D::RenderPathCommand * cmd = rp->GetCommand(i);
		if (cmd->type_ == Urho3D::RenderCommandType::CMD_CLEAR)	{
			cmd->useFogColor_ = false;
			float r = ((color & 0xFF))/255.0f;
			float g = ((color >> 8) & 0xFF)/255.0f;
			float b = ((color >> 16) & 0xFF)/255.0f;
			cmd->clearColor_ = Urho3D::Color(r,g,b, 1.0f);
		}
	}
}

PB_FUNCTION(void) uh3_SetViewportRect(Urho3D::Viewport* viewport, int left, int top, int right, int bottom) {
	viewport->SetRect(Urho3D::IntRect(left, top, right, bottom));
}

PB_FUNCTION(void) uh3_SetViewportRenderPathXML(Urho3D::Viewport* viewport, Urho3D::XMLFile* resource) {
	viewport->SetRenderPath(resource);
}




// MOVE TO CAMERA CPP
PB_FUNCTION(void) uh3_SetCameraFov(Urho3D::Camera* camera, float fov) {
	camera->SetFov(fov);	
}

PB_FUNCTION(void) uh3_SetCameraNearClip(Urho3D::Camera* camera, float value) {
	camera->SetNearClip(value);
}

PB_FUNCTION(void) uh3_SetCameraFarClip(Urho3D::Camera* camera, float value) {
	camera->SetFarClip(value);
}