#include "Vector2D.h"

// Конструктор по умолчанию: инициализируем координаты x и y нулями
Vector2D::Vector2D() : x(0.0), y(0.0) {}

// Параметризированный конструктор: инициализируем x и y заданными значениями
Vector2D::Vector2D(double x, double y) : x(x), y(y) {
    // Проверяем, что координаты конечны (не NaN или бесконечные)
    if (!std::isfinite(x) || !std::isfinite(y)) {
        throw std::invalid_argument("Координаты должны быть конечными числами.");
    }
}

// Метод доступа для получения значения x
double Vector2D::getX() const {
    return x;
}

// Метод доступа для получения значения y
double Vector2D::getY() const {
    return y;
}

// Метод для вычисления длины вектора
double Vector2D::length() const {
    return std::sqrt(x * x + y * y);
}

// Метод для вычисления скалярного произведения с другим вектором
double Vector2D::dotProduct(const Vector2D& other) const {
    return x * other.x + y * other.y;
}

// Оператор сложения двуух векторов
Vector2D Vector2D::operator+(const Vector2D& other) const {
    return Vector2D(x + other.x, y + other.y);
}

// Оператор умножения вектора на скаляр
Vector2D Vector2D::operator*(double scalar) const {
    return Vector2D(x * scalar, y * scalar);
}

// Перегрузка оператора вывода в поток для отображения вектора
std::ostream& operator<<(std::ostream& os, const Vector2D& vec) {
    os << "(" << vec.x << ", " << vec.y << ")";
    return os;
}
