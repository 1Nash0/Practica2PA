#include "Heart.h"
#include <iostream>
#include "Solid.h"
#include "Color.h"

bool Heart::getIsVisible() const {
    return isVisible;
}

void Heart::setIsVisible(bool visible) {
    isVisible = visible;
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

    if (isVisible) {
        if (model3D) {
            model3D->Render(); // Renderizar modelo 3D
        }
        else {
            glColor3f(1.0f, 1.0f, 0.0f); // Color rojo
            glutSolidSphere(size, 50, 50); // Esfera como placeholder
        }
    }
    glPopMatrix();
}

bool Heart::CheckCollision(Solid* other) {
    if (other == nullptr) { // Validar puntero nulo
        return false;
    }
    return Solid::CheckCollision(other); // Usar el m�todo base
    if (Solid::CheckCollision(other)) { // Verificar la colisi�n usando el m�todo base
        // Verificar si el objeto con el que ha colisionado es un jugador
        if (other->GetType() == "Player") {
            setIsVisible(false); // Hacer invisible el coraz�n
            std::cout << "El coraz�n ha sido recogido por el jugador." << std::endl;
            return true;
        }
    }
    return false;
}

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
