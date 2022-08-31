#include <iostream>
#include <string>
#include "Rectangle.h"

class Rectangle {
    private:
        double height;
        double width;
        std::string gender;

    public:
        double area(void) {
            return width * height;
        }

        std::string get_gender(void) {
            return gender;
        }
        
    // Constructor
    Rectangle(double w, double h, std::string g) {
        width = w;
        height = h;
        gender = g;
    }
};