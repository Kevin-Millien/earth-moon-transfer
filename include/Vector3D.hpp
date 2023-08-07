#pragma once

#include <cmath>
class Vector3D {
public:
    double x;
    double y;
    double z;

    // Constructor
    Vector3D();
    Vector3D(double x_, double y_, double z_);

    // Member functions
    double magnitude() const;

    void setValues(double x_, double y_, double z_) 
    {
    x = x_;
    y = y_;
    z = z_;
    }   

     void setX(double x_) 
    {
    x = x_;
  
    }   

};