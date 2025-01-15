#include "Solid.h"


void Solid::Update( const float& time)
{
	this->SetPosition(this->GetPosition() + this->GetSpeed() * time);
	this->SetOrientation( this->GetOrientation() + this->GetOrientationSpeed() * time);

    if (isAffectedByGravity) {
        Vector3D currentSpeed = this->GetSpeed();
        this->SetSpeed(currentSpeed + gravity * time);
    }
}
bool Solid::CheckCollision(const Solid* other) const {
    if (other == nullptr) return false;
    float distance = (this->GetPosition() - other->GetPosition()).Length();

    float sumRadii = this->GetCollisionRadius() + other->GetCollisionRadius();

    return distance <= sumRadii;
}
void Solid::OnCollision(Solid* other) {}

void Solid::ProcessCollisions(const std::vector<Solid*>& objects) {
    for (Solid* other : objects) {
        if (other != this && CheckCollision(other)) {
            OnCollision(other); 
        }
    }
}

