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
	player1->SetPosition(Vector3D(3.0, 2.0, 0.0));
	player1->SetOrientationSpeed(Vector3D(0.0, 0.0, 0.1));
	scene2->AddGameObject(player1);
	

	Text* text1 = new Text();
	text1->SetText("Nas > 2024");
	text1->SetPosition(Vector3D(-15.0, 15.0, -6.0));
	text1->SetColor(Color(1.0f, 0.0f, 0.0f, 1.0f));
	scene2->AddGameObject(text1);

	Heart* heart1 = new Heart();
	heart1->SetCollisionRadius(0.4f);
	heart1->SetPosition(Vector3D(2.0, 5.0, 0.0));
	heart1->SetOrientationSpeed(Vector3D(0.0, 1.0, 0.0));
	scene2->AddGameObject(heart1);

	Heart* heart2 = new Heart();
	heart2->SetPosition(Vector3D(9.0, 5.0, 0.0));
	heart2->SetCollisionRadius(0.4f);
	heart2->SetOrientationSpeed(Vector3D(0.0, 1.0, 0.0));
	scene2->AddGameObject(heart2);

	Heart* heart3 = new Heart();
	heart3->SetPosition(Vector3D(4.0, 5.0, 0.0));
	heart3->SetCollisionRadius(0.4f);
	heart3->SetOrientationSpeed(Vector3D(0.0, 1.0, 0.0));
	scene2->AddGameObject(heart3);

	Meteorite* Meteorite1 = new Meteorite();
	Meteorite1->SetPosition(Vector3D(7.0, 2.0, 0.0));
	Meteorite1->SetCollisionRadius(1.0f);
	Meteorite1->SetOrientationSpeed(Vector3D(1.0, 0.0, 0.0));
	Meteorite1->SetSpeed(Vector3D(0.0, 0.0, 0.0));
	scene2->AddGameObject(Meteorite1);

	Meteorite* Meteorite2 = new Meteorite();
	Meteorite2->SetPosition(Vector3D(9.0, 4.0, 0.0));
	Meteorite2->SetCollisionRadius(1.0f);

	Meteorite2->SetOrientationSpeed(Vector3D(1.0, 0.0, 0.0));
	Meteorite2->SetSpeed(Vector3D(0.0, 0.0, 0.0));
	scene2->AddGameObject(Meteorite2);

	Satellite* Satellite1 = new Satellite();
	Satellite1->SetPosition(Vector3D(15.0, 4.0, 0.0));
	Satellite1->SetOrientationSpeed(Vector3D(1.0, 0.0, 0.0));
	Satellite1->SetSpeed(Vector3D(0.0, 0.0, 0.0));
	scene2->AddGameObject(Satellite1);

	Battery* Battery1 = new Battery();
	Battery1->SetPosition(Vector3D(9.0, 6.0, 0.0));
	Battery1->SetCollisionRadius(0.7f);
	Battery1->SetOrientationSpeed(Vector3D(0.0, 1.0, 0.0));
	Battery1->SetSpeed(Vector3D(0.0, 0.0, 0.0));
	scene2->AddGameObject(Battery1);

	//Instanciamos un loader para leer el archivo obj
	//ModelLoader* loader = new ModelLoader();
	////fijamos la escala a 2 para que el objeto sea de un tama�o mayor
	//loader->SetScale(1.0);
	//loader->LoadModel("..\\3dModels\\heart.obj");
	////una vez cargado el modelo, instanciamos un Model usando memoria din�mica
	//Model* heart = new Model();
	////Asignamos el modelo del loader a lo apuntado por el puntero llamado bolt
	//*heart = loader->GetModel();
	////lo colocamos m�s cerca del centro de la escena
	//heart->SetPosition(Vector3D(4, 4, 0));
	////le damos velocidad de orientaci�n...
	//heart->SetOrientationSpeed(Vector3D(0, 0.2, 0));

	//heart->SetColor(Color(1.0, 0.0, 0.0, 1.0));

	////aqu� a�adimos el modelo a la escena
	//scene2->AddGameObject(heart);

	ModelLoader* loader = new ModelLoader();
	loader->SetScale(0.8f);
	loader->LoadModel("..\\3dModels\\Spaceship4.obj");
	Model* playerModel = new Model();
	*playerModel = loader->GetModel();
	player1->SetModel3D(playerModel);
	playerModel->SetSpeed(Vector3D(0.0, 0.0, 0.0));
	playerModel->SetColor(Color(1.0f, 0.0f, 0.0f, 1.0f)); 

	ModelLoader* loader2 = new ModelLoader();
	loader2->SetScale(0.5f);
	loader2->LoadModel("..\\3dModels\\heart.obj");
	Model* heartModel = new Model();
	Model* heartModel2 = new Model();
	Model* heartModel3 = new Model();
	*heartModel = loader2->GetModel();
	*heartModel2 = loader2->GetModel();
	*heartModel3 = loader2->GetModel();
	heart1->SetModel3D(heartModel);
	heart2->SetModel3D(heartModel2);
	heart3->SetModel3D(heartModel3);
	heartModel->SetSpeed(Vector3D(0.0, 0.0, 0.0));
	heartModel->SetColor(Color(1.0, 0.0, 0.0, 1.0));
	heartModel2->SetColor(Color(1.0, 1.0, 1.0, 1.0));
	heartModel3->SetColor(Color(1.0, 0.0, 0.8, 1.0));


	ModelLoader* loader3 = new ModelLoader();
	loader3->SetScale(0.5f);
	loader3->LoadModel("..\\3dModels\\rock_001.obj");
	Model* meteoriteModel = new Model();
	*meteoriteModel = loader3->GetModel();
	Meteorite1->SetModel3D(meteoriteModel);
	meteoriteModel->SetSpeed(Vector3D(0.0, 0.0, 0.0));
	meteoriteModel->SetColor(Color(1.0, 1.0, 1.0, 1.0));
	Meteorite2->SetModel3D(meteoriteModel);
	


	ModelLoader* loader5 = new ModelLoader();
	loader5->SetScale(0.04f);
	loader5->LoadModel("..\\3dModels\\Lowamogus.obj");
	Model* satelliteModel = new Model();
	*satelliteModel = loader5->GetModel();
	Satellite1->SetModel3D(satelliteModel);
	satelliteModel->SetSpeed(Vector3D(0.0, 0.0, 0.0));
	satelliteModel->SetColor(Color(1.0f, 0.0f, 0.0f, 1.0f));

	ModelLoader* loader6 = new ModelLoader();
	loader6->SetScale(1.0f);
	loader6->LoadModel("..\\3dModels\\Bolt.obj");
	Model* baterryModel = new Model();
	*baterryModel = loader6->GetModel();
	Battery1->SetModel3D(baterryModel);
	baterryModel->SetSpeed(Vector3D(0.0, 0.0, 0.0));
	baterryModel->SetColor(Color(1.0f, 1.0f, 0.0f, 1.0f));

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


	AddGameObject(player1);
	AddGameObject(heart1);
	AddGameObject(heart2);
	AddGameObject(heart3);
	AddGameObject(Meteorite1);
	AddGameObject(Meteorite2);
	AddGameObject(Battery1);
	//Sobre el resultado:
	// �por qu� no gira sobre s� mismo sino con un desplazamiento?
	// �qu� pasa con el color?

	this->scenes.push_back(scene1);
	this->scenes.push_back(scene2);
	this->activeScene = menuScene;


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
		if (object) {
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
