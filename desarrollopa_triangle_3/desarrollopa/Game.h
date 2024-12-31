#pragma once
#include "Cube.h"
#include "Sphere.h"
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
#include "Meteorite.h"
#include "Satellite.h"
#include "Menu.h"
#include "Battery.h"
#include "Star.h"
#include <chrono>

using namespace std::chrono;

class Game
{
private:
	const double TIME_INCREMENT = 1.0; //ms tiempo en el juego
	const long UPDATE_PERIOD = 10.0;  //ms timepo real en la partida

	milliseconds initialMilliseconds;
	long lastUpdateTime;

	vector<Solid*> gameObjects;

	Player* player1;
	Meteorite* meteorite1;
	Heart* heart1;
	Text* text1;
	Scene* activeScene;
	Menu* menuScene;
	vector<Scene*> scenes;

public:

	Game():activeScene(nullptr), player1(new Player()), heart1(nullptr), menuScene(nullptr),text1(nullptr), initialMilliseconds(duration_cast<milliseconds>(system_clock::now().time_since_epoch())), lastUpdateTime(0) {}
	
	void Init();
	void Render();
	void OnCollision(Solid* a, Solid* b);
	void AddGameObject(Solid* object);
	void Update(const float& time);
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClicked(int button, int state, int x, int y);
};

