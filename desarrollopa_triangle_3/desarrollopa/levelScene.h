#pragma once
#include "Scene.h"

class levelScene : public Scene
{
private:

	Vector3D gravity;

public:

	inline Vector3D GetGravity() { return this->gravity; }
	void SetGravity(Vector3D gravityToSet) { this->gravity = gravityToSet; }

};

