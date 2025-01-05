#pragma once
#include "Solid.h"
class Camera : public Solid
{
private:
	Vector3D position;

public:
	Camera() : position(0, 0, 0.0) {} // Constructor por defecto
	void SetPosition(const Vector3D& newPosition) { position = newPosition; }
	Vector3D GetPosition() const { return position; }

	Camera* Clone() const override {
		return new Camera(*this);
	}

	void Render();
	
};

