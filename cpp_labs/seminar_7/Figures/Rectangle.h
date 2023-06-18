//
// Created by romap on 18.06.2023.
//

#ifndef SEMINAR_7_RECTANGLE_H
#define SEMINAR_7_RECTANGLE_H


#include "Figure.h"

class Rectangle : public Figure {
private:
    double width;
    double height;

public:
    Rectangle(double rectangle_width, double rectangle_height) : width(rectangle_width), height(rectangle_height) {}

    double get_perimeter() const override {
        return 2 * (width + height);
    }

    double get_area() const override {
        return width * height;
    }
};

#endif //SEMINAR_7_RECTANGLE_H
