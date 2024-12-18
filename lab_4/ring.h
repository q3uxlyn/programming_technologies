#ifndef RING_H
#define RING_H

#include "shape.h"
#include "point.h"
#include <stdexcept>

class Ring : public Shape {
private:
    Point center;
    double outerRadius;
    double innerRadius;

public:
    Ring(const Point& c, double outerR, double innerR);

    virtual double getArea() const override;
    virtual void scale(double factor) override;
    virtual Point getCenter() const override;
    virtual std::string getName() const override;
};

#endif
