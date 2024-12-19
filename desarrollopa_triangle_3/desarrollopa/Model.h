#pragma once
#include <vector>
#include "Solid.h"
#include "Triangle.h"
#include <GL/glut.h>

using namespace std;

class Model : public Solid
{
private:
	vector<Triangle> triangles;
public:
	Model() {}

	Solid* Clone();
	void Render();

	void AddTriangle(Triangle triangle);
	void Clear();

	void SetColor(Color colorToSet) override;

};

