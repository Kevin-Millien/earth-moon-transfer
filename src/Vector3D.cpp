#include "Vector3D.hpp"

// Default Constructor
Vector3D::Vector3D() : x(0), y(0), z(0) {}

// Constructor
Vector3D::Vector3D(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}

// Member function to calculate the magnitude of the vector
double Vector3D::magnitude() const {
    return std::sqrt(x * x + y * y + z * z);
}