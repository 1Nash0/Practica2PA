#pragma once
#include <vector>
#include <chrono>
#include "Solid.h"
#include "EmmiterConfiguration.h"

using namespace std;
using namespace std::chrono;

class Emmiter : public Solid {
private:
    EmmiterConfiguration config;          // Configuraci�n del emisor
    vector<Solid*> particulas;            // Vector de part�culas generadas
    milliseconds initialMilliseconds;     // Tiempo de inicio de la ejecuci�n
    long lastUpdateTime;                  // �ltimo tiempo de emisi�n

public:
    // Constructor
    Emmiter(const EmmiterConfiguration& config);

    Emmiter* Clone() const override {
        return new Emmiter(*this);  // Devuelve un clon del emisor
    }


    // M�todos
    void Render();  // Renderiza todas las part�culas
    void Update();  // Controla la frecuencia de emisi�n y crea nuevas part�culas
};



