//
// Created by romap on 18.06.2023.
//

#ifndef SEMINAR_7_CIRCLE_H
#define SEMINAR_7_CIRCLE_H


#include <cmath>
#include "Figure.h"

class Circle : public Figure {
private:
    double radius;

public:
    Circle(double circleRadius) : radius(circleRadius) {}

    double get_perimeter() const override {
        return 2 * M_PI * radius;
    }

    double get_area() const override {
        return M_PI * radius * radius;
    }
};


#endif //SEMINAR_7_CIRCLE_H
