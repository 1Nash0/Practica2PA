#include "Solid.h"

void Solid::Update()
{
	this->position = this->position + this->speed;
	this->orientation = this->orientation + this->orientationSpeed;
}
