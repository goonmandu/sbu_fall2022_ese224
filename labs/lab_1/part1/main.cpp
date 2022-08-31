#include <iostream>
#include "Point.h"

int main() {
    double x, y;
    std::cout << "Creating a point with the default constructor..." << std::endl;
    Point p1 = Point();

    std::cout << "Create a point with the parameterized constructor (x, y): " << std::endl;
    std::cin >> x >> y;
    Point p2 = Point(x, y);
    std::cout << "The points of p2 are (" << p2.get_x_coord() << ", " << p2.get_y_coord() << ")" << std::endl;

    std::cout << "Change x_coord of p2: " << std::endl;
    std::cin >> x;
    p2.set_x_coord(x);
    std::cout << "The points of p2 are (" << p2.get_x_coord() << ", " << p2.get_y_coord() << ")" << std::endl;

    std::cout << "Change y_coord of p2: " << std::endl;
    std::cin >> y;
    p2.set_y_coord(y);
    std::cout << "The points of p2 are (" << p2.get_x_coord() << ", " << p2.get_y_coord() << ")" << std::endl;

    std::cout << "The distance from the origin of p2 is " << p2.dist_to_origin() << std::endl;
    return 0;
}