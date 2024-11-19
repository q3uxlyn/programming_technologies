#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>
#include <cmath>

class Vector2D {
private:
    double x; // Координата x
    double y; // Координата y

public:
    // Конструктор по умолчанию
    Vector2D();

    // Конструктор с параметрами
    Vector2D(double x, double y);

    // Методы для доступа с координатами
    double getX() const;
    double getY() const;

    // Метод для вычисления длины вектора
    double length() const;

    // Метод для вычисления скалярного произведения
    double dotProduct(const Vector2D& other) const;

    // Оператор сложения двух векторов
    Vector2D operator+(const Vector2D& other) const;

    // Оператор умножения вектора на скаляр
    Vector2D operator*(double scalar) const;

    // Функция для перегрузки оператора вывода в поток
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& vec);
};

#endif
