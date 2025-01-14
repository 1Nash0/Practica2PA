#pragma once
#include <GL/glut.h>
#include "Resource.h"

class Battery : public Resource
{
private:

	Model* model3D;

public:
	/*bool CheckCollision(const Solid& other);*/

	Battery() : model3D(nullptr), Resource() {}
	

	string GetType() const override { return "Battery"; }

	void SetModel3D(Model* model);

	Solid* Clone() const override {
		return new Battery(*this);  // Constructor copia para clonar
	}

	void Render();

};
