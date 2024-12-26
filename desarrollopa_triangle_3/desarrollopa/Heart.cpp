#include "Heart.h"
#include <iostream>



#include "Heart.h"
#include <iostream>




int Heart::getVidas() const {
    return vidas;
}

void Heart::sumarVidas(int cantidad) {
    vidas += cantidad;
}

void Heart::mostrarVidas() const {
    std::cout << "Vidas: " << vidas << std::endl;
}

void Heart::SetModel3D(Model* model) {
    if (model) {
        model3D = model;
    }
    else {
        std::cerr << "[Heart::SetModel3D] Modelo nulo pasado como argumento." << std::endl;
    }
}

Solid* Heart::Clone() const {
    return new Heart(*this);
}

//bool Heart::getIsVisible() const {
//    return isVisible;
//}

//void Heart::setIsVisible(bool visible) {
//    isVisible = visible;
//}

void Heart::HandleCollision() {
    if (isVisible) {
        isVisible = false;
        std::cout << "El jugador ha recogido el corazón. Ahora es invisible." << std::endl;
    }
}

void Heart::Render()
{
    glPushMatrix();
    glTranslatef(this->GetPosition().GetX(), this->GetPosition().GetY(),
        this->GetPosition().GetZ());
    glColor4f(this->GetColor().GetRed(),
        this->GetColor().GetGreen(),
        this->GetColor().GetBlue(),
        this->GetColor().GetAlpha());
    glRotatef(this->GetOrientation().GetX(), 1.0, 0.0, 0.0);
    glRotatef(this->GetOrientation().GetY(), 0.0, 1.0, 0.0);
    glRotatef(this->GetOrientation().GetZ(), 0.0, 0.0, 1.0);

    if (model3D) {
        model3D->Render();
    }
    else {
        // Si no hay modelo, dibuja una representación básica o lanza un error
        std::cout << "[Player] No model set for rendering!" << std::endl;
    }
    glPopMatrix();

    if (isVisible) {
        if (model3D) {
            model3D->Render(); // Renderizar modelo 3D
        }
        else {
            glColor3f(1.0f, 0.0f, 0.0f); // Color rojo
            glutSolidSphere(size, 50, 50); // Esfera como placeholder
        }
    }


}





