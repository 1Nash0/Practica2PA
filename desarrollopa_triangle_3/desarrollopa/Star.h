#pragma once
#include <GL/glut.h>
#include "Model.h"
#include "Solid.h"

class Star : public Solid
{
private:

	Model* model3D;

public:

	Star() : model3D(nullptr), Solid() {}
	
	void SetModel3D(Model* model);

	Solid* Clone() const override {
		return new Star(*this);  
	}
	void Render();

};