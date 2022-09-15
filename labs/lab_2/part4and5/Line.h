#pragma once
#include "Rectangle.h"

class Line {
    private:
        double slope, y_intercept;
    
    public:
        Line();
        Line(double slope, double y_intercept);
        double get_slope() const;
        double get_y_intercept() const;
        bool operator== (const Line &rhs) const;
        void operator* (double coeff);
        void operator+ (double incr);
        void print_attribs();
        bool intersects(Rectangle &r) const;
};