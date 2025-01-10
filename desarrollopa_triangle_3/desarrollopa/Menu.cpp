#include "Menu.h"


void Menu::Init() {
    // Configura la c�mara
    if (!camara) {
        camara = new Camera(); //Suponemos que Camera tiene un constructor por defecto
        camara->SetPosition(Vector3D(0, 0, 0)); // Establece una posici�n inicial
        AddGameObject(camara); // Registra la c�mara como un GameObject
    }

    // Texto del t�tulo del men�
    Text* titleText = new Text();
    titleText->SetPosition(Vector3D(8, 7, 0)); // Posici�n relativa
    titleText->SetText("INICIO");
    titleText->SetColor(Color(8.0f, 8.0f, 2.0f, 1.0f));
    textos.push_back(titleText);
    AddGameObject(titleText);

    // Texto de instrucciones
    Text* instructionText = new Text();
    instructionText->SetPosition(Vector3D(4, 3, 0)); // Posici�n relativa
    instructionText->SetText("Presiona la tecla 'P' para iniciar el juego");
    instructionText->SetColor(Color(8.0f, 0.0f, 0.0f, 1.0f)); // Granate
    textos.push_back(instructionText);
    AddGameObject(instructionText);
}

void Menu::SetCameraPosition(Vector3D position) {
    if (camara) {
        camara->SetPosition(position);
    }
}




