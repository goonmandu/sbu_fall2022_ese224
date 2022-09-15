#include <iostream>
#include "Line.h"
#include "Rectangle.h"

Line::Line() {
    slope = 0;
    y_intercept = 0;
}

Line::Line(double slope, double y_intercept) {
    this->slope = slope;
    this->y_intercept = y_intercept;
}

double Line::get_slope() const {
    return slope;
}

double Line::get_y_intercept() const {
    return y_intercept;
}

bool Line::operator== (const Line &rhs) const {
    return (this->slope == rhs.slope && this->y_intercept == rhs.y_intercept);
}

void Line::operator* (double coeff) {
    this->slope = this->slope * coeff;
}

void Line::operator+ (double incr) {
    this->y_intercept = this->y_intercept + incr;
}

void Line::print_attribs() {
    std::cout << "y = " << slope << "x + (" << y_intercept << ")" << std::endl;
}

bool Line::intersects(Rectangle &r) const {
    double v1, v2, h1, h2;
    v1 = r.get_x_coord() * this->slope + this->y_intercept;
    v2 = (r.get_x_coord() + r.get_width()) * this->slope + this->y_intercept;
    h1 = (r.get_y_coord() - this->y_intercept) / this->slope;
    h2 = (r.get_y_coord() + r.get_height() - this->y_intercept) / this->slope;
    if ((r.get_y_coord() <= v1 && v1 <= r.get_y_coord() + r.get_height()) ||
        (r.get_y_coord() <= v2 && v2 <= r.get_y_coord() + r.get_height()) ||
        (r.get_x_coord() <= h1 && h1 <= r.get_x_coord() + r.get_width()) ||
        (r.get_x_coord() <= h2 && h2 <= r.get_x_coord() + r.get_width())) {
            return true;
    } else {
        return false;
    }
}
