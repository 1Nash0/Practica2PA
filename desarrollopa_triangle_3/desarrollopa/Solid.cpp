#include "Solid.h"
#include <cmath>


void Solid::Update( const float& time)
{
	this->SetPosition(this->GetPosition() + this->GetSpeed() * time);
	this->SetOrientation( this->GetOrientation() + this->GetOrientationSpeed() * time);

	/*if (this->GetIsAffectedByGravity())
	{
		this->SetSpeed(Vector3D(this->GetSpeed() + gravity * time));
	}*/
}

//bool Solid::CheckCollision(Solid* other) {
//	Vector3D diff = this->GetPosition() - other->GetPosition();
//	return diff.Length() < 0.5;
//}
bool Solid::CheckBoundingBoxCollision(const Solid* other) const {
    // Supongamos un tamaño de caja ajustado al radio de colisión
    float halfSizeA = this->GetCollisionRadius() / 2.0f;
    float halfSizeB = other->GetCollisionRadius() / 2.0f;

    Vector3D minA = this->GetPosition() - Vector3D(halfSizeA, halfSizeA, halfSizeA);
    Vector3D maxA = this->GetPosition() + Vector3D(halfSizeA, halfSizeA, halfSizeA);

    Vector3D minB = other->GetPosition() - Vector3D(halfSizeB, halfSizeB, halfSizeB);
    Vector3D maxB = other->GetPosition() + Vector3D(halfSizeB, halfSizeB, halfSizeB);

    // Comprobación de intersección en los ejes X, Y, y Z
    return (minA.GetX() <= maxB.GetX() && maxA.GetX() >= minB.GetX()) &&
        (minA.GetY() <= maxB.GetY() && maxA.GetY() >= minB.GetY()) &&
        (minA.GetZ() <= maxB.GetZ() && maxA.GetZ() >= minB.GetZ());
}

bool Solid::CheckCollision(const Solid* other) const {
    // Colisión basada en la distancia entre los centros y la suma de radios
    float distance = (this->GetPosition() - other->GetPosition()).Length();
    return distance <= (this->GetCollisionRadius() + other->GetCollisionRadius());
}