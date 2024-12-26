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

	cout << "[GAME] Init..." << endl;
	Scene* scene1 = new Scene();
	Scene* scene2 = new Scene();

	// Configuramos el emisor
	int numParticulas = 1000;
	int tiempoEmision = 10;
	Solid* particulaRef = new Cube();


	EmmiterConfiguration Config(numParticulas, tiempoEmision, particulaRef);
	Emmiter* emisor = new Emmiter(Config);
	scene1->AddGameObject(emisor);

	Cube* cube1 = new Cube();
	cube1->SetPosition(Vector3D(3.0, 2.0, 0.0));
	cube1->SetColor(Color(0.8f, 0.7f, 0.6f, 0.4f));
	cube1->SetOrientationSpeed(Vector3D(1.0, 0.0, 3.0));
	cube1->SetSpeed(Vector3D(0.01, 0.02, 0.01));
	scene1->AddGameObject(cube1);

	Sphere* sphere1 = new Sphere();
	sphere1->SetPosition(Vector3D(0.0, 4.0, 0.0));
	sphere1->SetColor(Color(0.4f, 0.4f, 0.9f, 0.8f));
	sphere1->SetSpeed(Vector3D(0.01, 0.01, 0.01));
	scene1->AddGameObject(sphere1);

	Torus* torus1 = new Torus();
	torus1->SetPosition(Vector3D(1.0, 2.0, 0.0));
	torus1->SetOrientationSpeed(Vector3D(0.0, 1.0, 0.0));
	scene2->AddGameObject(torus1);

	Cylinder* cylinder1 = new Cylinder();
	cylinder1->SetPosition(Vector3D(7.0, 1.0, 0.0));
	cylinder1->SetOrientation(Vector3D(90.0, 0.0, 0.0));
	cylinder1->SetColor(Color(0.6f, 0.1f, 0.7f, 1.0f));
	scene1->AddGameObject(cylinder1);

	Player* player1 = new Player(); 
	player1->SetPosition(Vector3D(3.0, 2.0, -1.0));
	player1->SetOrientationSpeed(Vector3D(0.0, 0.0, 0.1));
	scene2->AddGameObject(player1);

	Text* text1 = new Text();
	text1->SetText("Nas > 2024");
	text1->SetPosition(Vector3D(5.0, 5.0, -6.0));
	text1->SetColor(Color(1.0f, 0.0f, 0.0f, 1.0f));
	scene2->AddGameObject(text1);

	Heart* heart1 = new Heart();
	heart1->SetPosition(Vector3D(2.0, 5.0, 0.0));
	heart1->SetOrientationSpeed(Vector3D(0.0, 1.0, 0.0));
	scene2->AddGameObject(heart1);

	Heart* heart2 = new Heart();
	heart2->SetPosition(Vector3D(3.0, 5.0, 0.0));
	heart2->SetOrientationSpeed(Vector3D(0.0, 1.0, 0.0));
	scene2->AddGameObject(heart2);

	Meteorite* Meteorite1 = new Meteorite();
	Meteorite1->SetPosition(Vector3D(7.0, 2.0, 0.0));
	Meteorite1->SetOrientationSpeed(Vector3D(1.0, 0.0, 3.0));
	Meteorite1->SetSpeed(Vector3D(0.01, 0.02, 0.01));
	scene2->AddGameObject(Meteorite1);

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
	playerModel->SetColor(Color(1.0f, 0.0f, 0.0f, 1.0f)); // Cambia a rojo // Asegúrate de incluir el valor alfa

	ModelLoader* loader2 = new ModelLoader();
	loader2->SetScale(0.5f);
	loader2->LoadModel("..\\3dModels\\heart.obj");
	Model* heartModel = new Model();
	Model* heartModel2 = new Model();
	*heartModel = loader2->GetModel();
	*heartModel2 = loader2->GetModel();
	heart1->SetModel3D(heartModel);
	heart2->SetModel3D(heartModel);
	heartModel->SetSpeed(Vector3D(0.0, 0.0, 0.0));
	heartModel->SetColor(Color(1.0, 0.0, 0.0, 1.0));



	ModelLoader* loader3 = new ModelLoader();
	loader3->SetScale(0.5f);
	loader3->LoadModel("..\\3dModels\\Cop_v1.obj");
	Model* meteoriteModel = new Model();
	*meteoriteModel = loader3->GetModel();
	Meteorite1->SetModel3D(meteoriteModel);
	meteoriteModel->SetSpeed(Vector3D(0.0, 0.0, 0.0));
	meteoriteModel->SetColor(Color(1.0, 1.0, 1.0, 1.0));
	//Sobre el resultado:
	// �por qu� no gira sobre s� mismo sino con un desplazamiento?
	// �qu� pasa con el color?

	this->scenes.push_back(scene1);
	this->scenes.push_back(scene2);
	this->activeScene = scene2;
}


//
//bool CheckCollision(float playerX, float playerY, float playerZ, float heartX, float heartY, float heartZ, float radius) {
//	float distanceSquared = (playerX - heartX) * (playerX - heartX) +
//		(playerY - heartY) * (playerY - heartY) +
//		(playerZ - heartZ) * (playerZ - heartZ);
//	return distanceSquared <= radius * radius;
//}

//void UpdateGame(Player& player, std::vector<Heart>& hearts) {
//	for (Heart& heart : hearts) {
//		if (CheckCollision(player.getX(), player.getY(), player.getZ(),
//			heart.getX(), heart.getY(), heart.getZ(), 1.0f)) {
//			heart.HandleCollision();
//		}
//	}
//}
//
//
//
//}

void Game::Render()
{
	this->activeScene->Render();
}

void Game::Update()
{
	//cout << "[GAME] Update..." << endl;
	this->activeScene->Update();
}


void Game::ProcessKeyPressed(unsigned char key, int px, int py)
{
	cout << "tecla pulsada: " << key << endl;

	int index = (key - '0') - 1;
	if (index < this->scenes.size())
	{
		this->activeScene = this->scenes[index];
	}
	
}

void Game::ProcessMouseClicked(int button, int state, int x, int y)
{
	cout << "[GAME] Click:" << button << endl;

	if (button == 0 && player1 != nullptr) {
		player1->Shoot();
	}
	else if (button == 2 && player1 != nullptr)
	{
		player1->LaunchBomb();
	}
}


void Game::ProcessMouseMovement(int x, int y)
{
	cout << "[GAME] Movement:" << x << ", " << y << endl;
}
