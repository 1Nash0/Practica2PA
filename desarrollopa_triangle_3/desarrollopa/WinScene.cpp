#include "WinScene.h"


void WinScene::Init() {
    if (!camara) {
        camara = new Camera(); 
        camara->SetPosition(Vector3D(0, 0, 0)); 
        AddGameObject(camara); 
    }

    Text* titleText = new Text();
    titleText->SetPosition(Vector3D(8, 7, 0)); 
    titleText->SetText("VICTORIA");
    titleText->SetColor(Color(9.0f, 9.0f, 4.0f, 1.0f));
    textos.push_back(titleText);
    AddGameObject(titleText);

    Text* instructionText = new Text();
    instructionText->SetPosition(Vector3D(4, 3, 0)); 
    instructionText->SetText("Presiona la tecla 'P' para reiniciar el juego");
    instructionText->SetColor(Color(8.0f, 0.0f, 0.0f, 1.0f)); 
    textos.push_back(instructionText);
    AddGameObject(instructionText);
}

void WinScene::SetCameraPosition(Vector3D position) {
    if (camara) {
        camara->SetPosition(position);
    }
}