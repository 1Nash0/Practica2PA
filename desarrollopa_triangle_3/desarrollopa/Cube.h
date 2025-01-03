#pragma once
#include <GL/glut.h>
#include "Solid.h"

class Cube : public Solid
{
private:

	float size;

public:

	Cube() : Solid()
	{
		this->size = 1.0;
	}

	inline float GetSize() { return this->size; }
	void SetSize(float sizeToSet) { this->size = sizeToSet; }

	Solid* Clone() const override {
		return new Cube(*this);  // Constructor copia para clonar
	}

	void Render();

};

