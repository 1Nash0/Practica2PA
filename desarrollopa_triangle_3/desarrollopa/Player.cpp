#include "Player.h"



void Player::Render() {

    glPushMatrix();
    glTranslatef(this->GetPosition().GetX(), this->GetPosition().GetY(), this->GetPosition().GetZ());
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f); // Rotar 90 grados para mirar a la derecha
    if (model3D) {
        model3D->Render();
    }
    glPopMatrix();
}

void Player::Update(const float& time) {

    PlayerMovement(time);
}

void Player::PlayerMovement(const float& time) {
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
        std::cerr << "Modelo nulo pasado como argumento." << std::endl;
    }
}

void Player::TakeDamage(int damage) {
    if (health > 0) {
        health -= damage;
    }
}

void Player::CollectResource(const std::string& resourceType) {
    if (resourceType == "Heart") {
        if (health < 5) {
            health++;
        }
    }
    else if (resourceType == "Battery") {
        if (battery < 10) {
            battery++;
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
    if (other == nullptr) { 
        return false;
    }
}

bool Player::isKeyPressed(char key) {
    return (GetAsyncKeyState(key) & 0x8000) != 0;
}



