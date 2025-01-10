#include "WinScene.h"
#include "Text.h"

void WinScene::Init() {
    // Configura la c�mara
    if (!camara) {
        camara = new Camera(); // Suponemos que Camera tiene un constructor por defecto
        camara->SetPosition(Vector3D(0, 0, 0)); // Establece una posici�n inicial
        AddGameObject(camara); // Registra la c�mara como un GameObject
    }

    // Texto del t�tulo del men�
    Text* titleText = new Text();
    titleText->SetPosition(Vector3D(8, 7, 0)); // Posici�n relativa
    titleText->SetText("VICTORIA");
    titleText->SetColor(Color(9.0f, 9.0f, 4.0f, 1.0f));
    textos.push_back(titleText);
    AddGameObject(titleText);

    // Texto de instrucciones
    Text* instructionText = new Text();
    instructionText->SetPosition(Vector3D(4, 3, 0)); // Posici�n relativa
    instructionText->SetText("Presiona la tecla 'P' para reiniciar el juego");
    instructionText->SetColor(Color(8.0f, 0.0f, 0.0f, 1.0f)); // Granate
    textos.push_back(instructionText);
    AddGameObject(instructionText);
}

void WinScene::SetCameraPosition(Vector3D position) {
    if (camara) {
        camara->SetPosition(position);
    }
}