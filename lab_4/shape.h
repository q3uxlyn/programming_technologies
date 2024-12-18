// Определение абстрактного класса Shape. 
// Класс должен предоставлять следующие методы:
// - getArea вычисление площади
// - scale изотропное мсштабирование фигуры относительно ее центра с указанным коэффициентом
// - getCenter получение точки центра фигуры
// - getName получение названия фигуры (использовать при выводе) 
#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include "point.h"

class Shape {
public:
    // Виртуальный деструктор, для корректного освобождения ресурсов при наследовании 
    virtual ~Shape() = default;
    // Вычисление площади
    virtual double getArea() const = 0;
    // Масштабирование фигуры
    virtual void scale(double factor) = 0;
    // Получение центра фигуры
    virtual Point getCenter() const = 0;
    // Получение имени фигуры
    virtual std::string getName() const = 0;
};

// Перегрузка оператора "<" для сравнения двух фигур
inline bool operator<(const Shape& lhs, const Shape& rhs) {
    return lhs.getArea() < rhs.getArea();
}

#endif
