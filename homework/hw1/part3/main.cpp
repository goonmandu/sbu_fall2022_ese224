#include <iostream>
#include "Circle.h"

int main() {
    Circle circle = Circle(6, 9, 4.20);
    Circle another_circle = Circle(6, 9, 4.20 * 3);

    std::cout << "\"circle\" stats:" << std::endl;
    circle.print_stats();

    std::cout << "\nExpanding radius of \"circle\" by 3:" << std::endl;
    circle = circle * 3;

    std::cout << "New \"circle\" stats:" << std::endl;
    circle.print_stats();
    std::cout << "\n\"another_circle\" stats:" << std::endl;
    another_circle.print_stats();

    int equal = (circle == another_circle);

    std::cout << "\nIs circle the same as another_circle? " << equal << std::endl;
}