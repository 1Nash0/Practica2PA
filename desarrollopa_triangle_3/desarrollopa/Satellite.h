#pragma once
#include <GL/glut.h>
#include "Model.h"
#include "Solid.h"

class Satellite : public Solid
{
private:

	float size;
	Model* model3D;

public:
	/*bool CheckCollision(const Solid& other);*/

	Satellite() : model3D(nullptr), Solid()
	{
		this->size = 0.5;
	}

	inline float GetSize() { return this->size; }
	void SetSize(float sizeToSet) { this->size = sizeToSet; }

	void SetModel3D(Model* model);

	Solid* Clone() const override {
		return new Satellite(*this);  // Constructor copia para clonar
	}

	void Render();

};

