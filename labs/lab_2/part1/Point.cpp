#include <iostream>
#include <math.h>
#include <iomanip>
#include "Point.h"

Point::Point() {
    x_coord = 0;
    y_coord = 0;
}

Point::Point(double x, double y) {
    x_coord = x;
    y_coord = y;
}

double Point::get_x_coord(void) {
    return x_coord;
}

double Point::get_y_coord(void) {
    return y_coord;
}

void Point::set_x_coord(double x) {
    x_coord = x;
}

void Point::set_y_coord(double y) {
    y_coord = y;
}

double Point::dist_to_origin(void) const {
    return sqrt(pow(x_coord, 2) + pow(y_coord, 2));
}

double Point::distance(const Point &rhs) const {
    return sqrt(pow(this->x_coord - rhs.x_coord, 2) + pow(this->y_coord - rhs.y_coord, 2));
}

double Point::operator- (const Point &rhs) const {
    return sqrt(pow(this->x_coord - rhs.x_coord, 2) + pow(this->y_coord - rhs.y_coord, 2));
}

int Point::equals(const Point &rhs) const {
    return (this->x_coord == rhs.x_coord && this->y_coord == rhs.y_coord) ? 1 : 0;
}

int Point::operator== (const Point &rhs) const {
    return (this->x_coord == rhs.x_coord && this->y_coord == rhs.y_coord) ? 1 : 0;
}

void Point::print() {
    std::cout << std::fixed << std::setprecision(3);
    std::cout << "x = " << x_coord << ", y = " << y_coord << std::endl;
}

Point Point::operator* (int coeff) {
    this->x_coord = 3 * this->x_coord;
    this->y_coord = 3 * this->y_coord;
    return *this;
}

int Point::operator> (const Point &rhs) {
    return (this->dist_to_origin() > rhs.dist_to_origin()) ? 1 : 0;
}