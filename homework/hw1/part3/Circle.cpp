#include <iostream>
#include <iomanip>
#include "Circle.h"

Circle::Circle() {
    x = 0;
    y = 0;
    radius = 1;
}

Circle::Circle(double x, double y, double radius) {
    this->x = x;
    this->y = y;
    this->radius = radius;
}

double Circle::get_x() {
    return x;
}

double Circle::get_y() {
    return y;
}

double Circle::get_radius() {
    return radius;
}

void Circle::set_radius(double new_radius) {
    radius = new_radius;
}

void Circle::print_stats() {
    std::cout << "Circle center: (" << get_x() << ", " << get_y() << ")" << std::endl;
    std::cout << "Circle radius: " << get_radius() << std::endl << std::setw(10);
}

Circle Circle::operator* (double rhs) {
    this->set_radius(radius * rhs);
    return *this;
}

int Circle::operator== (const Circle &c) const {
    if (x == c.x && y == c.y && radius == c.radius) {
        return 1;
    } else {
        return 0;
    }
}