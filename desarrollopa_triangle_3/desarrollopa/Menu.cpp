#include "Menu.h"


void Menu::Init() {

    if (!camara) {
        camara = new Camera(); 
        camara->SetPosition(Vector3D(0, 0, 0)); 
        AddGameObject(camara); 
    }

    // Texto del título 
    Text* titleText = new Text();
    titleText->SetPosition(Vector3D(7, 7, 0)); 
    titleText->SetText("EMPTY SPACE");
    titleText->SetColor(Color(8.0f, 8.0f, 2.0f, 1.0f));
    textos.push_back(titleText);
    AddGameObject(titleText);

    // Texto de instrucciones
    Text* instructionText = new Text();
    instructionText->SetPosition(Vector3D(4, 3, 0)); 
    instructionText->SetText("Presiona la tecla 'P' para iniciar el juego");
    instructionText->SetColor(Color(8.0f, 0.0f, 0.0f, 1.0f)); 
    textos.push_back(instructionText);
    AddGameObject(instructionText);
}

void Menu::SetCameraPosition(Vector3D position) {
    if (camara) {
        camara->SetPosition(position);
    }
}




