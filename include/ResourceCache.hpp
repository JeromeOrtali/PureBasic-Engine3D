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
#ifndef RESOURCECACHE_HPP
#define RESOURCECACHE_HPP


#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Resource/XMLFile.h>
#include <Urho3D/Resource/JSONFile.h>
#include <Urho3D/Resource/Image.h>
#include <Urho3D/Graphics/Model.h>
#include <Urho3D/Graphics/ParticleEffect.h>
#include <Urho3D/Graphics/Material.h>
#include <Urho3D/Audio/Sound.h>
#include <Urho3D/Urho2D/TmxFile2D.h>
#include <Urho3D/UI/Font.h>
#include <Urho3D/AngelScript/ScriptFile.h>
#include <Urho3D/AngelScript/Script.h>
#include <Urho3D/AngelScript/ScriptInstance.h>
#include <Urho3D/Graphics/Technique.h>
extern Urho3D::ResourceCache* PB_RESOURCECACHE;

enum Resource {
	Sound,
	Material,
	Model,
	ParticleEffect,
	TMXFile,
	XMLFile,
	JSONFile,
	Font,
	Image,
	Script,
	Technique
};

#ifndef PB_FUNCTION
	#define PB_FUNCTION(T) __declspec(dllexport) T
#endif 

extern "C" {
	PB_FUNCTION(void*) uh3_GetResource(Resource type, const unsigned short* name);

	PB_FUNCTION(int) uh3_GetResourceBackground(Resource type, const unsigned short* name);

	PB_FUNCTION(void) uh3_AddManualResource(Urho3D::Resource* resource);
}



#endif // !RESOURCECACHE_HPP
