#include <iostream>
#include <iomanip>
#include <cmath>
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

double Rectangle::area(void) const {
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
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Origin: (" << get_x_coord() << ", " << get_y_coord() << ")" << std::endl;
    std::cout << "Width: " << std::setw(10) << std::left << get_width() << ", Height: " << std::setw(10) << std::left << get_height() << std::endl;
}

bool Rectangle::operator> (const Rectangle &rhs) {
    return (this->area() > rhs.area());
}

double Rectangle::operator- (const Rectangle &rhs) {
    return fabs(this->area() - rhs.area());
}

double Rectangle::compute_IOU (const Rectangle &rhs) {
    Rectangle r1, r2;
    double overlap;
    if (this->x_coord < rhs.x_coord) {
        r1 = *this;
        r2 = rhs;
    } else {
        r1 = rhs;
        r2 = *this;
    }

    if (r1.y_coord < r2.y_coord) {
        overlap = (r1.x_coord + r1.width - r2.x_coord) * (r1.y_coord + r1.height - r2.y_coord);
    } else {
        overlap = (r1.x_coord + r1.width - r2.x_coord) * (r2.y_coord + r2.height - r1.x_coord);
    }

    return (overlap / (r1.area() + r2.area() - overlap));
}