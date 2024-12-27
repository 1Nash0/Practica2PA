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
