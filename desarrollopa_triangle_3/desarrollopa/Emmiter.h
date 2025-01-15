#pragma once
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
        return new Emmiter(*this); 
    }

    // M�todos
    void Render(); 
    void Update(const float& time);  
};



