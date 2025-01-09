#pragma once
#include "Scene.h"
class DefeatScene : public Scene
    
{
private:
	Camera* camara;
	vector <Text*> textos;
public:
	DefeatScene() : camara() {}

	inline Camera* GetCamera() const { return this->camara; }

	inline void SetCamera(Camera* cameraToSet) { this->camara = cameraToSet; }

	void SetCameraPosition(Vector3D position);
	void Init();
	void Update();
};

