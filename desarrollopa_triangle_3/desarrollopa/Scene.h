#pragma once
#include <vector>
#include "Solid.h"
#include "Camera.h"
#include "Cuboid.h"

using namespace std;

class Scene
{
private:
	vector<Solid*> gameObjects;
	Camera camera;
	
	Vector3D boundary;
	Vector3D gravity;
	bool drawBoundary;
	void checkBoundary();
	void renderBoundary();

protected:

	void checkBoundary(Solid*);

public:

	vector<Solid*>& GetGameObjects() {
		return gameObjects;
	}

	Scene(Vector3D boundaryArgument = Vector3D(19, 11, 4)) : boundary(boundaryArgument)
	{
		this->drawBoundary = true;
		this->camera.SetPosition(Vector3D(boundary.GetX() / 2, boundary.GetY() / 2, boundary.GetZ() * 3.5));
	}

	inline Vector3D GetBoundary() { return this->boundary; }
	inline bool GetDrawBoundary() { return this->drawBoundary; }
	inline Vector3D GetGravity() { return this->gravity; }
	inline void SetDrawBoundary(bool drawBoundaryToSet) { this->drawBoundary = drawBoundaryToSet; }
	void SetGravity(Vector3D gravityToSet) { this->gravity = gravityToSet; }

	void AddGameObject(Solid* gameObject);

	void Init();
	void Render();
	void Update(const float& time);
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClicked(int button, int state, int x, int y);
};

