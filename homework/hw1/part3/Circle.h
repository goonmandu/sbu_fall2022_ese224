#pragma once
#include <iostream>

class Circle {
    private:
        double x, y;
        double radius;
    
    public:
        Circle();
        Circle(double x, double y, double radius);
        double get_x();
        double get_y();
        double get_radius();
        void set_radius(double new_radius);
        void print_stats();

        Circle operator* (double rhs);
        int operator== (const Circle &c) const;
};