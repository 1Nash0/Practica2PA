#pragma once
#include <GL/glut.h>
#include "Model.h"
#include "Solid.h"

class Battery : public Solid
{
private:

	float size;
	Model* model3D;

public:
	/*bool CheckCollision(const Solid& other);*/

	Battery() : model3D(nullptr), Solid()
	{
		this->SetSize(1.0);
		this->SetAffectedByGravity(true);
		this->SetCollisionRadius(0.7f);
		this->SetSpeed(Vector3D(-0.01, 0.0f, 0.0f));
		this->SetOrientationSpeed(Vector3D(0.0, 1.0, 0.0));
	}

	inline float GetSize() const { return this->size; }
	void SetSize(float sizeToSet) { this->size = sizeToSet; }
	string GetType() const override { return "Battery"; }

	void SetModel3D(Model* model);
	bool CheckCollision(Solid* other);
	Solid* Clone() const override {
		return new Battery(*this);  // Constructor copia para clonar
	}

	void Render();

};
