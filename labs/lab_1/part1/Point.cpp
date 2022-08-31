#include <math.h>
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

double Point::dist_to_origin(void) {
    return sqrt(pow(x_coord, 2) + pow(y_coord, 2));
}