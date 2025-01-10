#include "Player.h"
#include "Solid.h"
#include "Text.h"
#include "Color.h"
#include "Meteorite.h" 
#include "Heart.h"    // Asegúrate de incluir las cabeceras necesarias
#include "Battery.h"  // Asegúrate de incluir las cabeceras necesarias
#include <iostream>
#include <GL/gl.h>    // Asegúrate de incluir OpenGL
#include <GL/glu.h>   // Asegúrate de incluir OpenGL
#include <windows.h>  // Para GetAsyncKeyState

void Player::Render() {
    glPushMatrix();
    glTranslatef(this->GetPosition().GetX(), this->GetPosition().GetY(), this->GetPosition().GetZ());
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f); // Rotar 90 grados para mirar a la derecha
    if (model3D) {
        model3D->Render();
    }
    else {
        std::cout << "[Player] No model set for rendering!" << std::endl;
    }
    glPopMatrix();

    glPushMatrix();
    healthText.SetText("Vidas: " + std::to_string(health));
    healthText.SetPosition(Vector3D(1.0f, 12.0f, 0.0f)); // Posición fija
    healthText.SetColor(Color(1.0f, 0.0f, 0.0f, 1.0f));
    healthText.Render();

    batteryText.SetText("Baterias: " + std::to_string(batteryCount) +"/10");
    batteryText.SetPosition(Vector3D(5.0f, 12.0f, 0.0f)); // Posición fija
    batteryText.SetColor(Color(1.0f, 1.0f, 0.1f, 1.0f));
    batteryText.Render();
    glPopMatrix();
}

void Player::Update(const float& time) {
    Vector3D currentPosition = this->GetPosition();
    if (isKeyPressed('W')) {
        this->SetPosition(Vector3D(currentPosition.GetX(), currentPosition.GetY() + 0.5f * time, currentPosition.GetZ())); // Mover hacia arriba
    }
    if (isKeyPressed('S')) {
        this->SetPosition(Vector3D(currentPosition.GetX(), currentPosition.GetY() - 0.5f * time, currentPosition.GetZ())); // Mover hacia abajo
    }
    if (isKeyPressed('A')) {
        this->SetPosition(Vector3D(currentPosition.GetX() - 0.5f * time, currentPosition.GetY(), currentPosition.GetZ())); // Mover hacia la izquierda
    }
    if (isKeyPressed('D')) {
        this->SetPosition(Vector3D(currentPosition.GetX() + 0.5f * time, currentPosition.GetY(), currentPosition.GetZ())); // Mover hacia la derecha
    }
}

void Player::SetModel3D(Model* model) {
    if (model) {
        this->model3D = model;
    }
    else {
        std::cerr << "[Player::SetModel3D] Modelo nulo pasado como argumento." << std::endl;
    }
}

void Player::TakeDamage(int damage) {
    if (health > 0) {
        health -= damage;
        if (health <= 0) {
            std::cout << "¡GAME OVER!\n";
            // Aquí puedes agregar lógica adicional para detener el juego o reiniciarlo.
        }
    }
}

void Player::CollectResource(const std::string& resourceType) {
    if (resourceType == "Heart") {
        if (health < 5) {
            health++;
            std::cout << "Vida aumentada: " << health << std::endl;
        }
    }
    else if (resourceType == "Battery") {
        if (batteryCount < 10) {
            batteryCount++;
            std::cout << "Batería recogida: " << batteryCount << std::endl;
            if (batteryCount == 10) {
                batteryText.SetText("Victoria");
            }
        }
    }
}

void Player::OnCollision(Solid* other) {
    if (Meteorite* meteorite = dynamic_cast<Meteorite*>(other)) {
        TakeDamage(1); // Reduce la vida del jugador
        meteorite->MarkForDeletion(); // Marca el meteorito para eliminación
    }
    else if (Heart* heart = dynamic_cast<Heart*>(other)) {
        if (health < 5) { // Solo recoge corazones si no tiene vida completa
            CollectResource("Heart");
            heart->MarkForDeletion(); // Marca el corazón para eliminación
        }
    }
    else if (Battery* battery = dynamic_cast<Battery*>(other)) {
        CollectResource("Battery"); // Incrementa la energía del jugador
        battery->MarkForDeletion(); // Marca la batería para eliminación
    }
}

bool Player::CheckCollision(Solid* other) {
    if (other == nullptr) { // Validar puntero nulo
        return false;
    }
    // Aquí puedes agregar la lógica de colisión real
    return false;
}

bool Player::isKeyPressed(char key) {
    return (GetAsyncKeyState(key) & 0x8000) != 0;
}

int Player::GetHealth() const {
    return health;  // Retorna la salud actual del jugador
}

int Player::GetEnergy() const {
    return batteryCount;
}
