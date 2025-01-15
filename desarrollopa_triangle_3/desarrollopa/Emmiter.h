#pragma once
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
        return new Emmiter(*this); 
    }

    // Métodos
    void Render(); 
    void Update(const float& time);  
};



