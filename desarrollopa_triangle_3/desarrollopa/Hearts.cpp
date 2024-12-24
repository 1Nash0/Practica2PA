#include "Hearts.h"
#include <iostream>



// Constructor parametrizado
Hearts::Hearts(int inicialVidas) : vidas(inicialVidas) {}

// Getter para obtener el número de vidas
int Hearts::getVidas() const {
    return vidas;
}

// Método para sumar vidas
void Hearts::sumarVidas(int cantidad) {
    if (cantidad > 0) {
        vidas += cantidad;
    }
}

// Método para mostrar la cantidad de vidas
void Hearts::mostrarVidas() const {
    std::cout << "Vidas: " << vidas << std::endl;
}

void Hearts::Render()
{

    if (model3D) {
        model3D->Render();
    }
    else {
        // Si no hay modelo, dibuja una representación básica o lanza un error
        std::cout << "[Player] No model set for rendering!" << std::endl;
    }

}

