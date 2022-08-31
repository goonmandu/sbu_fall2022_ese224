#include <iostream>
#include "Rectangle.h"

Rectangle::Rectangle(void) {
    x_coord = 0;
    y_coord = 0;
    width = 1;
    height = 1;
}

Rectangle::Rectangle(double x, double y, double w, double h) {
    x_coord = x;
    y_coord = y;
    width = w;
    height = h;
}

double Rectangle::get_x_coord(void) {
    return x_coord;
}

double Rectangle::get_y_coord(void) {
    return y_coord;
}

double Rectangle::get_width(void) {
    return width;
}

double Rectangle::get_height(void) {
    return height;
}

double Rectangle::area(void) {
    return height * width;
}

void Rectangle::make_mirror_origin(void) {
    x_coord *= -1;
    y_coord *= -1;
}

void Rectangle::make_mirror_x(void) {
    y_coord *= -1;
}

void Rectangle::make_mirror_y(void) {
    x_coord *= -1;
}

void Rectangle::print_attribs(void) {
    std::cout << "Coords: (" << get_x_coord() << ", " << get_y_coord() << "), Dims: " << get_width() << "W, "
              << get_height() << "H, Area: " << area() << std::endl << std::endl;
}