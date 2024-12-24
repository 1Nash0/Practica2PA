#include "Player.h"
#include "Solid.h"
#include "Color.h"

void Player::Render()
{
    glPushMatrix();
    glColor4f(0.0f, 0.0f, 1.0f, 1.0f); // Cambiar color a azul
    glTranslatef(this->GetPosition().GetX(), this->GetPosition().GetY(), this->GetPosition().GetZ());
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f); // Rotar 90 grados para mirar a la derecha
    if (model3D) {
        model3D->Render();
    }
    else {
        // Si no hay modelo, dibuja una representación básica o lanza un error
        std::cout << "[Player] No model set for rendering!" << std::endl;
    }
    glPopMatrix();
}

//void SetModel3D(Model* model);



