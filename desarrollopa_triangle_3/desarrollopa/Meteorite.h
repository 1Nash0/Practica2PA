#pragma once
#include <GL/glut.h>
#include "Obstacle.h"

class Meteorite : public Obstacle
{
private:

	Model* model3D;
	float damage;

public:

	Meteorite() : model3D(nullptr), damage(1.0), Obstacle() {}
	
	string GetType() const override { return "Meteorite"; }
	inline float GetDamage() const { return this->damage; }
	void SetDamage(float damageToSet) { this->damage = damageToSet; }
	void SetModel3D(Model* model);

	Solid* Clone() const override {
		return new Meteorite(*this);  // Constructor copia para clonar
	}
	void Render();

};
