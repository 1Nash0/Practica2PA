//#include "Menu.h"
//#include <time.h>
//
//
//void Menu::Init() {
//	camara2->SetPosition(Vector3D(0, 0, 0));
//	AddGameObject(camara2);
//	//TEXTO
//	Text* text = new Text();
//	text->SetPosition(Vector3D(this->camara2->GetCoordinates().GetCoordinateX() -
//		0.08, this->camara2->GetCoordinates().GetCoordinateY(),
//		this->camara2->GetCoordinates().GetCoordinateZ() - 1));
//	text->setTexto("INICIO");
//	text->SetColors(Color(0.8, 0.2, 0.6));
//	textos.push_back(text);
//	AddGameObject(text);
//	Text* textoNextScene = new Text();
//	textoNextScene->SetPosition(Vector3D(this->camara2->SetPosition().SetPositionX() - 0.3, this->camara2->SetPosition().SetPositionY() - 0.2,
//		this->camara2->SetPosition().SetPositionZ() - 1));
//	textoNextScene->setTexto("Presiona 'P' para iniciar el juego");
//	textoNextScene->SetColors(Color(0.8, 0.2, 0.6));
//	textos.push_back(textoNextScene);
//	AddGameObject(textoNextScene);
//}
//void Menu::SetCameraPosition(Vector3D position)
//{
//	this->camara2->SetCoordinates(position);
//}
//void Menu::ProcessKeyPressed(unsigned char key, int px, int py)
//{
//}
//void Menu::Update()
//{
//	float rSecret, gSecret, bSecret;
//	srand(time(NULL));
//	rSecret = (rand() % 10 + 1) * 0.10;
//	gSecret = (rand() % 10 + 1) * 0.10;
//	bSecret = (rand() % 10 + 1) * 0.10;
//	rSecret = (rand() % 10 + 1) * 0.10;
//	gSecret = (rand() % 10 + 1) * 0.10;
//	bSecret = (rand() % 10 + 1) * 0.10;
//}
