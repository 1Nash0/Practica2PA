#pragma once
#include "Solid.h"
#include "Model.h"
#include "Color.h"
#include "Text.h"
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
    Projectile* proyectil;      // Generador de projectiles
    Text healthText;
    Text batteryText;



public:
    // Constructor
    Player()
        :  size(1.0), health(5), batteryCount(0), score(0),
        model3D(nullptr), proyectil(nullptr) {}


    // Getters y Setters
    inline float GetSize() const { return this->size; }
    void SetSize(float sizeToSet) { this->size = sizeToSet; }


    // Asignar modelo 3D
    void SetModel3D(Model* model);
    int GetHealth() const;
    int GetEnergy() const;
  
    string GetType() const override { return "Player"; }
    // Métodos de juego
    void TakeDamage(int damage);
    void CollectResource(const std::string& resourceType);

    bool isKeyPressed(char key);

    void Update(const float& time);

    bool CheckCollision(Solid* other);

    Solid* Clone() const override {
        Player* clone = new Player(*this);
        if (this->model3D) clone->model3D = new Model(*this->model3D); // Copia profundo
        return clone;
    }

    void Render();
};
