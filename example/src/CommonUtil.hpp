#pragma once
#include "ofMain.h"

class PhysicValue {
public:
    PhysicValue(){};
    PhysicValue(float mass, float gravity, float velocityLimit) : mass(mass),gravity(gravity),velocityLimit(velocityLimit) {
        position = 0., velocity = 0., acceleration = 0.;
        lowerLimit = 0., upperLimit = 1.;
    };
    
    void update(){
        velocity += acceleration;
        velocity -= gravity;
        if (velocity > velocityLimit) velocity = velocityLimit;
        
        position += velocity;
        if (isUpper && position > upperLimit) position = upperLimit;
        if (isLower && position < lowerLimit) {
            position = lowerLimit;
            velocity = 0.;
        }
        
        acceleration = 0.;
    };
    
    float get(){ return position; };
    
    void addForce(float force){
        acceleration += force / mass;
    };
    
    void setUpperLimit(float upperLimit){
        PhysicValue::upperLimit = upperLimit;
    };
    
    void enableUpperLimit(){ isUpper = true; };
    
    void setLowerLimit(float lowerLimit){
        PhysicValue::lowerLimit = lowerLimit;
    };
    
    void enableLowerLimit(){ isLower = true; };
    
    void setGravity(float gravity){
        PhysicValue::gravity = gravity;
    };
    
    void setVelocityLimit();
    
private:
    float mass;
    float lowerLimit, upperLimit;
    float acceleration, velocity, position;
    float gravity;
    float velocityLimit;
    bool isUpper, isLower;
};

