#pragma once
#include <GL/glut.h>
#include "Obstaculo.h"

class Meteorite : public Obstaculo
{
private:
	Model* model3D;

public:

	Meteorite() : model3D(nullptr), Obstaculo() {}
	

	string GetType() const override { return "Meteorite"; }
	void SetModel3D(Model* model);

	Solid* Clone() const override {
		return new Meteorite(*this);  // Constructor copia para clonar
	}
	void Render();

};
