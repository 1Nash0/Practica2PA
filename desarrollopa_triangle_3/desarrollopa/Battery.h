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
		this->size = 0.5;
	}

	inline float GetSize() { return this->size; }
	void SetSize(float sizeToSet) { this->size = sizeToSet; }

	void SetModel3D(Model* model);
	bool CheckCollision(Solid* other);
	string GetType() const override { return "Battery"; }
	Solid* Clone() const override {
		return new Battery(*this);  // Constructor copia para clonar
	}

	void Render();

};
