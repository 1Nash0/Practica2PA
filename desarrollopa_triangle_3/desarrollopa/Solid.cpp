#include "Solid.h"
#include <cmath>


void Solid::Update( const float& deltaTime)
{
	this->SetPosition(this->GetPosition() + this->GetSpeed() * deltaTime);
	this->SetOrientation( this->GetOrientation() + this->GetOrientationSpeed() * deltaTime);

    if (isAffectedByGravity) {
        Vector3D currentSpeed = this->GetSpeed();
        this->SetSpeed(currentSpeed + gravity * deltaTime);
    }
}


void Solid::ProcessCollisions(const std::vector<Solid*>& objects) {
    for (Solid* other : objects) {
        if (other != this && CheckCollision(other)) {
            OnCollision(other); // Llama al manejo de colisión
        }
    }
}
void Solid::SetAffectedByGravity(bool affected) {
    isAffectedByGravity = affected;
}

bool Solid::GetIsAffectedByGravity() const {
    return isAffectedByGravity;
}
void Solid::OnCollision(Solid* other) {
    
}

bool Solid::CheckCollision(const Solid* other) const {
    if (other == nullptr) return false;

    // Distancia entre los centros de los objetos
    float distance = (this->GetPosition() - other->GetPosition()).Length();

    // Suma de los radios de colisión
    float sumRadii = this->GetCollisionRadius() + other->GetCollisionRadius();

    // Verifica si las esferas de colisión están superpuestas
    return distance <= sumRadii;
}
