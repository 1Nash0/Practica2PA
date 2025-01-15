#include "Text.h"


void Text::Render() {

    glPushMatrix();
    glColor4f(this->GetColor().GetRed(), this->GetColor().GetGreen(), this->GetColor().GetBlue(), this->GetColor().GetAlpha());
    glTranslatef(this->GetPosition().GetX(), this->GetPosition().GetY(), this->GetPosition().GetZ());
    glRasterPos3d(0, 0, 0);
    for (char c : text)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    glPopMatrix();
}

void Text::SetText(const string& newText) {
    text = newText;
}
