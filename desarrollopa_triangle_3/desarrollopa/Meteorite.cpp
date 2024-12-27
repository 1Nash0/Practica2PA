#include "Meteorite.h"


void Meteorite::Render() 
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
		// Si no hay modelo, dibuja una representaci�n b�sica o lanza un error
		std::cout << "[Meteorite] No model set for rendering!" << std::endl;
	}
	glPopMatrix();
}

void Meteorite::SetModel3D(Model* model) {
	if (model) {
		this->model3D = model;
	}
	else {
		std::cerr << "[Meteorite::SetModel3D] Modelo nulo pasado como argumento." << std::endl;
	}
}
//
//bool CheckCollision(const Solid& other) {
//	// L�gica espec�fica para la colisi�n con meteoritos
//	// Devuelve true si hay colisi�n con otro objeto
//	return false; // Ejemplo
//}