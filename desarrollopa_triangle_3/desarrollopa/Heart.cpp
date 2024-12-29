#include "Heart.h"
#include <iostream>
#include "Solid.h"
#include "Color.h"





//bool CheckCollision(const Solid& other)  {
//    // Lógica específica para la colisión con corazones
//    return false; // Ejemplo
//}

//bool Heart::getIsVisible() const {
//    return isVisible;
//}

//void Heart::setIsVisible(bool visible) {
//    isVisible = visible;
//}

//void Heart::HandleCollision() {
//    if (isVisible) {
//        isVisible = false;
//        std::cout << "El jugador ha recogido el corazón. Ahora es invisible." << std::endl;
//    }
//}

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
            glColor3f(1.0f, 0.0f, 0.0f); // Color rojo
            glutSolidSphere(size, 50, 50); // Esfera como placeholder
        }
    }
    glPopMatrix();


}
bool Heart::CheckCollision(const Solid& other) {
    // Verifica que el objeto no sea nulo
    if (&other == nullptr) return false; 

    // Calcula la distancia entre el centro del corazón y el otro objeto
    Vector3D otherPosition = other.GetPosition();
    float dx = this->GetPosition().GetX() - otherPosition.GetX();
    float dy = this->GetPosition().GetY() - otherPosition.GetY();
    float dz = this->GetPosition().GetZ() - otherPosition.GetZ();

    float distanceSquared = dx * dx + dy * dy + dz * dz;

    // Compara con el radio de colisión combinado
    float combinedRadius = this->GetCollisionRadius() + other.GetCollisionRadius();
    return distanceSquared <= (combinedRadius * combinedRadius);
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





