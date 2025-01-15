// Vector3D.h



class Vector3D
{
private:

    float x, y, z;

public:

    Vector3D() : x(0.0f), y(0.0f), z(0.0f) {}
    Vector3D(float xArgument, float yArgument, float zArgument)
        : x(xArgument), y(yArgument), z(zArgument) {}

    inline float GetX() const { return this->x; }
    inline float GetY() const { return this->y; }
    inline float GetZ() const { return this->z; }

    inline void SetX(const float& xToSet) { this->x = xToSet; }
    inline void SetY(const float& yToSet) { this->y = yToSet; }
    inline void SetZ(const float& zToSet) { this->z = zToSet; }

    // Operadores existentes para sumar, restar, y multiplicar
    Vector3D Add(const Vector3D& other);
    Vector3D operator+(const Vector3D& other);
    Vector3D Product(const float a);
    Vector3D operator*(const float a);
    Vector3D operator-(const Vector3D& other);
    float Length() const;
};

