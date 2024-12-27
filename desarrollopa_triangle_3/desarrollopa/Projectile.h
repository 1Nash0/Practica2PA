#pragma once
#include "Sphere.h"
#include "Cylinder.h"
#include "Emmiter.h"
#include "EmmiterConfiguration.h"

class Projectile
{
private:
	Sphere bomb; //modelo del proyectil
	Cylinder bullet;

public:
	void SetBullet(int posx, int posy, int posz) {
		int numParticulas = 10;
		int tiempoEmision = 1000;
		Solid* particulaRef = new Cylinder();

		EmmiterConfiguration Config(numParticulas, tiempoEmision, particulaRef);
		Emmiter* emisor = new Emmiter(Config);

	}

	void SetBomb(int posx, int posy, int posz) {
		int numParticulas = 10;
		int tiempoEmision = 1000;
		Solid* particulaRef = new Sphere();

		EmmiterConfiguration Config(numParticulas, tiempoEmision, particulaRef);
		Emmiter* emisor = new Emmiter(Config);

	}

};


