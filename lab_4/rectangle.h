#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include "point.h"
#include <stdexcept>

class Rectangle : public Shape {
private:
    Point lowerLeft;
    Point upperRight;

public:
    Rectangle(const Point& ll, const Point& ur);

    virtual double getArea() const override;
    virtual void scale(double factor) override;
    virtual Point getCenter() const override;
    virtual std::string getName() const override;
};

#endif
