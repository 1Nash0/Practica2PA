#pragma once
#include "Scene.h"
#include "Player.h"
#include "Text.h"
#include <string>
#include "Solid.h"
#include <GL/glut.h>


using namespace std;

class levelScene : public Scene
{
private:

	Player* player;
	Vector3D gravity;
	Text texto1;

public:

	levelScene() : player(nullptr) {}

	inline Vector3D GetGravity() { return this->gravity; }
	void SetGravity(Vector3D gravityToSet) { this->gravity = gravityToSet; }




};

