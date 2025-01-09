#include "DefeatScene.h"
#include "Text.h"

void DefeatScene::Init() {
    // Configura la c�mara
    if (!camara) {
        camara = new Camera(); // Suponemos que Camera tiene un constructor por defecto
        camara->SetPosition(Vector3D(0, 0, 0)); // Establece una posici�n inicial
        AddGameObject(camara); // Registra la c�mara como un GameObject
    }

    // Texto del t�tulo del men�
    Text* titleText = new Text();
    titleText->SetPosition(Vector3D(7, 7, -1)); // Posici�n relativa
    titleText->SetText("DERROTA");
    titleText->SetColor(Color(1.0f, 0.0f, 5.0f, 1.0f));
    textos.push_back(titleText);
    AddGameObject(titleText);

    // Texto de instrucciones
    Text* instructionText = new Text();
    instructionText->SetPosition(Vector3D(3, -0.2, -1)); // Posici�n relativa
    instructionText->SetText("Presiona 'P' para reiniciar el juego");
    instructionText->SetColor(Color(1.0f, 0.0f, 0.0f, 1.0f));
    textos.push_back(instructionText);
    AddGameObject(instructionText);
}

void DefeatScene::SetCameraPosition(Vector3D position) {
    if (camara) {
        camara->SetPosition(position);
    }
}

