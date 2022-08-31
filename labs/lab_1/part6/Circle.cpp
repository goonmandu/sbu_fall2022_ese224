#include <iostream>
#include <math.h>
#include "Circle.h"

Circle::Circle() {
    cx = 0;
    cy = 0;
    radius = 1;
}

Circle::Circle(double cx, double cy, double radius) {
    this->cx = cx;
    this->cy = cy;
    this->radius = radius;
}

double Circle::get_cx() {
    return cx;
}

double Circle::get_cy() {
    return cy;
}

double Circle::get_radius() {
    return radius;
}

int Circle::contains(int x, int y) {
    if (pow(cx - x, 2) + pow(cy - y, 2) < pow(radius, 2)) {
        return 1;
    } else {
        return 0;
    }
}

double Circle::dist(int x, int y) {
    return sqrt(pow(cx - x, 2) + pow(cy - y, 2));
}