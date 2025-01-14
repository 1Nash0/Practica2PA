#pragma once
#include "Solid.h"
#include "Model.h"


class Recogible : public Solid
{
private:
	float size;
	Model* model3D;
public:

	Recogible() : model3D(nullptr) {

		this->SetSize(1.0);
		this->SetAffectedByGravity(true);
		this->SetCollisionRadius(0.7f);
		this->SetSpeed(Vector3D(-0.01, 0.0f, 0.0f));
		this->SetOrientationSpeed(Vector3D(0.0, 1.0, 0.0));

	}

	void SetModel3D(Model* model);

	inline float GetSize() const { return this->size; }
	void SetSize(float sizeToSet) { this->size = sizeToSet; }

	bool CheckCollision(Solid* other);
};

