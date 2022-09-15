#include <iostream>
#include "Point.h"

int main() {
    double x, y;

    std::cout << "First point: ";
    std::cin >> x >> y;
    Point p1 = Point(x, y);
    p1.print();

    std::cout << "Second point: ";
    std::cin >> x >> y;
    Point p2 = Point (x, y);
    p2.print();

    std::cout << "Distance by function: " << p1.distance(p2) << std::endl;
    std::cout << "Distance by operator: " << p1 - p2 << std::endl;
    std::cout << "Are two points the same by function: " << p1.equals(p2) << std::endl;
    std::cout << "Are two points the same by operator: " << (p1 == p2) << std::endl;

    return 0;
}