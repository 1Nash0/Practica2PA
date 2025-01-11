#include "Battery.h"


void Battery::Render()
{
	glPushMatrix();
	glTranslatef(this->GetPosition().GetX(), this->GetPosition().GetY(), this->GetPosition().GetZ());
	glColor4f(this->GetColor().GetRed(), this->GetColor().GetGreen(), this->GetColor().GetBlue(), this->GetColor().GetAlpha());
	glRotatef(this->GetOrientation().GetX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetOrientation().GetY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetOrientation().GetZ(), 0.0, 0.0, 1.0);
	if (model3D) {
		model3D->Render();
	}
	else {
		// Si no hay modelo, dibuja una representación básica o lanza un error
		std::cout << "No model set for rendering!" << std::endl;
	}
	glPopMatrix();
}

void Battery::SetModel3D(Model* model) {
	if (model) {
		this->model3D = model;
	}
	else {
		std::cerr << "[Meteorite::SetModel3D] Modelo nulo pasado como argumento." << std::endl;
	}
}
bool Battery::CheckCollision(Solid* other) {
	if (other == nullptr) { 
		return false;
	}
	return Solid::CheckCollision(other); 
}