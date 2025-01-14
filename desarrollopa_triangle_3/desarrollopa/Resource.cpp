#include "Resource.h"


bool Resource::CheckCollision(Solid* other) {
	if (other == nullptr) {
		return false;
	}
	return Solid::CheckCollision(other);
}

void Resource::SetModel3D(Model* model) {
	if (model) {
		this->model3D = model;
	}
	else {
		std::cerr << "Modelo nulo pasado como argumento." << std::endl;
	}
}