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


// Implementaci�n del m�todo Render() que invoca Render en todas las part�culas
void Emmiter::Render() {
    for (auto p : particulas) {
        p->Render();
    }
}

// Implementaci�n del m�todo Update() que controla la frecuencia de emisi�n y crea nuevas part�culas

void Emmiter::Update(const float& time) {

    milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());


    // Verificar si ha pasado el tiempo de emisi�n configurado
    if (currentTime.count() - this->initialMilliseconds.count() - this->lastUpdateTime > this->config.GetTiempoEmision() && particulas.size() < config.GetNumParticulas()) {
        // Crear nueva part�cula clonando la part�cula de referencia
        Solid* newParticula = config.GetParticula()->Clone();


        newParticula->SetPosition(Vector3D(
            (rand() % 100 - 25),  
            (rand() % 100 - 25),
            -20.0f               // Fijo en Z (puedes ajustarlo seg�n tu necesidad)
        ));
        //newParticula->SetColor(Color((float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX, 1.0f));  // Color aleatorio
        newParticula->SetOrientation(Vector3D(1.0, 0.0, 0.0));  // Orientaci�n aleatoria
        newParticula->SetOrientationSpeed(Vector3D(
            (rand() % 10 - 5) / 2.0f,
            (rand() % 10 - 5) / 2.0f,
            (rand() % 10 - 5) / 2.0f));

        //Vector3D velocity((rand() % 100 - 50) / 10000.0f,
        //    (rand() % 100 - 50) / 10000.0f,
        //    (rand() % 100 - 50) / 10000.0f);
        //newParticula->SetVelocity(velocity);  // Asignar la velocidad a la part�cula

        // A�adir la nueva part�cula al vector

        particulas.push_back(newParticula);

        // Actualizar el tiempo del �ltimo update

        this->lastUpdateTime = currentTime.count() - this->initialMilliseconds.count();
    }

    // Actualizar todas las part�culas
    for (auto p : particulas) {
        // Mover las part�culas en su direcci�n de velocidad

        Vector3D position = p->GetPosition();
        Vector3D velocity = p->GetVelocity();
       /* position = position + velocity; */ // Desplazar la part�cula

        // Rebote cuando la part�cula se sale de los l�mites 

        if (position.x < -25 || position.x > 25) velocity.x *= -1;
        if (position.y < -25 || position.y > 25) velocity.y *= -1;
        if (position.z < -25 || position.z > 25) velocity.z *= -1;


        p->SetPosition(position);  // Actualizar la posici�n de la part�cula
        p->SetVelocity(velocity);  // Actualizar la velocidad

        // Actualizar la part�cula (como lo har�as normalmente en el m�todo Update)
        p->Update(time);
    }
}

