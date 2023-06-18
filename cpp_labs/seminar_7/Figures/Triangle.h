//
// Created by romap on 18.06.2023.
//

#ifndef SEMINAR_7_TRIANGLE_H
#define SEMINAR_7_TRIANGLE_H


#include <cmath>
#include "Figure.h"

class Triangle : public Figure {
private:
    double side1;
    double side2;
    double side3;

public:
    Triangle(double triangle_side1, double triangle_side2, double triangle_side3)
            : side1(triangle_side1), side2(triangle_side2), side3(triangle_side3) {}

    double get_perimeter() const override {
        return side1 + side2 + side3;
    }

    double get_area() const override {
        double semiperimeter = get_perimeter() / 2;
        return sqrt(semiperimeter * (semiperimeter - side1) * (semiperimeter - side2) * (semiperimeter - side3));
    }
};

#endif //SEMINAR_7_TRIANGLE_H
