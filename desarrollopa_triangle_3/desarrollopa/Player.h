#pragma once
#include "Solid.h"
#include "Model.h"
#include "Heart.h"
#include "Battery.h"
#include "Text.h"
#include <GL/glut.h>
#include <string>
#include "Meteorite.h" 



using namespace std;

class Player : public Solid {
private:
    float size;                 // Tamaño del jugador
    int health;                 // Vida restante
    int battery;           // Baterías disponibles            // Puntos acumulados
    Model* model3D;             // Modelo 3D del jugador  // Generador de projectiles




public:
    // Constructor
    Player()
        :  size(1.0), health(5), battery(0), 
        model3D(nullptr)
    {   
        this->SetSize(1.0);
        this->SetCollisionRadius(0.8f);
        this->SetPosition(Vector3D(5.0, 5.0, 0.0));
        this->SetOrientationSpeed(Vector3D(0.0, 0.0, 0.1));
    
    }


    // Getters y Setters
    inline float GetSize() const { return this->size; }
    void SetSize(float sizeToSet) { this->size = sizeToSet; }



    void SetModel3D(Model* model);
    int GetHealth() const { return health; }
    int GetBattery() const { return battery; }
  
    string GetType() const override { return "Player"; }

    // Métodos de juego
    void TakeDamage(int damage);
    void CollectResource(const std::string& resourceType);
    void PlayerMovement(const float& time);
    bool isKeyPressed(char key);
    void Update(const float& time);
    void OnCollision(Solid* other) override; // Sobrescritura para manejar colisiones específicas
    bool CheckCollision(Solid* other);

    Solid* Clone() const override {
        Player* clone = new Player(*this);
        if (this->model3D) clone->model3D = new Model(*this->model3D); // Copia profundo
        return clone;
    }

    void Render();
};
