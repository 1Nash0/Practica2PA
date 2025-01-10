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



void Emmiter::Update(const float& time) {

    milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());


    // Verificar si ha pasado el tiempo de emisión configurado
    if (currentTime.count() - this->initialMilliseconds.count() - this->lastUpdateTime > this->config.GetTiempoEmision() && particulas.size() < config.GetNumParticulas()) {
        Solid* newParticula = config.GetParticula()->Clone();

        newParticula->SetPosition(Vector3D(
            (rand() % 100 - 40),  
            (rand() % 100 - 25),
            -20.0f               
        ));
        newParticula->SetOrientation(Vector3D(1.0, 0.0, 0.0));  
        newParticula->SetOrientationSpeed(Vector3D(0.0, (rand() % 10 - 5) / 2.0f, 0.0));

        particulas.push_back(newParticula);

        this->lastUpdateTime = currentTime.count() - this->initialMilliseconds.count();
    }

    for (auto p : particulas) {


        Vector3D position = p->GetPosition();
        Vector3D velocity = p->GetVelocity();


        p->SetPosition(position);  // Actualizar la posición de la partícula
        p->SetVelocity(velocity);  // Actualizar la velocidad


        p->Update(time);
    }
}

