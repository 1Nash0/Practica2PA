#pragma once
#include "Sphere.h"
#include "Cylinder.h"
#include "Vector3D.h"
#include "Solid.h"
#include "Emmiter.h"
#include "EmmiterConfiguration.h"

class Projectile
{
private:
	Sphere bomb; //modelo del proyectil
	Cylinder bullet;
	Vector3D position;	//posición de la nave

public:
	void SetPosition(Vector3D pos) {
		position = pos;
	}
	void SetBomb() {

		this->bomb.SetPosition(position);
		this->bomb.SetOrientation(Vector3D(this->bomb.GetOrientation().GetX(), this->bomb.GetOrientation().GetY(), 90.0f));
		this->bomb.SetSpeed(Vector3D(0.0, 0.5, 0.0));
	}
	void SetBullet() {

		this->bullet.SetPosition(position);
		this->bullet.SetOrientation(Vector3D(this->bullet.GetOrientation().GetX(), this->bullet.GetOrientation().GetY(), 90.0f));
		this->bullet.SetSpeed(Vector3D(0.0, 0.5, 0.0));
	}
};





