#pragma once
#include "Solid.h"
#include "Model.h"
#include <GL/glut.h>


using namespace std;

class Text : public Solid {
private:
    string text; 

public:

    Text() : text("") {}

    Text(const string& initialText, float initialScale)
        : text(initialText) {}

    void SetText(const string& newText);
    const string& GetText() const { return text; }

    Solid* Clone() const override {
        return new Text(*this);  
    }

    void Render() override;
};


