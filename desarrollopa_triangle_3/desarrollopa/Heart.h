#include "Solid.h"
#include "Model.h"
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
        : size(1.0), vidas(5), model3D(nullptr), isVisible(true), Solid() {}

    int getVidas() const;

    void sumarVidas(int cantidad);

    //bool getIsVisible() const { return isVisible; }

    //void setIsVisible(bool visible) { isVisible = visible; }

    void mostrarVidas() const;

    Solid* Clone() const override;

    void HandleCollision();

    void SetModel3D(Model* model);

    void Render() override;
};

#endif // HEART_H








