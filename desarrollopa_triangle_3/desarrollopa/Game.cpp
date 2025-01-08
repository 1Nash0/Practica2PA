#include "Game.h"
#include "Emmiter.h"
#include "EmmiterConfiguration.h"
#include "Heart.h"
#include "Player.h"
#include <vector>
#include <iostream>
#include <ctime> 


void Game::Init()
{

	menuScene = new Menu();
	menuScene->Init();

	activeScene = menuScene;

	cout << "[GAME] Init..." << endl;
	Scene* scene1 = new Scene();
	Scene* scene2 = new Scene();

	

	// Configuramos el emisor
	int numParticulas = 1000;
	int tiempoEmision = 10;
	Solid* particulaRef = new Cube();

	

	Player* player1 = new Player(); 
	player1->SetCollisionRadius(0.8f);
	player1->SetPosition(Vector3D(5.0, 5.0, 0.0));
	player1->SetOrientationSpeed(Vector3D(0.0, 0.0, 0.1));
	scene2->AddGameObject(player1);
	

	Text* text1 = new Text();
	text1->SetText("Nas > 2024");
	text1->SetPosition(Vector3D(-15.0, 15.0, -6.0));
	text1->SetColor(Color(1.0f, 0.0f, 0.0f, 1.0f));
	scene2->AddGameObject(text1);

	ModelLoader* loader = new ModelLoader();
	loader->SetScale(0.8f);
	loader->LoadModel("..\\3dModels\\Spaceship4.obj");
	Model* playerModel = new Model();
	*playerModel = loader->GetModel();
	player1->SetModel3D(playerModel);
	playerModel->SetSpeed(Vector3D(0.0, 0.0, 0.0));
	playerModel->SetColor(Color(1.0f, 0.0f, 0.0f, 1.0f)); 

	for (int i = 1; i < 20; i++) {

		Battery* battery1 = new Battery();
		battery1->SetPosition(Vector3D(9.0 * 3 * i, (rand() % 12), 0.0));
		scene2->AddGameObject(battery1);
		ModelLoader* loader6 = new ModelLoader();
		loader6->SetScale(1.0f);
		loader6->LoadModel("..\\3dModels\\Bolt.obj");
		Model* baterryModel = new Model();
		*baterryModel = loader6->GetModel();
		baterryModel->SetColor(Color(1.0f, 1.0f, 0.0f, 1.0f));
		battery1->SetModel3D(baterryModel);
		AddGameObject(battery1);
		delete loader6;
	}
	

	for (int i = 1; i < 20; i++) {
		Heart* heart1 = new Heart();
		heart1->SetPosition(Vector3D(9.0 * 2*i, (rand() % 12), 0.0));
		scene2->AddGameObject(heart1);
		ModelLoader* loader2 = new ModelLoader();
		loader2->SetScale(0.5f);
		loader2->LoadModel("..\\3dModels\\heart.obj");
		Model* heartModel = new Model();
		*heartModel = loader2->GetModel();
		heartModel->SetColor(Color(1.0, 0.0, 0.0, 1.0));
		heart1->SetModel3D(heartModel);
		AddGameObject(heart1);
		delete loader2;
	}
for (int i = 1; i < 100; i++) {

    Meteorite* Meteorite1 = new Meteorite();
    Meteorite1->SetPosition(Vector3D(9.0 * i, (rand() % 12), 0.0));
    scene2->AddGameObject(Meteorite1);
    ModelLoader* loader3 = new ModelLoader();
    loader3->SetScale(0.5f);
    loader3->LoadModel("..\\3dModels\\rock_001.obj");
    Model* meteoriteModel = new Model();
    *meteoriteModel = loader3->GetModel();
    meteoriteModel->SetColor(Color(1.0, 1.0, 1.0, 1.0));
    Meteorite1->SetModel3D(meteoriteModel);
    AddGameObject(Meteorite1);
    delete loader3;
}


	

	Star* star1 = new Star();
	ModelLoader* loader7 = new ModelLoader();
	loader7->SetScale(0.5f);
	loader7->LoadModel("..\\3dModels\\star.obj");
	Model* starModel = new Model();
	*starModel = loader7->GetModel();
	star1->SetModel3D(starModel);
	starModel->SetSpeed(Vector3D(0.0, 0.0, 0.0));
	starModel->SetColor(Color(0.9f, 0.9f, 0.0f, 1.0f));


	
	EmmiterConfiguration Config(numParticulas, tiempoEmision, starModel);
	Emmiter* emisor = new Emmiter(Config);
	menuScene->AddGameObject(emisor);
	scene1->AddGameObject(emisor);
	//EmmiterConfiguration Config2(numParticulas, tiempoEmision, meteoriteModel);
	//Emmiter* emisor2 = new Emmiter(Config2);



	AddGameObject(player1);

	//Sobre el resultado:
	// �por qu� no gira sobre s� mismo sino con un desplazamiento?
	// �qu� pasa con el color?

	this->scenes.push_back(scene1);
	this->scenes.push_back(scene2);
	this->activeScene = menuScene;
	scene2->SetPlayer(player1);

}



void Game::Render()
{
	if (activeScene) {
		activeScene->Render();  // Renderiza la escena activa (ya sea el menú o la escena 2)
	}

}

void Game::Update(const float& time) {
	// Actualizar el tiempo
	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

	if ((currentTime.count() - this->initialMilliseconds.count()) - this->lastUpdateTime > UPDATE_PERIOD) {
		if (activeScene) {
			activeScene->Update(TIME_INCREMENT);
		}
		this->lastUpdateTime = currentTime.count() - this->initialMilliseconds.count();
	}

	// Actualizar todos los objetos
	for (auto* object : gameObjects) {
		if (object && !object->IsMarkedForDeletion()) {
			object->Update(time);
		}
	}

	// Procesar colisiones delegando la responsabilidad a cada objeto
	for (auto* object : gameObjects) {
		if (object) {
			object->ProcessCollisions(gameObjects); // Cada objeto revisa sus colisiones
		}
	}

	// Eliminar objetos marcados para eliminación
	for (auto it = gameObjects.begin(); it != gameObjects.end(); ) {
		if ((*it)->IsMarkedForDeletion()) {
			delete* it; // Libera memoria
			it = gameObjects.erase(it); // Elimina el puntero de la lista
		}
		else {
			++it;
		}
	}
}



	void Game::AddGameObject(Solid * object) {
		gameObjects.push_back(object);
	}

void Game::ProcessKeyPressed(unsigned char key, int px, int py)
{
	cout << "tecla pulsada: " << key << endl;

	int index = (key - '0') - 1;
	if (index < this->scenes.size())
	{
		this->activeScene = this->scenes[index];
	}
	cout << "tecla pulsada: " << key << endl;

	if (activeScene) {
		activeScene->ProcessKeyPressed(key, px, py);

		// Cambiar de la escena del menú a la escena 2 al presionar 'P'
		if (activeScene == menuScene && (key == 'P' || key == 'p')) {
			std::cout << "Iniciando el juego jeje..." << std::endl;
			activeScene = scenes[1];  // Cambia a la escena 2
		}
	}
	
}

void Game::ProcessMouseClicked(int button, int state, int x, int y)
{
	cout << "[GAME] Click:" << button << endl;

	
}


void Game::ProcessMouseMovement(int x, int y)
{
	cout << "[GAME] Movement:" << x << ", " << y << endl;
}
