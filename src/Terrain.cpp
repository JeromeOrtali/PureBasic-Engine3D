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
#include "Terrain.hpp"


PB_FUNCTION(void) uh3_SetTerrainPatchSize(Urho3D::Terrain* terrain, int size) {
	terrain->SetPatchSize(size);
}

PB_FUNCTION(int) uh3_GetTerrainPatchSize(Urho3D::Terrain* terrain) {
	return terrain->GetPatchSize();
}

PB_FUNCTION(void) uh3_SetTerrainSpacing(Urho3D::Terrain* terrain, float x, float y, float z) {
	terrain->SetSpacing(Urho3D::Vector3(x, y, z));
}

PB_FUNCTION(void) uh3_GetTerrainSpacing(Urho3D::Terrain* terrain, float *x, float *y, float *z) {
	Urho3D::Vector3 v = terrain->GetSpacing();
	*x = v.x_;
	*y = v.y_;
	*z = v.z_;
}

PB_FUNCTION(void) uh3_SetMaxLodLevel(Urho3D::Terrain* terrain, unsigned int levels) {
	terrain->SetMaxLodLevels(levels);
}

PB_FUNCTION(unsigned int) uh3_GetMaxLodLevel(Urho3D::Terrain* terrain) {
	return terrain->GetMaxLodLevels();
}

PB_FUNCTION(void) uh3_SetTerrainSmoothing(Urho3D::Terrain* terrain, int enable) {
	terrain->SetSmoothing((bool)enable);
}

PB_FUNCTION(int) uh3_GetTerrainSmoothing(Urho3D::Terrain* terrain) {
	return terrain->GetSmoothing();
}

PB_FUNCTION(int) uh3_SetTerrainHeightMap(Urho3D::Terrain* terrain, Urho3D::Image* image) {
	return (int)terrain->SetHeightMap(image);
}

PB_FUNCTION(void) uh3_SetTerrainApplyHeightMap(Urho3D::Terrain* terrain) {
	terrain->ApplyHeightMap();
}

PB_FUNCTION(void) uh3_SetTerrainMaterial(Urho3D::Terrain* terrain, Urho3D::Material* material) {
	terrain->SetMaterial(material);
}

PB_FUNCTION(Urho3D::Material*) uh3_GetTerrainMaterial(Urho3D::Terrain* terrain) {
	return terrain->GetMaterial();
}

PB_FUNCTION(void) uh3_SetTerrainNeighbor(Urho3D::Terrain* terrain, Urho3D::Terrain* neighborTerrain, TerrainNeighBor neighbor) {
	switch (neighbor)
	{
	case north:
		terrain->SetNorthNeighbor(neighborTerrain);
		break;
	case south:
		terrain->SetSouthNeighbor(neighborTerrain);
		break;
	case west:
		terrain->SetWestNeighbor(neighborTerrain);
		break;
	case east:
		terrain->SetEastNeighbor(neighborTerrain);
		break;
	default:
		break;
	}
}

PB_FUNCTION(float) uh3_GetTerrainHeight(Urho3D::Terrain* terrain, float x, float y, float z) {
	return terrain->GetHeight(Urho3D::Vector3(x, y, z));
}

PB_FUNCTION(void) uh3_GetTerrainNormal(Urho3D::Terrain* terrain, float x, float y, float z, float *nx, float *ny, float *nz) {
	Urho3D::Vector3 n = terrain->GetNormal(Urho3D::Vector3(x, y, z));
	*nx = n.x_;
	*ny = n.y_;
	*nz = n.z_;	
}

PB_FUNCTION(void) uh3_SetTerrainOccluder(Urho3D::Terrain* terrain, int state) {
	terrain->SetOccluder((bool)state);
}

PB_FUNCTION(int) uh3_GetTerrainOccluder(Urho3D::Terrain* terrain) {
	return (int)terrain->IsOccluder();
}

PB_FUNCTION(void) uh3_SetTerrainCastShadow(Urho3D::Terrain* terrain, int state) {
	terrain->SetCastShadows((bool)state);
}

PB_FUNCTION(int) uh3_GetTerrainCastShadow(Urho3D::Terrain* terrain) {
	return terrain->GetCastShadows();
}

PB_FUNCTION(void) uh3_GetTerrainWorldToHeightmap(Urho3D::Terrain* terrain, float x, float y, float z,unsigned int *px, unsigned int *py) {
	Urho3D::IntVector2 r = terrain->WorldToHeightMap(Urho3D::Vector3(x, y, z));
	*px = r.x_;
	*py = r.y_;
}

PB_FUNCTION(void) uh3_SetTerrainLodBias(Urho3D::Terrain* terrain, float bias) {
	terrain->SetLodBias(bias);
}