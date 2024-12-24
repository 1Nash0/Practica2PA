#pragma once
#include "Solid.h"
#include "Model.h"
#include "Color.h"
#include <GL/glut.h>
#include <string>
#include <iostream>


using namespace std;
class Text : public Solid {
private:
    string text; // Atributo que contiene el texto a mostrar
public:
    // Constructor por defecto
    Text() : text(""), Solid() {}

    // Establece el texto
    void SetText(const string& newText)
    {
        text = newText;
    };

    // Obtiene el texto actual
   
    Solid* Clone() const override {
        return new Text(*this);  // Constructor copia para clonar
    }
    // Sobrescribe el método Render
    void Render();
};


