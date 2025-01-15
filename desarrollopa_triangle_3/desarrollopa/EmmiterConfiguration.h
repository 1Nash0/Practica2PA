#pragma once
#include "Solid.h"

class EmmiterConfiguration {
private:

    int numParticulas;            // N�mero m�ximo de part�culas
    int tiempoEmision;            // Intervalo de tiempo de emisi�n en milisegundos
    Solid* particulaRef;          // Part�cula de referencia

public:
    // Constructor 
    EmmiterConfiguration(int numParticulas, int tiempoEmision, Solid* particulaRef)
        : numParticulas(numParticulas), tiempoEmision(tiempoEmision), particulaRef(particulaRef) {}

    // M�todos de acceso

    inline int GetNumParticulas() const { return this->numParticulas; }
    inline void SetNumParticulas(const int& numParticulasToSet) { this->numParticulas = numParticulasToSet; }
    inline int GetTiempoEmision() const { return this->tiempoEmision; }
    inline void SetTiempoEmision(const int& tiempoEmisionToSet) { this->tiempoEmision = tiempoEmisionToSet; }
    inline Solid* GetParticula() const { return this->particulaRef; }
    inline void GetParticula(Solid*& particulaRefToSet) { this->particulaRef = particulaRefToSet; }

};
