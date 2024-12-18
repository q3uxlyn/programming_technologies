// Фигура: прямоугольник
// Конструтор принимает 2 точки: левый нижний и правый верхний углы
// Считается, что стороны прямоугольника параллельны осям координат
// Центром фигуры считается точка пересечения диагоналей
#include "rectangle.h"
#include <cmath>

Rectangle::Rectangle(const Point& ll, const Point& ur) : lowerLeft(ll), upperRight(ur) {
    // Проверка, что координаты корректны
    // нижний левый угол ниже и левее верхнего правого
    if (lowerLeft.x >= upperRight.x || lowerLeft.y >= upperRight.y) {
        throw std::invalid_argument("Invalid rectangle coordinates: lowerLeft must be below and to the left of upperRight.");
    }
}

double Rectangle::getArea() const {
    // Вычисление площади прямоугольника
    double width = upperRight.x - lowerLeft.x;
    double height = upperRight.y - lowerLeft.y;
    return width * height;
}

Point Rectangle::getCenter() const {
    // Вычисление центра прямоугольника
    Point center;
    center.x = (lowerLeft.x + upperRight.x) / 2.0;
    center.y = (lowerLeft.y + upperRight.y) / 2.0;
    return center;
}

void Rectangle::scale(double factor) {
    // Масштабирование прямоугольника относительно его центра
    if (factor <= 0) {
        throw std::invalid_argument("Scale factor must be positive.");
    }
    Point center = getCenter();
    double halfWidth = (upperRight.x - lowerLeft.x) / 2.0 * factor;
    double halfHeight = (upperRight.y - lowerLeft.y) / 2.0 * factor;
    lowerLeft.x = center.x - halfWidth;
    lowerLeft.y = center.y - halfHeight;
    upperRight.x = center.x + halfWidth;
    upperRight.y = center.y + halfHeight;
}

std::string Rectangle::getName() const {
    return "RECTANGLE";
}
