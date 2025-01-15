#pragma once
#include "Solid.h"
#include "Model.h"


class Obstacle : public Solid
{
private:

	float size;
	Model* model3D;

public:

	Obstacle() : model3D(nullptr)  {
		this->size = 1.0;
		this->SetAffectedByGravity(true); // Habilitar gravedad para meteoritos
		this->SetCollisionRadius(1.0f);   // Define un radio de colisión si es necesario
		this->SetSpeed(Vector3D(-0.01, 0.0f, 0.0f));
		this->SetOrientationSpeed(Vector3D(rand() % 10 - 9, rand() % 10 - 9, 0.0));
	}

	inline float GetSize() const { return this->size; }
	void SetSize(float sizeToSet) { this->size = sizeToSet; }

	void SetModel3D(Model* model);

	bool CheckCollision(Solid* other);

};

