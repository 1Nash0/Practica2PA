#pragma once
#include "Vector3D.h"
#include "Color.h"
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

class Solid {
private:
    Vector3D position;
    Vector3D speed;
    Vector3D orientation;
    Vector3D orientationSpeed;
    Vector3D velocity;
    Color color;
    float collisionRadius; // Radio para detecci�n de colisiones esf�ricas
    bool wired;
    bool isMarkedForDeletion = false;
    bool isAffectedByGravity = false; // Indica si el objeto est� afectado por gravedad
    Vector3D gravity = Vector3D(-0.0005f, 0.0, 0.0f); // Gravedad est�ndar
public:
    Solid(
        Color colorArgument = Color(),
        Vector3D positionArgument = Vector3D(),
        Vector3D speedArgument = Vector3D(),
        Vector3D orientationArgument = Vector3D(),
        Vector3D orientationSpeedArgument = Vector3D(),
        float collisionRadiusArgument = 1.0f)
        : color(colorArgument),
        position(positionArgument),
        speed(speedArgument),
        velocity(Vector3D(0, 0, 0)),
        orientation(orientationArgument),
        orientationSpeed(orientationSpeedArgument),
        collisionRadius(collisionRadiusArgument),
        wired(false),
        isAffectedByGravity(false) {}
    virtual ~Solid() {}

    void SetAffectedByGravity(bool affected);
    bool GetIsAffectedByGravity() const;
    void MarkForDeletion() { isMarkedForDeletion = true; }
    bool IsMarkedForDeletion() const { return isMarkedForDeletion; }
    // M�todos Getter
    inline Vector3D GetPosition() const { return position; }
    inline Vector3D GetSpeed() const { return speed; }
    inline Vector3D GetOrientation() const { return orientation; }
    inline Vector3D GetVelocity() const { return velocity; }
    inline Vector3D GetOrientationSpeed() const { return orientationSpeed; }
    inline Color GetColor() const { return color; }
    inline bool GetWired() const { return wired; }
 
    inline float GetCollisionRadius() const { return collisionRadius; }

    // M�todos Setter
    inline void SetPosition(const Vector3D& coordsToSet) { position = coordsToSet; }
    inline void SetSpeed(const Vector3D& speedToSet) { speed = speedToSet; }
    inline void SetOrientation(const Vector3D& orientationToSet) { orientation = orientationToSet; }
    inline void SetOrientationSpeed(const Vector3D& orientationSpeedToSet) { orientationSpeed = orientationSpeedToSet; }
    inline void SetVelocity(const Vector3D& velocityToSet) { velocity = velocityToSet; }
    virtual void SetColor(const Color& colorToSet) { color = colorToSet; }
    inline void SetWired(bool wiredToSet) { wired = wiredToSet; }
    inline void SetCollisionRadius(float collisionRadiusToSet) { collisionRadius = collisionRadiusToSet; }

    // M�todos para detecci�n de colisiones
    virtual bool CheckCollision(const Solid* other) const;

    virtual void ProcessCollisions(const std::vector<Solid*>& objects); // Nuevo m�todo
    virtual void OnCollision(Solid* other); // Nuevo m�todo
   // bool CheckBoundingBoxCollision(const Solid* other) const;
    // M�todos virtuales para sobrecargar
    virtual void Render() = 0;
    virtual void Update(const float& deltaTime);
  

    // Cambia 'string' a 'std::string' para evitar el error de especificador de invalidaci�n desconocido
    virtual std::string GetType() const { return "Unknown"; }
    virtual Solid* Clone() const = 0;

};


