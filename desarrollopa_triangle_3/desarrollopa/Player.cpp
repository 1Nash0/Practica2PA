#include "Player.h"
#include "Solid.h"
#include "Text.h"
#include "Color.h"
#include "Meteorite.h"  // Asegúrate de incluir la clase Meteorite

void Player::Render() {
    glPushMatrix();
    glColor4f(0.0f, 0.0f, 1.0f, 1.0f); // Cambiar color a azul
    glTranslatef(this->GetPosition().GetX(), this->GetPosition().GetY(), this->GetPosition().GetZ());
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f); // Rotar 90 grados para mirar a la derecha
    if (model3D) {
        model3D->Render();
    }
    else {
        std::cout << "[Player] No model set for rendering!" << std::endl;
    }
    healthText.Render();
    glPopMatrix();
}

void Player::Update(const float& time) {
    Vector3D currentPosition = this->GetPosition();
    if (isKeyPressed('W')) {
        this->SetPosition(Vector3D(currentPosition.GetX(), currentPosition.GetY() + 0.1f * time, currentPosition.GetZ())); // Mover hacia arriba
    }
    if (isKeyPressed('S')) {
        this->SetPosition(Vector3D(currentPosition.GetX(), currentPosition.GetY() - 0.1f * time, currentPosition.GetZ())); // Mover hacia abajo
    }
    if (isKeyPressed('A')) {
        this->SetPosition(Vector3D(currentPosition.GetX() - 0.1f * time, currentPosition.GetY(), currentPosition.GetZ())); // Mover hacia la izquierda
    }
    if (isKeyPressed('D')) {
        this->SetPosition(Vector3D(currentPosition.GetX() + 0.1f * time, currentPosition.GetY(), currentPosition.GetZ())); // Mover hacia la derecha
    }



    healthText.SetText("Vida: " + to_string(health));
    healthText.SetPosition(this->GetPosition() + Vector3D(0, 1.0f, 0)); // Posicionar el texto sobre el jugador
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
        if (batteryCount < 3) {
            batteryCount++;
            std::cout << "Batería recogida: " << batteryCount << std::endl;
        }
    }
}


    bool Player::CheckCollision(Solid * other) {
        if (other == nullptr) { // Validar puntero nulo
            return false;
        }

        if (Solid::CheckCollision(other)) {
            // Aquí determinamos el tipo de objeto con el que colisionó.
            if (other->GetType() == "Heart") {
                // Aumentar vida al colisionar con un corazón
                CollectResource("Heart");
                std::cout << "Vida aumentada. Vida actual: " << health << std::endl;
            }
            else if (other->GetType() == "Meteorite") {
                // Reducir vida al colisionar con un meteorito
                TakeDamage(1);
                std::cout << "Daño recibido por meteorito. Vida restante: " << health << std::endl;
            }
            else if (other->GetType() == "Battery") {
                // Aquí agregas lo que quieras hacer con las baterías
                CollectResource("Battery");
            }
            return true;
        }
        return false;
    }


bool Player::isKeyPressed(char key) {
    return (GetAsyncKeyState(key) & 0x8000) != 0;
}
// En Player.cpp
int Player::GetHealth() const {
    return health;  // Retorna la salud actual del jugador
}

