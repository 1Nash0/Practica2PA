#pragma once
#include "Solid.h"
class Camera : public Solid
{
private:
	Vector3D position;
	Vector3D lookAt;
public:
	Camera() : position(0, 0, 0.0) {} // Constructor por defecto
	void SetPosition(const Vector3D& newPosition) { position = newPosition; }
	Vector3D GetPosition() const { return position; }

	Camera* Clone() const override {
		return new Camera(*this);
	}

	void Render();
	void SetLookAt(const Vector3D& target) { lookAt = target; }

	Vector3D GetLookAt() const { return lookAt; }
};

