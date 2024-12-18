// Фигура: кольцо
// Конструктор принимает точку центра и пару радиусов: внеешней и внутренней окружности соответственно.
// Центром фигуры считается центр окружностей
#include "ring.h"
#include <cmath>

// Определение константы pi
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Проверка корректности координат
Ring::Ring(const Point& c, double outerR, double innerR) : center(c), outerRadius(outerR), innerRadius(innerR) {
    // 1. Внешний радиус должен быть больше внутреннего
    // 2. Внутренний радиус должен быть больше 0
    if (outerRadius <= innerRadius || innerRadius <= 0) {
        throw std::invalid_argument("Invalid radii: require outerRadius > innerRadius > 0.");
    }
}

// Вычисление площади кольца
double Ring::getArea() const {
    return M_PI * (outerRadius * outerRadius - innerRadius * innerRadius);
}

// Получение центра кольца
Point Ring::getCenter() const {
    return center;
}

// Масштабирование кольца
void Ring::scale(double factor) {
    // Проверка, что коэффициент масштабирования положительный
    if (factor <= 0) {
        throw std::invalid_argument("Scale factor must be positive.");
    }
    // Увеличение внутреннего и внешнего радиусов на заданный коэффициент
    outerRadius *= factor;
    innerRadius *= factor;
}

std::string Ring::getName() const {
    return "RING";
}
