#pragma once
#include "Solid.h"
#include "Model.h"
#include "Heart.h"
#include "Battery.h"
#include "Resource.h"
#include "Text.h"
#include <GL/glut.h>
#include <string>
#include "Meteorite.h" 


using namespace std;

class Player : public Solid {
private:

    float size;                
    int health;                 
    int battery;           
    Model* model3D;             

public:

    Player()
        :  size(1.0), health(5), battery(0),  model3D(nullptr)
    {   
        this->SetSize(1.0);
        this->SetCollisionRadius(0.8f);
        this->SetPosition(Vector3D(5.0, 5.0, 0.0));
        this->SetOrientationSpeed(Vector3D(0.0, 0.0, 0.1));
    }

    float GetSize() const { return this->size; }
    int GetHealth() const { return health; }
    int GetBattery() const { return battery; }
    string GetType() const override { return "Player"; }


    void SetSize(float sizeToSet) { this->size = sizeToSet; }
    void SetModel3D(Model* model);


    void TakeDamage();
    void CollectResource(const std::string& resourceType);
    void PlayerMovement(const float& time);
    void Update(const float& time);
    void OnCollision(Solid* other) override;
    bool CheckCollision(Solid* other);
    bool isKeyPressed(char key);
    void Render();

    Solid* Clone() const override {
        Player* clone = new Player(*this);
        if (this->model3D) clone->model3D = new Model(*this->model3D); 
        return clone;
    }
};
