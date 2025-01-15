#pragma once
#include "Solid.h"
#include "Model.h"


class Resource : public Solid
{
private:
	float size;
	float point;
	Model* model3D;
public:

	Resource() : model3D(nullptr), point(1.0) {

		this->SetSize(1.0);
		this->SetAffectedByGravity(true);
		this->SetCollisionRadius(0.7f);
		this->SetSpeed(Vector3D(-0.01, 0.0f, 0.0f));
		this->SetOrientationSpeed(Vector3D(0.0, 2.0, 0.0));

	}

	void SetModel3D(Model* model);
	inline float GetPoint() const { return this->point; }

	inline float GetSize() const { return this->size; }
	void SetSize(float sizeToSet) { this->size = sizeToSet; }

	bool CheckCollision(Solid* other);
};

