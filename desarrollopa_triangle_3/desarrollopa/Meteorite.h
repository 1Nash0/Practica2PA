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
		this->SetAffectedByGravity(true); // Habilitar gravedad para meteoritos
		this->SetCollisionRadius(1.0f);   // Define un radio de colisión si es necesario
		this->SetSpeed(Vector3D(-0.000002f, 0.0f, 0.0f));
	}


	void Update(const float& time) override; // Sobrescribir Update si es necesario
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
