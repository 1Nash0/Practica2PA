#pragma once
#include "Scene.h"
#include "Text.h"


class WinScene : public Scene

{
private:
	Camera* camara;
	vector <Text*> textos;

public:
	WinScene() : camara() {}

	inline Camera* GetCamera() const { return this->camara; }

	inline void SetCamera(Camera* cameraToSet) { this->camara = cameraToSet; }

	void SetCameraPosition(Vector3D position);
	void Init();


};
