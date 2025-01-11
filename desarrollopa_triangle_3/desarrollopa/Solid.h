#pragma once
#include "Vector3D.h"
#include "Color.h"
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Solid {
private:
    Vector3D position;
    Vector3D speed;
    Vector3D orientation;
    Vector3D orientationSpeed;
    Vector3D velocity;
    Color color;
    float collisionRadius; // Radio para detección de colisiones esféricas
    bool wired;
    bool isMarkedForDeletion = false;
    bool isAffectedByGravity = false; // Indica si el objeto está afectado por gravedad
    Vector3D gravity = Vector3D(-0.001f, 0.0, 0.0f); // Gravedad estándar
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
   

    
    
    void MarkForDeletion() { isMarkedForDeletion = true; }
    bool IsMarkedForDeletion() const { return isMarkedForDeletion; }

    // Métodos Getter
    inline Vector3D GetPosition() const { return position; }
    inline Vector3D GetSpeed() const { return speed; }
    inline Vector3D GetOrientation() const { return orientation; }
    inline Vector3D GetVelocity() const { return velocity; }
    inline Vector3D GetOrientationSpeed() const { return orientationSpeed; }
    inline Color GetColor() const { return color; }
    inline bool GetWired() const { return wired; }
    inline float GetCollisionRadius() const { return collisionRadius; }
    inline bool GetIsAffectedByGravity() const { return isAffectedByGravity; }

    // Métodos Setter
    inline void SetPosition(const Vector3D& coordsToSet) { position = coordsToSet; }
    inline void SetSpeed(const Vector3D& speedToSet) { speed = speedToSet; }
    inline void SetOrientation(const Vector3D& orientationToSet) { orientation = orientationToSet; }
    inline void SetOrientationSpeed(const Vector3D& orientationSpeedToSet) { orientationSpeed = orientationSpeedToSet; }
    inline void SetVelocity(const Vector3D& velocityToSet) { velocity = velocityToSet; }
    inline void SetColor(const Color& colorToSet) { color = colorToSet; }
    inline void SetWired(bool wiredToSet) { wired = wiredToSet; }
    inline void SetCollisionRadius(float collisionRadiusToSet) { collisionRadius = collisionRadiusToSet; }
    inline void SetAffectedByGravity(bool affected) { isAffectedByGravity = affected; }

    // Métodos para detección de colisiones
    virtual bool CheckCollision(const Solid* other) const;
    virtual void ProcessCollisions(const vector<Solid*>& objects); 
    virtual void OnCollision(Solid* other); 


    virtual void Render() = 0;
    virtual void Update(const float& deltaTime);
  

  
    virtual string GetType() const { return "Unknown"; }
    virtual Solid* Clone() const = 0;

};


