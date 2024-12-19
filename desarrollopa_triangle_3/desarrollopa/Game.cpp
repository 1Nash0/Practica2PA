#include "Game.h"
#include <iostream>


void Game::Init()
{
	cout << "[GAME] Init..." << endl;
	Scene* scene1 = new Scene();
	Scene* scene2 = new Scene();


	Teapot* teapot1 = new Teapot();
	teapot1->SetPosition(Vector3D(4.0, 0.0,0.0));
	teapot1->SetColor(Color(0.2f, 0.4f, 0.6f, 1.0f));
	teapot1->SetOrientationSpeed(Vector3D(0.0, 2.0, 2.0));
	teapot1->SetSpeed(Vector3D(0.01, -0.02, 0.03));
	scene1->AddGameObject(teapot1);

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


	//Instanciamos un loader para leer el archivo obj
	ModelLoader* loader = new ModelLoader();
	//fijamos la escala a 2 para que el objeto sea de un tama�o mayor
	loader->SetScale(1.0);
	loader->LoadModel("..\\3dModels\\heart.obj");
	//una vez cargado el modelo, instanciamos un Model usando memoria din�mica
	Model* heart = new Model();
	//Asignamos el modelo del loader a lo apuntado por el puntero llamado bolt
	*heart = loader->GetModel();
	//lo colocamos m�s cerca del centro de la escena
	heart->SetPosition(Vector3D(4, 4, 0));
	//le damos velocidad de orientaci�n...
	heart->SetOrientationSpeed(Vector3D(0, 0.2, 0));

	heart->SetColor(Color(1.0, 0.0, 0.0, 1.0));

	//aqu� a�adimos el modelo a la escena
	scene2->AddGameObject(heart);

	//Sobre el resultado:
	// �por qu� no gira sobre s� mismo sino con un desplazamiento?
	// �qu� pasa con el color?

	this->scenes.push_back(scene1);
	this->scenes.push_back(scene2);
	this->activeScene = scene2;
}

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
}

void Game::ProcessMouseMovement(int x, int y)
{
	cout << "[GAME] Movement:" << x << ", " << y << endl;
}
