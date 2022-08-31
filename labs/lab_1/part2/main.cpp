#include <iostream>
#include "Rectangle.h"

int main() {
    Rectangle r1 = Rectangle();
    Rectangle r2 = Rectangle(2, 3, 6, 9);
    r2.print_attribs();
    r2.make_mirror_origin();
    r2.print_attribs();
    r2.make_mirror_x();
    r2.print_attribs();
    r2.make_mirror_y();
    r2.print_attribs();
    
    return 0;
}