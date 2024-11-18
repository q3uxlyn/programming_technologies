// Разработать класс для работы с двумерными векторами (с двумя координатами).
// Методы для сложения, скалярного произведения векторов, вычисления длины вектора, умножения
// вектора на число.

#include <iostream>
#include "Vector2D.h"

int main() {
    try {
        Vector2D v1; // Конструктор по умолчанию
        Vector2D v2(3.0, 4.0); // Параметризированный конструктор

        std::cout << "Вектор v1 (по умолчанию): " << v1 << std::endl;
        std::cout << "Вектор v2: " << v2 << std::endl;

        // Демонстрация методов доступа
        std::cout << "v2.x = " << v2.getX() << ", v2.y = " << v2.getY() << std::endl;

        // Демонстрация вычисления длины
        std::cout << "Длина v2: " << v2.length() << std::endl;

        // Демонстрация сложения векторов
        Vector2D v3 = v1 + v2;
        std::cout << "v1 + v2 = " << v3 << std::endl;

        // Демонстрация умножения на скаляр
        double scalar = 2.5;
        Vector2D v4 = v2 * scalar;
        std::cout << "v2 * " << scalar << " = " << v4 << std::endl;

        // Демонстрация скалярного произведения
        double dot = v2.dotProduct(v4);
        std::cout << "Скалярное произведение v2 и v4: " << dot << std::endl;

    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
