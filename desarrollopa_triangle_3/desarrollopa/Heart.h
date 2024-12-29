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
    Vector3D position;
    float collisionRadius;

public:

    Heart(Vector3D positionArgument = Vector3D(), float collisionRadiusArgument = 1.0f)
        : position(positionArgument), size(1.0), vidas(5), model3D(nullptr), isVisible(true), collisionRadius(collisionRadiusArgument) {}

    int getVidas() const;

    inline Vector3D GetPosition() const { return position; }
    inline void SetPosition(const Vector3D& coordsToSet) { position = coordsToSet; }

    // Getters y Setters
    inline float GetSize() const { return this->size; }
    void SetSize(float sizeToSet) { this->size = sizeToSet; }

    inline float GetCollisionRadius() const { return collisionRadius; }
    inline void SetCollisionRadius(float collisionRadiusToSet) { collisionRadius = collisionRadiusToSet; }

    void sumarVidas(int cantidad);

    //bool getIsVisible() const { return isVisible; }

    //void setIsVisible(bool visible) { isVisible = visible; }

    void mostrarVidas() const;

    Solid* Clone() const override;

    //void HandleCollision();

   bool CheckCollision(const Solid& other);

    void SetModel3D(Model* model);

    void Render() override;
};

#endif // HEART_H








