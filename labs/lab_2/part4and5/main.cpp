#include <iostream>
#include "Line.h"



int main() {
    double m, b;
    /*
    std::cout << "Slope and y-intercept: ";
    std::cin >> m >> b;
    Line l1 = Line(m, b);
    l1.print_attribs();
    std::cout << "Multiplying slope by 2.5" << std::endl;
    l1 * 2.5;
    l1.print_attribs();
    

    std::cout << "Slope and y-intercept: ";
    std::cin >> m >> b;
    Line l2 = Line(m, b);
    l2.print_attribs();
    std::cout << "Incrementing y-intercept by 6.9" <<std::endl;
    l2 + 6.9;
    l2.print_attribs();
     */

    
    Line l3 = Line(0.5, -0.5);
    Rectangle r1 = Rectangle(2, 1, 3, 2);
    std::cout << l3.intersects(r1) << std::endl;

    // std::cout << "Are the two lines equal after modifications: " << (l1 == l2) << std::endl;
}