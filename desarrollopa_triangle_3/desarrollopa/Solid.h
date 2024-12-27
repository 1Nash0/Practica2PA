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
	float time;
	bool wired;
	bool isAffectedByGravity;
	

public:
	/*virtual bool CheckCollision(Solid* other);*/

	Solid(
		Color colorArgument = Color(),
		Vector3D positionArgument = Vector3D(),
		Vector3D speedArgument = Vector3D(),
		Vector3D orientationArgument = Vector3D(),
		Vector3D orientationSpeedArgument = Vector3D(),
		float collisionRadiusArgument = 1.0f)
		: color(colorArgument),
		position(positionArgument),
		speed(speedArgument),
		velocity(Vector3D(0, 0, 0)),
		orientation(orientationArgument),
		orientationSpeed(orientationSpeedArgument),
		wired(false),
		isAffectedByGravity(false),
		time(0.0f) // Inicialización de la variable time
	{}

	
	inline Vector3D GetPosition()  {return this->position;}
	inline Vector3D GetSpeed() const { return this->speed; }
	inline Vector3D GetOrientation() { return this->orientation; }
	inline Vector3D GetVelocity() { return this->velocity; }
	inline Vector3D GetOrientationSpeed() { return this->orientationSpeed; }
	inline Color GetColor() { return this->color; }
	inline bool GetWired() const { return this->wired; }
	inline bool GetIsAffectedByGravity() const { return this->isAffectedByGravity; }
	

	//void SetPosition(const Vector3D& newPosition) { position = newPosition; }

	inline void SetPosition( Vector3D coordsToSet) { this->position = coordsToSet; }
	inline void SetSpeed(const Vector3D& speedToSet) { this->speed = speedToSet; }
	inline void SetOrientation(Vector3D orientationToSet) { this->orientation = orientationToSet; }
	inline void SetOrientationSpeed(Vector3D orientationSpeedToSet) { this->orientationSpeed = orientationSpeedToSet; }
	void SetVelocity(Vector3D velocityToSet) { this->velocity = velocityToSet; }
	virtual void SetColor(Color colorToSet) { this->color = colorToSet; }
	inline void SetWired(const bool wiredToSet) { this->wired = wiredToSet; }
	inline void SetIsAffectedByGravity(const bool isAffectedByGravityToSet) { this->isAffectedByGravity = isAffectedByGravityToSet; }

	virtual void Render() = 0;
	virtual void Update(const float& time);

	virtual Solid* Clone() const = 0;

	
};


