#include "Solid.h"
#include "Model.h"
#include "Player.h"
#include "Color.h"
#include <GL/glut.h>
#include <string>
#include <iostream>

#ifndef HEART_H
#define HEART_H


using namespace std;

class Heart : public Solid {
private:

    int vidas;
    float size;
    Model* model3D;
    bool isVisible;


public:

    Heart()
        :  size(1.0), vidas(5), model3D(nullptr), isVisible(true) 
    {
        this->SetOrientationSpeed(Vector3D(0.0, 1.0, 0.0));
        this->SetCollisionRadius(0.4f);
    }

    int getVidas() const;

    string GetType() const override { return "Heart"; }

    // Getters y Setters
    inline float GetSize() const { return this->size; }
    void SetSize(float sizeToSet) { this->size = sizeToSet; }

    
    void sumarVidas(int cantidad);



    void mostrarVidas() const;

    Solid* Clone() const override;

    //void HandleCollision();

    bool CheckCollision(Solid* other);

    void SetModel3D(Model* model);

    void Render() override;
};

#endif // HEART_H








