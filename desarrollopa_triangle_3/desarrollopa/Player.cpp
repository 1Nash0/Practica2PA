#include "Player.h"
#include "Solid.h"
#include "Color.h"

void Player::Render()
{
    glPushMatrix();
    glColor4f(0.0f, 0.0f, 1.0f, 1.0f); // Cambiar color a azul
    glTranslatef(this->GetPosition().GetX(), this->GetPosition().GetY(), this->GetPosition().GetZ());
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f); // Rotar 90 grados para mirar a la derecha
    if (model3D) {
        model3D->Render();
    }
    else {
        // Si no hay modelo, dibuja una representación básica o lanza un error
        std::cout << "[Player] No model set for rendering!" << std::endl;
    }
    glPopMatrix();
}
void Player:: Update(const float& time) {
    Vector3D currentPosition = this->GetPosition();
    if (isKeyPressed('W')) {
        this->SetPosition(Vector3D(currentPosition.GetX(), currentPosition.GetY() + 0.1f * time, currentPosition.GetZ()));  // Mover hacia arriba
    }
    if (isKeyPressed('S')) {
        this->SetPosition(Vector3D(currentPosition.GetX(), currentPosition.GetY() - 0.1f * time, currentPosition.GetZ()));  // Mover hacia abajo
    }
    if (isKeyPressed('A')) {
        this->SetPosition(Vector3D(currentPosition.GetX() - 0.1f * time, currentPosition.GetY(), currentPosition.GetZ()));  // Mover hacia la izquierda
    }
    if (isKeyPressed('D')) {
        this->SetPosition(Vector3D(currentPosition.GetX() + 0.1f * time, currentPosition.GetY(), currentPosition.GetZ()));  // Mover hacia la derecha
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

//void Player::SetProjectile() {
//    Vector3D pos = this->GetPosition();
//    Vector3D updater = Vector3D(0.0, 2.0, 0.0);
//    pos = pos + updater;
//    proyectil.SetPosition(pos);
//}

// Métodos de juego
void Player:: Shoot() {
    cout << "Disparando...\n";
    // Lógica para disparar
}

void Player::LaunchBomb() {
    if (batteryCount > 0) {
        batteryCount--;
        cout << "¡Bomba lanzada!\n";
        // Lógica para lanzar bomba
    }
    else {
        cout << "Sin baterías.\n";
    }
}

void Player::TakeDamage(int damage) {
    health -= damage;
    if (health <= 0) {
        std::cout << "¡GAME OVER!\n";
    }
}

void Player::CollectResource(const std::string& resourceType) {
    if (resourceType == "Heart") {
        if (health < 5) health++;
    }
    else if (resourceType == "Battery") {
        if (batteryCount < 3) batteryCount++;
    }

}

//bool CheckCollision(const Solid& other)  {
//    // Lógica específica para la colisión con corazones
//    return false; // Ejemplo
//}

bool Player::isKeyPressed(char key) {
    return (GetAsyncKeyState(key) & 0x8000) != 0;
}

    bool Player::CheckCollision(Solid * other) {
        if (other == nullptr) { // Validar puntero nulo
            return false;
        }
        return Solid::CheckCollision(other); // Usar el método base
    }

//void SetModel3D(Model* model);



