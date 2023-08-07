
#pragma once
#include "Vector3D.hpp"

class Moon
{
    
    public:
    double distance; //in km
    double delta; //inclination in degress
    double rightAscension; //24h

    Vector3D position;
    Vector3D speed;

    double Mass;

    Moon();

    double fx(double x, double y, double z);
    double fy(double x, double y, double z);
    double fz(double x, double y, double z);

    void updatePositionAndVelocity(double timeStep);
    
};