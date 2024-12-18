#include <iostream>
#include <vector>
#include <algorithm>
#include "shape.h"
#include "rectangle.h"
#include "ring.h"

int main() {
    try {
        // Контейнер для хранения указателей на объекты фигур
        std::vector<Shape*> shapes;
        // Создание и добавление нескольких Прямоугольников
        Point ll1 = {0.0, 0.0};
        Point ur1 = {4.0, 3.0};
        shapes.push_back(new Rectangle(ll1, ur1));

        Point ll2 = {1.0, 1.0};
        Point ur2 = {5.0, 5.0};
        shapes.push_back(new Rectangle(ll2, ur2));

        // Создание и добавление колец
        Point center1 = {2.0, 2.0};
        double outerR1 = 5.0;
        double innerR1 = 3.0;
        shapes.push_back(new Ring(center1, outerR1, innerR1));

        Point center2 = {0.0, 0.0};
        double outerR2 = 4.0;
        double innerR2 = 2.0;
        shapes.push_back(new Ring(center2, outerR2, innerR2));

        Point ll3 = {-3.0, -1.0};
        Point ur3 = {1.0, 2.0};
        shapes.push_back(new Rectangle(ll3, ur3));

        // Сортировка фигур по возрастанию площади
        std::sort(shapes.begin(), shapes.end(), [](Shape* a, Shape* b) -> bool {
            // Перегруженный оператор для стравнения площадей
            return *a < *b;
        });

        // Вывод информации о фигурах после сортировки
        std::cout << "Shapes sorted by area (ascending):\n";
        for (const auto& shape : shapes) {
            // Получение центра фигуры
            Point c = shape->getCenter();
            std::cout << shape->getName() << ": "
                      << "Center(" << c.x << ", " << c.y << "), "
                      << "Area = " << shape->getArea() << "\n";
        }

        // Запрос коэффициента масштабирования у пользователя
        double factor;
        std::cout << "\nEnter scale factor: ";
        std::cin >> factor;

        // Проверка, что коэффициент масштабирования положительный
        if (factor <= 0) {
            throw std::invalid_argument("Scale factor must be positive.");
        }

        // Масштабирование фигур
        for (auto& shape : shapes) {
            shape->scale(factor);
        }

        // Вывод информации о фигурах после масштабирования
        std::cout << "\nShapes after scaling by a factor of " << factor << ":\n";
        for (const auto& shape : shapes) {
            Point c = shape->getCenter();
            std::cout << shape->getName() << ": "
                      << "Center(" << c.x << ", " << c.y << "), "
                      << "Area = " << shape->getArea() << "\n";
        }

        // Освобождение памяти, выделенной для всех фигур
        for (auto& shape : shapes) {
            delete shape;
        }
    }
    catch (const std::exception& ex) {
        // Обработка возможных исключений
        std::cerr << "Error: " << ex.what() << "\n";
        return 1;
    }

    return 0;
}
