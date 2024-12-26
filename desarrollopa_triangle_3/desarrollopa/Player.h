#pragma once
#include "Solid.h"
#include "Model.h"
#include "Color.h"
#include "Projectile.h"
#include <GL/glut.h>
#include <string>
#include <iostream>

using namespace std;

class Player : public Solid {
private:

    float size;                 // Tamaño del jugador
    int health;                 // Vida restante
    int batteryCount;           // Baterías disponibles
    int score;                  // Puntos acumulados
    Model* model3D;             // Modelo 3D del jugador

public:
    // Constructor
    Player()
        : size(1.0), health(5), batteryCount(3), score(0), model3D(nullptr), Solid() {}


    // Getters y Setters
    inline float GetSize() const { return this->size; }
    void SetSize(float sizeToSet) { this->size = sizeToSet; }

    // Asignar modelo 3D
    void SetModel3D(Model* model);
   
    // Métodos de juego
    void Shoot();

    void LaunchBomb();

    void TakeDamage(int damage);

    void CollectResource(const std::string& resourceType);

    bool isKeyPressed(char key);

    void Update();

    Solid* Clone() const override {
        return new Player(*this);  // Constructor copia para clonar
    }

    void Render();
};
