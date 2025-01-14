#pragma once
#include <GL/glut.h>
#include "Model.h"
#include "Recogible.h"

class Battery : public Recogible
{
private:

	Model* model3D;

public:
	/*bool CheckCollision(const Solid& other);*/

	Battery() : model3D(nullptr), Recogible() {}
	


	string GetType() const override { return "Battery"; }

	void SetModel3D(Model* model);

	Solid* Clone() const override {
		return new Battery(*this);  // Constructor copia para clonar
	}

	void Render();

};
