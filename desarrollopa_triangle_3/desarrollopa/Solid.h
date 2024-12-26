#pragma once
#include "Vector3D.h"
#include "Color.h"
#include <iostream>

class Solid
{
private:
	Vector3D position;
	Vector3D speed;
	Vector3D orientation;
	Vector3D orientationSpeed;
	Vector3D velocity;
	Color color;
	bool wired;

public:
	Solid(
		Color colorArgument = Color(),
		Vector3D positionArgument = Vector3D(),
		Vector3D speedArgument = Vector3D(),
		Vector3D orientationArgument = Vector3D(),
		Vector3D orientationSpeedArgument = Vector3D())
		: color(colorArgument),
		position(positionArgument),
		speed(speedArgument),
		velocity(Vector3D(0, 0, 0)),
		orientation(orientationArgument),
		orientationSpeed(orientationSpeedArgument),
		wired(false) {}

	
	inline Vector3D GetPosition() { return this->position; }
	inline Vector3D GetSpeed() { return this->speed; }
	inline Vector3D GetOrientation() { return this->orientation; }
	inline Vector3D GetVelocity() { return this->velocity; }
	inline Vector3D GetOrientationSpeed() { return this->orientationSpeed; }
	inline Color GetColor() { return this->color; }
	inline bool GetWired() const { return this->wired; }


	//void SetPosition(const Vector3D& newPosition) { position = newPosition; }

	inline void SetPosition(Vector3D coordsToSet) { this->position = coordsToSet; }
	inline void SetSpeed(const Vector3D& speedToSet) { this->speed = speedToSet; }
	inline void SetOrientation(Vector3D orientationToSet) { this->orientation = orientationToSet; }
	inline void SetOrientationSpeed(Vector3D orientationSpeedToSet) { this->orientationSpeed = orientationSpeedToSet; }
	void SetVelocity(Vector3D velocityToSet) { this->velocity = velocityToSet; }
	virtual void SetColor(Color colorToSet) { this->color = colorToSet; }
	inline void SetWired(const bool wiredToSet) { this->wired = wiredToSet; }

	virtual void Render() = 0;
	virtual void Update();

	virtual Solid* Clone() const = 0;
};


