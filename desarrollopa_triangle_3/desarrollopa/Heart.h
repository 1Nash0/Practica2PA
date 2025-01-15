#pragma once
#include "Resource.h"



class Heart : public Resource {
private:

    Model* model3D;

public:

    Heart() : model3D(nullptr), Resource()
    {
        this->SetCollisionRadius(0.8f);   
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









