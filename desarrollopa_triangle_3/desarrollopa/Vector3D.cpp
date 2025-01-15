#include "Vector3D.h"
#include <cmath>

// M�todo para sumar dos vectores
Vector3D Vector3D::Add(const Vector3D& other)
{
	return Vector3D(this->x + other.x, this->y + other.y, this->z + other.z);
}

// Sobrecarga del operador + utilizando el m�todo Add
Vector3D Vector3D::operator+(const Vector3D& other)
{
	return this->Add(other);
}

// M�todo para multiplicar un vector por un escalar
Vector3D Vector3D::Product(const float a)
{
	return Vector3D(
		this->GetX() * a,
		this->GetY() * a,
		this->GetZ() * a);
}

// Sobrecarga del operador * utilizando el m�todo Product
Vector3D Vector3D::operator*(const float a)
{
	return this->Product(a);
}

// Sobrecarga del operador - para restar vectores
Vector3D Vector3D::operator-(const Vector3D& other)
{
	return Vector3D(
		this->GetX() - other.GetX(),
		this->GetY() - other.GetY(),
		this->GetZ() - other.GetZ());
}

// M�todo para calcular la longitud del vector
float Vector3D::Length() const
{
	return std::sqrt(x * x + y * y + z * z);
}

