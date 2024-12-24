#pragma once
#include "Cube.h"
#include "Sphere.h"
#include "Display.h"
#include "Torus.h"
#include "Cylinder.h"
#include "Scene.h"
#include "Triangle.h"
#include "Model.h"
#include "ModelLoader.h"
#include "Player.h"
#include "Heart.h"
#include "Text.h"
#include "Emmiter.h"

using namespace std;

class Game
{
private:
	Player* player1; 
	vector<Scene*> scenes;
	Scene* activeScene;
	// en class game private
	//Model* player1;

public:

	Game():activeScene(nullptr), player1(nullptr) {}

	void Init();
	void Render();
	void Update();
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClicked(int button, int state, int x, int y);
};

