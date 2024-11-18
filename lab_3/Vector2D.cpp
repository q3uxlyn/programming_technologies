#include "Vector2D.h"

Vector2D::Vector2D() : x(0.0), y(0.0) {}

Vector2D::Vector2D(double x, double y) : x(x), y(y) {
    if (!std::isfinite(x) || !std::isfinite(y)) {
        throw std::invalid_argument("Координаты должны быть конечными числами.");
    }
}


double Vector2D::getX() const {
    return x;
}

double Vector2D::getY() const {
    return y;
}


double Vector2D::length() const {
    return std::sqrt(x * x + y * y);
}

double Vector2D::dotProduct(const Vector2D& other) const {
    return x * other.x + y * other.y;
}

Vector2D Vector2D::operator+(const Vector2D& other) const {
    return Vector2D(x + other.x, y + other.y);
}

Vector2D Vector2D::operator*(double scalar) const {
    return Vector2D(x * scalar, y * scalar);
}


std::ostream& operator<<(std::ostream& os, const Vector2D& vec) {
    os << "(" << vec.x << ", " << vec.y << ")";
    return os;
}
