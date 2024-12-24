#include "Solid.h"

void Solid::Update()
{
	this->position = this->position + this->velocity;
	this->orientation = this->orientation + this->orientationSpeed;
}
