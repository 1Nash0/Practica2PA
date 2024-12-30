#include "Emmiter.h"
#include "Solid.h"
#include "Scene.h"
#include <ctime>
#include <cstdlib>
#include <cmath>

// Constructor
Emmiter::Emmiter(const EmmiterConfiguration& config)
    : config(config),
    initialMilliseconds(duration_cast<milliseconds>(system_clock::now().time_since_epoch())),
    lastUpdateTime(0) {
    std::srand(std::time(nullptr));  // Establecer la semilla para la aleatoriedad
}


// Implementación del método Render() que invoca Render en todas las partículas
void Emmiter::Render() {
    for (auto p : particulas) {
        p->Render();
    }
}

// Implementación del método Update() que controla la frecuencia de emisión y crea nuevas partículas

void Emmiter::Update(const float& time) {

    milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());


    // Verificar si ha pasado el tiempo de emisión configurado
    if (currentTime.count() - this->initialMilliseconds.count() - this->lastUpdateTime > this->config.GetTiempoEmision() && particulas.size() < config.GetNumParticulas()) {
        // Crear nueva partícula clonando la partícula de referencia
        Solid* newParticula = config.GetParticula()->Clone();


        newParticula->SetPosition(Vector3D(
            (rand() % 100 - 25),  
            (rand() % 100 - 25),
            -20.0f               // Fijo en Z (puedes ajustarlo según tu necesidad)
        ));
        //newParticula->SetColor(Color((float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX, 1.0f));  // Color aleatorio
        newParticula->SetOrientation(Vector3D(1.0, 0.0, 0.0));  // Orientación aleatoria
        newParticula->SetOrientationSpeed(Vector3D(
            (rand() % 10 - 5) / 2.0f,
            (rand() % 10 - 5) / 2.0f,
            (rand() % 10 - 5) / 2.0f));

        //Vector3D velocity((rand() % 100 - 50) / 10000.0f,
        //    (rand() % 100 - 50) / 10000.0f,
        //    (rand() % 100 - 50) / 10000.0f);
        //newParticula->SetVelocity(velocity);  // Asignar la velocidad a la partícula

        // Añadir la nueva partícula al vector

        particulas.push_back(newParticula);

        // Actualizar el tiempo del último update

        this->lastUpdateTime = currentTime.count() - this->initialMilliseconds.count();
    }

    // Actualizar todas las partículas
    for (auto p : particulas) {
        // Mover las partículas en su dirección de velocidad

        Vector3D position = p->GetPosition();
        Vector3D velocity = p->GetVelocity();
       /* position = position + velocity; */ // Desplazar la partícula

        // Rebote cuando la partícula se sale de los límites 

        if (position.x < -25 || position.x > 25) velocity.x *= -1;
        if (position.y < -25 || position.y > 25) velocity.y *= -1;
        if (position.z < -25 || position.z > 25) velocity.z *= -1;


        p->SetPosition(position);  // Actualizar la posición de la partícula
        p->SetVelocity(velocity);  // Actualizar la velocidad

        // Actualizar la partícula (como lo harías normalmente en el método Update)
        p->Update(time);
    }
}

