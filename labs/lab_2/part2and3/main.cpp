#include <iostream>
#include "Rectangle.h"

int main() {
    double x, y, w, h;
    std::cout << "x, y, w, h: ";
    std::cin >> x >> y >> w >> h;
    Rectangle r1 = Rectangle(x, y, w, h);
    r1.print_attribs();

    std::cout << "x, y, w, h: ";
    std::cin >> x >> y >> w >> h;
    Rectangle r2 = Rectangle(x, y, w, h);
    r2.print_attribs();

    std::cout << "Is r1 bigger than r2: " << (r1 > r2) << std::endl;
    std::cout << "Difference in area between r1 and r2: " << (r1 - r2) << std::endl;
    std::cout << "IOU of r1 and r2 is: " << r1.compute_IOU(r2) << std::endl;
    
    return 0;
}