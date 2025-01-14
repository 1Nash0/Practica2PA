
#pragma once
#include <GL/glut.h>
#include "Recogible.h"


using namespace std;

class Heart : public Recogible {
private:

    Model* model3D;

public:

    Heart() : model3D(nullptr), Recogible()
    {
        this->SetCollisionRadius(0.8f);   // Define un radio de colisión si es necesario
        this->SetSpeed(Vector3D(-0.2, 0.0f, 0.0f));
        this->SetOrientationSpeed(Vector3D(0.0, 4.0, 0.0));
    }

    string GetType() const override { return "Heart"; }


    Solid* Clone() const {
        return new Heart(*this);
    }

    void SetModel3D(Model* model);

    void Render();
};









