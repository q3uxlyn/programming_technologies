#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>

class Vector2D {
private:
    double x;
    double y;

public:
    Vector2D();

    Vector2D(double x, double y);

    double getX() const;
    double getY() const;

    double length() const;

    double dotProduct(const Vector2D& other) const;

    Vector2D operator+(const Vector2D& other) const;

    Vector2D operator*(double scalar) const;

    friend std::ostream& operator<<(std::ostream& os, const Vector2D& vec);
};

#endif
