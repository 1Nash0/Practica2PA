// Vector3D.h

class Vector3D
{
private:
    

public:
    float x, y, z;

    Vector3D() : x(0.0), y(0.0), z(0.0) {}
    Vector3D(float xArgument, float yArgument, float zArgument)
        : x(xArgument), y(yArgument), z(zArgument) {}

    inline float GetX() const { return this->x; }
    inline float GetY() const { return this->y; }
    inline float GetZ() const { return this->z; }

    inline void SetX(const float& xToSet) { this->x = xToSet; }
    inline void SetY(const float& yToSet) { this->y = yToSet; }
    inline void SetZ(const float& zToSet) { this->z = zToSet; }


    // Operadores existentes para sumar, restar, y multiplicar
    Vector3D Add(Vector3D& other);
    Vector3D operator+(Vector3D& other);
    Vector3D Product(float a);
    Vector3D operator*(float a);
    Vector3D operator-(Vector3D& other);
};
