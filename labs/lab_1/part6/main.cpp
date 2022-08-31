#include <iostream>
#include "Circle.h"

int main() {
    double x, y, r;
    double distance, max_dist = 0, x_at_max, y_at_max;
    std::cout << "Enter x, y, r: ";
    std::cin >> x >> y >> r;
    Circle circle = Circle(x, y, r);

    for (int xcand = (int) (circle.get_cx() - r); xcand <= (int) (circle.get_cx() + r); xcand++) {
        for (int ycand = (int) (circle.get_cy() - r); ycand <= (int) (circle.get_cy() + r); ycand++) {
            if (circle.contains(xcand, ycand)) {
                distance = circle.dist(xcand, ycand);
                if (distance >= max_dist) {
                    max_dist = distance;
                    x_at_max = xcand;
                    y_at_max = ycand;
                }
            }
        }
    }

    std::cout << "Integer coordinates that are farthest away from the center are (" << x_at_max << ", " << y_at_max << ")." << std::endl;
    std::cout << "The distance is " << max_dist << "." << std::endl;
}