#pragma once
#include <GL/glut.h>
#include "Model.h"
#include "Solid.h"

class Meteorite : public Solid
{
private:
	float size;
	Model* model3D;

public:

	Meteorite() : model3D(nullptr), Solid()
	{
		this->size = 1.0;
		this->SetAffectedByGravity(true); // Habilitar gravedad para meteoritos
		this->SetCollisionRadius(1.0f);   // Define un radio de colisión si es necesario
		this->SetSpeed(Vector3D(-0.01, 0.0f, 0.0f));
		this->SetOrientationSpeed(Vector3D(rand() % 10 -9,rand() % 10 - 9, 0.0));
	}

	inline float GetSize() const { return this->size; }
	string GetType() const override { return "Meteorite"; }

	void SetSize(float sizeToSet) { this->size = sizeToSet; }
	void SetModel3D(Model* model);

	bool CheckCollision(Solid* other);

	Solid* Clone() const override {
		return new Meteorite(*this);  // Constructor copia para clonar
	}

	void Render();

};
