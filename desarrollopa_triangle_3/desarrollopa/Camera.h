#pragma once
#include "Solid.h"
class Camera : public Solid
{
private:

public:
	Camera() {}

	Camera* Clone() const override {
		return new Camera(*this);
	}

	void Render();
};

