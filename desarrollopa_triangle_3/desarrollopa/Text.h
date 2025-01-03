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
    string text;
    // Atributo que contiene el texto a mostrar
public:
    // Constructor por defecto
    Text() : text("") {}

    // Constructor con texto inicial
    Text(const string& initialText, float initialScale)
        : text(initialText) {}

    // Establece el texto
    void SetText(const string& newText);

    // Obtener texto
    const string& GetText() const {
        return text;
    }

   
    Solid* Clone() const override {
        return new Text(*this);  // Constructor copia para clonar
    }
    // Sobrescribe el m�todo Render
    void Render();
};


