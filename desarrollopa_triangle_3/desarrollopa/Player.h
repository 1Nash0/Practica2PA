#pragma once
#include "Solid.h"
#include "Model.h"
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

    // Destructor
    ~Player() {
        if (model3D) {
            delete model3D;
            model3D = nullptr;
        }
    }

    // Getters y Setters
    inline float GetSize() const { return this->size; }
    void SetSize(float sizeToSet) { this->size = sizeToSet; }

    // Asignar modelo 3D
    void SetModel3D(Model* model) {
        if (model) {
            this->model3D = model;
        }
        else {
            std::cerr << "[Player::SetModel3D] Modelo nulo pasado como argumento." << std::endl;
        }
    }

    void Move(float deltaX, float deltaY) {
        // Llamar al método Move de Solid que actualiza la posición
        Solid::Move(deltaX, deltaY);
    }

    // Métodos de juego
    void Shoot() {
        cout << "Disparando...\n";
        // Lógica para disparar
    }

    void LaunchBomb() {
        if (batteryCount > 0) {
            batteryCount--;
            cout << "¡Bomba lanzada!\n";
            // Lógica para lanzar bomba
        }
        else {
            cout << "Sin baterías.\n";
        }
    }

    void TakeDamage(int damage) {
        health -= damage;
        if (health <= 0) {
            std::cout << "¡GAME OVER!\n";
        }
    }

    void CollectResource(const std::string& resourceType) {
        if (resourceType == "Heart") {
            if (health < 5) health++;
        }
        else if (resourceType == "Battery") {
            if (batteryCount < 3) batteryCount++;
        }
    }

    // Renderizado
    //void Render() {
    //    glPushMatrix();
    //    glTranslatef(this->GetPosition().GetX(), this->GetPosition().GetY(), this->GetPosition().GetZ());
    //    glColor4f(this->GetColor().GetRed(), this->GetColor().GetGreen(), this->GetColor().GetBlue(), this->GetColor().GetAlpha());

    //    if (model3D) {
    //        model3D->Render(); // Renderiza el modelo 3D
    //    }
    //    else {
    //        // Si no hay modelo, renderiza un cubo básico
    //        if (!this->GetWired()) {
    //            glutSolidCube(this->GetSize());
    //        }
    //        else {
    //            glutWireCube(this->GetSize());
    //        }
    //    }

    //    glPopMatrix();
    //}
    //bool isKeyPressed(char key) {
    //    return (GetAsyncKeyState(key) & 0x8000) != 0;
    //}
    //void Update() {
    //    if (isKeyPressed('W')) {
    //        this->GetPosition().Move(0.0f, 1.0f);  // Mover hacia arriba
    //    }
    //    if (isKeyPressed('S')) {
    //        this->GetPosition().Move(0.0f, -1.0f);  // Mover hacia abajo
    //    }
    //    if (isKeyPressed('A')) {
    //        this->GetPosition().Move(-1.0f, 0.0f);  // Mover hacia la izquierda
    //    }
    //    if (isKeyPressed('D')) {
    //        this->GetPosition().Move(1.0f, 0.0f);  // Mover hacia la derecha
    //    }
    //}


    void Render();
};
