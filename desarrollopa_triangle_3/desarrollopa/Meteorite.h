#pragma once
#include <GL/glut.h>
#include "Model.h"
#include "Solid.h"

class Meteorite : public Solid
{
private:

	Model* model3D;

public:
	/*bool CheckCollision(const Solid& other);*/

	Meteorite() : model3D(nullptr), Solid()
	{
		this->SetAffectedByGravity(true); // Habilitar gravedad para meteoritos
		this->SetCollisionRadius(1.0f);   // Define un radio de colisión si es necesario
		this->SetSpeed(Vector3D(-0.01, 0.0f, 0.0f));
		this->SetOrientationSpeed(Vector3D(rand() % 10 -9,rand() % 10 - 9, 0.0));
	}


	
	string GetType() const override { return "Meteorite"; }
	void SetModel3D(Model* model);
	bool CheckCollision(Solid* other);
	Solid* Clone() const override {
		return new Meteorite(*this);  // Constructor copia para clonar
	}

	void Render();

};
