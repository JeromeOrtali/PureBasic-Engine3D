class Flicker : ScriptObject{
	
	float range;

	void update(float timestep){
		node.GetComponent("Light").SetRange(0);
	}

}