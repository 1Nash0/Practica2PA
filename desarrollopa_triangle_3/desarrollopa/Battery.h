#pragma once
#include <GL/glut.h>
#include "Resource.h"

class Battery : public Resource
{
private:

	Model* model3D;

public:

	Battery() : model3D(nullptr), Resource() {}
	
	string GetType() const override { return "Battery"; }
	void SetModel3D(Model* model);

	Solid* Clone() const override {
		return new Battery(*this); 
	}

	void Render();
};
