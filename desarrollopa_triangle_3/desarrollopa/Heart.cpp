#include "Heart.h"
#include <iostream>



// Constructor parametrizado
Heart::Heart(int inicialVidas) : vidas(inicialVidas) {}

// Getter para obtener el número de vidas
int Heart::getVidas() const {
    return vidas;
}

// Método para sumar vidas
void Heart::sumarVidas(int cantidad) {
    if (cantidad > 0) {
        vidas += cantidad;
    }
}

// Método para mostrar la cantidad de vidas
void Heart::mostrarVidas() const {
    std::cout << "Vidas: " << vidas << std::endl;
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

}

