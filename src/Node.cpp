#include "Node.hpp"



PB_FUNCTION(void*) uh3_CreateNodeComponent(Urho3D::Node* node, NodeComponent component) {
	switch (component)
	{
	case camera: {
		Urho3D::Camera * c = node->CreateComponent < Urho3D::Camera>();
		c->SetFarClip(2000);
		return c; }
		break;
	case staticModel:
		return node->CreateComponent<Urho3D::StaticModel>();
		break;
	case animatedModel:
		return node->CreateComponent<Urho3D::AnimatedModel>();
		break;
	case skybox:
		return node->CreateComponent < Urho3D::Skybox>();
		break;
	case light: {
		Urho3D::Light* light = node->CreateComponent < Urho3D::Light>();
		light->SetLightType(Urho3D::LIGHT_POINT);
		light->SetRange(25);
		return light; }
		break;
	case terrain:
		return node->CreateComponent<Urho3D::Terrain>();
		break;
	case scriptInstance:
		return (void*)node->CreateComponent<Urho3D::ScriptInstance>();
		break;
	default:
		break;
	}
}

PB_FUNCTION(Urho3D::Node*) uh3_GetChildByName(Urho3D::Node* node, const unsigned short* name, int recursive) {
	return node->GetChild(Urho3D::String((const wchar_t*)name), recursive);
}

PB_FUNCTION(Urho3D::Node*) uh3_GetChildByID(Urho3D::Node* node, unsigned int id) {
	return node->GetChild(id);
}


PB_FUNCTION(void) uh3_SetNodePosition(Urho3D::Node* node, float x, float y, float z) {
	node->SetPosition(Urho3D::Vector3(x, y, z));
}

PB_FUNCTION(void) uh3_NodeTranslate(Urho3D::Node* node, float x, float y, float z, int mode) {
	node->Translate(Urho3D::Vector3(x, y, z), (Urho3D::TransformSpace)mode);
}


PB_FUNCTION(void) uh3_SetNodeRotation(Urho3D::Node* node, float x, float y, float z) {
	node->SetRotation(Urho3D::Quaternion(x, y, z));
}


PB_FUNCTION(void) uh3_NodeRotate(Urho3D::Node* node, float x, float y, float z, int mode) {
	node->Rotate(Urho3D::Quaternion(x,y,z), (Urho3D::TransformSpace)mode );
}
