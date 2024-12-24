#pragma once
#include <vector>
#include <chrono>
#include "Solid.h"
#include "EmmiterConfiguration.h"

using namespace std;
using namespace std::chrono;

class Emmiter : public Solid {
private:
    EmmiterConfiguration config;          // Configuración del emisor
    vector<Solid*> particulas;            // Vector de partículas generadas
    milliseconds initialMilliseconds;     // Tiempo de inicio de la ejecución
    long lastUpdateTime;                  // Último tiempo de emisión

public:
    // Constructor
    Emmiter(const EmmiterConfiguration& config);

    Emmiter* Clone() const override {
        return new Emmiter(*this);  // Devuelve un clon del emisor
    }


    // Métodos
    void Render();  // Renderiza todas las partículas
    void Update();  // Controla la frecuencia de emisión y crea nuevas partículas
};



