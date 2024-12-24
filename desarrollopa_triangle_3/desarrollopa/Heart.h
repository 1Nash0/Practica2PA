#include "Solid.h"
#include "Model.h"
#include "Color.h"
#include <GL/glut.h>
#include <string>
#include <iostream>

using namespace std;

class Heart : public Solid {
private:

    int vidas; // Número de vidas asociadas al corazón
    float size;
    Model* model3D;

public:
    // Constructor por defecto
    Heart()
        : size(1.0), model3D(nullptr), Solid() {}

    // Constructor parametrizado
    Heart(int inicialVidas);

    // Getter para obtener el número de vidas
    int getVidas() const;

    // Método para sumar vidas
    void sumarVidas(int cantidad);

    // Método para mostrar la cantidad de vidas
    void mostrarVidas() const;

    void SetModel3D(Model* model) {
        if (model) {
            this->model3D = model;
        }
        else {
            std::cerr << "[Player::SetModel3D] Modelo nulo pasado como argumento." << std::endl;
        }
    }

    void Render();
};







