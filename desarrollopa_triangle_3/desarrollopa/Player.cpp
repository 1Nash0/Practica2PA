#include "Player.h"
#include "Solid.h"

void Player::Render()
{

	glPushMatrix();
	glColor4f(this->GetColor().GetRed(), this->GetColor().GetGreen(), this->GetColor().GetBlue(), this->GetColor().GetAlpha());

    glTranslatef(this->GetPosition().GetX(), this->GetPosition().GetY(), this->GetPosition().GetZ());
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



