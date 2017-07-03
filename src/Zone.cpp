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
#include "Zone.hpp"


PB_FUNCTION(void) uh3_SetZoneSize(Urho3D::Zone* zone, float minx, float miny, float minz, float maxx, float maxy, float maxz) {
	zone->SetBoundingBox(Urho3D::BoundingBox(Urho3D::Vector3(minx, miny, minz), Urho3D::Vector3(maxx, maxy, maxz)));
	//zone->SetBoundingBox(Urho3D::BoundingBox(-1000, 1000));
}

PB_FUNCTION(void) uh3_SetZoneAmbientColor(Urho3D::Zone* zone, unsigned int color) {
	float r = (float)((color & 0xFF)) / 255.0f;
	float g = (float)((color >> 8) & 0xFF) / 255.0f;
	float b = (float)((color >> 16) & 0xFF) / 255.0f;
	zone->SetAmbientColor(Urho3D::Color(r, g, b));
}

PB_FUNCTION(void) uh3_SetZoneFogColor(Urho3D::Zone* zone, unsigned int color) {
	float r = (float)((color & 0xFF)) / 255.0f;
	float g = (float)((color >> 8) & 0xFF) / 255.0f;
	float b = (float)((color >> 16) & 0xFF) / 255.0f;
	zone->SetFogColor(Urho3D::Color(r, g, b));
}


PB_FUNCTION(void) uh3_SetZoneFogStart(Urho3D::Zone* zone, float start) {
	zone->SetFogStart(start);
}

PB_FUNCTION(void) uh3_SetZoneFogEnd(Urho3D::Zone* zone, float end) {
	zone->SetFogEnd(end);
}