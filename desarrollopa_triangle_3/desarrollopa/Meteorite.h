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
	/*bool CheckCollision(const Solid& other);*/

	Meteorite() : model3D(nullptr), Solid()
	{
		this->size = 0.5;
	}

	inline float GetSize() { return this->size; }
	void SetSize(float sizeToSet) { this->size = sizeToSet; }
	string GetType() const override { return "Meteorite"; }
	void SetModel3D(Model* model);
	bool CheckCollision(Solid* other);
	Solid* Clone() const override {
		return new Meteorite(*this);  // Constructor copia para clonar
	}

	void Render();

};
