
#pragma once
#include <GL/glut.h>
#include "Model.h"
#include "Solid.h"


using namespace std;

class Heart : public Solid {
private:

    float size;
    Model* model3D;

public:

    Heart() : model3D(nullptr), Solid()
    {
        this->size = 0.5;
        this->SetAffectedByGravity(true); // Habilitar gravedad para meteoritos
        this->SetCollisionRadius(0.8f);   // Define un radio de colisión si es necesario
        this->SetSpeed(Vector3D(-0.1, 0.0f, 0.0f));
        this->SetOrientationSpeed(Vector3D(0.0, 4.0, 0.0));
    }

    string GetType() const override { return "Heart"; }

    // Getters y Setters
    inline float GetSize() const { return this->size; }
    void SetSize(float sizeToSet) { this->size = sizeToSet; }

    Solid* Clone() const override;


    void SetModel3D(Model* model);
    bool CheckCollision(Solid* other);

    void Render();
};









