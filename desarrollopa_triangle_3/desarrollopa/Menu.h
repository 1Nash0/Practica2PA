#pragma once
#include "Scene.h"


class Menu : public Scene
{
private:
	Camera* camara;
	vector <Text*> textos;
public:
	Menu() : camara() {}
	
	inline Camera* GetCamera() const { return this->camara; }
	inline void SetCamera(Camera* cameraToSet) { this->camara = cameraToSet; }

	void SetCameraPosition(Vector3D position);
	void Init();

};