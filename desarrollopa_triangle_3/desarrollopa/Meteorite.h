#pragma once
#include <GL/glut.h>
#include "Obstaculo.h"

class Meteorite : public Obstaculo
{
private:
	Model* model3D;
	float damage;
public:

	Meteorite() : model3D(nullptr), damage(1.0), Obstaculo() {}
	

	string GetType() const override { return "Meteorite"; }
	void SetModel3D(Model* model);


	inline float GetDamage() const { return this->damage; }
	void SetDamage(float damageToSet) { this->damage = damageToSet; }
	Solid* Clone() const override {
		return new Meteorite(*this);  // Constructor copia para clonar
	}
	void Render();

};
