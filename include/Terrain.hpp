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
#ifndef TERRAIN_HPP
#define TERRAIN_HPP

#include <Urho3D/Engine/Engine.h>
#include <Urho3D/Graphics/Graphics.h>
#include <Urho3D/Graphics/Material.h>
#include <Urho3D/Graphics/Terrain.h>

enum TerrainNeighBor {
	north,
	south,
	west,
	east	
};

#ifndef PB_FUNCTION
	#define PB_FUNCTION(T) __declspec(dllexport) T
#endif 

extern Urho3D::Context*						PB_ENGINE_CONTEXT;
extern Urho3D::SharedPtr<Urho3D::Engine>	PB_ENGINE;

extern "C" {
	PB_FUNCTION(void) uh3_SetTerrainPatchSize(Urho3D::Terrain* terrain, int size);
	PB_FUNCTION(int) uh3_GetTerrainPatchSize(Urho3D::Terrain* terrain);
	PB_FUNCTION(void) uh3_SetTerrainSpacing(Urho3D::Terrain* terrain, float x, float y, float z);
	PB_FUNCTION(void) uh3_GetTerrainSpacing(Urho3D::Terrain* terrain, float *x, float *y, float *z);
	PB_FUNCTION(void) uh3_SetMaxLodLevel(Urho3D::Terrain* terrain, unsigned int levels);
	PB_FUNCTION(unsigned int) uh3_GetMaxLodLevel(Urho3D::Terrain* terrain);
	PB_FUNCTION(void) uh3_SetTerrainSmoothing(Urho3D::Terrain* terrain, int enable);
	PB_FUNCTION(int) uh3_GetTerrainSmoothing(Urho3D::Terrain* terrain);
	PB_FUNCTION(int) uh3_SetTerrainHeightMap(Urho3D::Terrain* terrain, Urho3D::Image* image);
	PB_FUNCTION(void) uh3_SetTerrainApplyHeightMap(Urho3D::Terrain* terrain);
	PB_FUNCTION(void) uh3_SetTerrainMaterial(Urho3D::Terrain* terrain, Urho3D::Material* material);
	PB_FUNCTION(Urho3D::Material*) uh3_GetTerrainMaterial(Urho3D::Terrain* terrain);
	PB_FUNCTION(void) uh3_SetTerrainNeighbor(Urho3D::Terrain* terrain, Urho3D::Terrain* neighborTerrain, TerrainNeighBor neighbor);
	PB_FUNCTION(float) uh3_GetTerrainHeight(Urho3D::Terrain* terrain, float x, float y, float z);
	PB_FUNCTION(void) uh3_GetTerrainNormal(Urho3D::Terrain* terrain, float x, float y, float z, float *nx, float *ny, float *nz);
	PB_FUNCTION(void) uh3_SetTerrainOccluder(Urho3D::Terrain* terrain, int state);
	PB_FUNCTION(void) uh3_SetTerrainOccluder(Urho3D::Terrain* terrain, int state);
	PB_FUNCTION(int) uh3_GetTerrainOccluder(Urho3D::Terrain* terrain);

	PB_FUNCTION(void) uh3_SetTerrainCastShadow(Urho3D::Terrain* terrain, int state);
	PB_FUNCTION(int) uh3_GetTerrainCastShadow(Urho3D::Terrain* terrain);
	PB_FUNCTION(void) uh3_GetTerrainWorldToHeightmap(Urho3D::Terrain* terrain, float x, float y, float z, unsigned int *px, unsigned int *py);
	PB_FUNCTION(void) uh3_SetTerrainLodBias(Urho3D::Terrain* terrain, float bias);
}
#endif