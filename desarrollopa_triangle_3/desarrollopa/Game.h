#pragma once
#include "Scene.h"
#include "Triangle.h"
#include "Model.h"
#include "ModelLoader.h"
#include "Player.h"
#include "Text.h"
#include "Emmiter.h"
#include "Menu.h"
#include "WinScene.h"
#include "DefeatScene.h"
#include "levelScene.h"
#include "Obstaculo.h"
#include "Recogible.h"
#include "Star.h"
#include <chrono>
#include <iostream>



using namespace std::chrono;

class Game
{
private:
	const double TIME_INCREMENT = 0.5;  // 50 ms por actualización, en el juego
	const long UPDATE_PERIOD = 5;  // 32 ms para la actualización en tiempo real


	milliseconds initialMilliseconds;
	long lastUpdateTime;

	vector<Solid*> gameObjects;

	Player* player1;
	Meteorite* meteorite1;
	Heart* heart1;
	Battery* battery1;
	Text* text1;
	Scene* activeScene;
	levelScene* gameScene;
	Menu* menuScene;
	WinScene* winScene;
	DefeatScene* defeatScene;
	vector<Scene*> scenes;

public:

	Game():activeScene(nullptr), player1(new Player()), heart1(nullptr), gameScene(nullptr), menuScene(nullptr),text1(nullptr), winScene(nullptr), defeatScene(nullptr), initialMilliseconds(duration_cast<milliseconds>(system_clock::now().time_since_epoch())), lastUpdateTime(0) {}
	
	void Init();
	void Render();
	void AddGameObject(Solid* object);
	void RestartGame();
	void Update(const float& time);
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClicked(int button, int state, int x, int y);
};

