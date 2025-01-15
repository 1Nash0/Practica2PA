#include "Obstacle.h"


bool Obstacle::CheckCollision(Solid* other) {
	if (other == nullptr) {
		return false;
	}
	return Solid::CheckCollision(other);
}

void Obstacle::SetModel3D(Model* model) {
	if (model) {
		this->model3D = model;
	}
	else {
		std::cerr << "Modelo nulo pasado como argumento." << std::endl;
	}
}