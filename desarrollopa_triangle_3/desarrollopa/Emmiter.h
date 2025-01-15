#pragma once
#include <chrono>
#include "Solid.h"
#include "EmmiterConfiguration.h"

using namespace std;
using namespace std::chrono;

class Emmiter : public Solid {
private:

    EmmiterConfiguration config;         
    vector<Solid*> particulas;           
    milliseconds initialMilliseconds;     
    long lastUpdateTime;                  

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



