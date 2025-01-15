#pragma once
#include "Solid.h"

class EmmiterConfiguration {
private:

    int numParticulas;            // Número máximo de partículas
    int tiempoEmision;            // Intervalo de tiempo de emisión en milisegundos
    Solid* particulaRef;          // Partícula de referencia

public:
    // Constructor 
    EmmiterConfiguration(int numParticulas, int tiempoEmision, Solid* particulaRef)
        : numParticulas(numParticulas), tiempoEmision(tiempoEmision), particulaRef(particulaRef) {}

    // Métodos de acceso

    inline int GetNumParticulas() const { return this->numParticulas; }
    inline void SetNumParticulas(const int& numParticulasToSet) { this->numParticulas = numParticulasToSet; }
    inline int GetTiempoEmision() const { return this->tiempoEmision; }
    inline void SetTiempoEmision(const int& tiempoEmisionToSet) { this->tiempoEmision = tiempoEmisionToSet; }
    inline Solid* GetParticula() const { return this->particulaRef; }
    inline void GetParticula(Solid*& particulaRefToSet) { this->particulaRef = particulaRefToSet; }

};
