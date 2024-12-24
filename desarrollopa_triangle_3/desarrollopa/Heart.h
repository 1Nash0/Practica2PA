#include "Solid.h"
#include "Model.h"
#include "Color.h"
#include <GL/glut.h>
#include <string>
#include <iostream>

using namespace std;

class Heart : public Solid {
private:

    int vidas; // N�mero de vidas asociadas al coraz�n
    float size;
    Model* model3D;

public:
    // Constructor por defecto
    Heart()
        : size(1.0), model3D(nullptr), Solid() {}

    // Constructor parametrizado
    Heart(int inicialVidas);

    // Getter para obtener el n�mero de vidas
    int getVidas() const;

    // M�todo para sumar vidas
    void sumarVidas(int cantidad);

    // M�todo para mostrar la cantidad de vidas
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







