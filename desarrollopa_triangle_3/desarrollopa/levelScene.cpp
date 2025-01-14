#include "levelScene.h"


void levelScene::Render() {


	glPushMatrix();
    texto1.SetText("Vidas: /5");
    texto1.SetPosition(Vector3D(1.0f, 10.0f, 0.0f));
    texto1.SetColor(Color(1.0f, 0.0f, 0.0f, 1.0f));
    texto1.Render();
}




