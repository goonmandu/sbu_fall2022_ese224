#include <iostream>
#include <iomanip>
#include <cmath>
#include "Rectangle.h"

Rectangle::Rectangle(void) {
    x_coord = 0;
    y_coord = 0;
    width = 1;
    height = 1;
}

Rectangle::Rectangle(double x, double y, double w, double h) {
    x_coord = x;
    y_coord = y;
    width = w;
    height = h;
}

double Rectangle::get_x_coord(void) {
    return x_coord;
}

double Rectangle::get_y_coord(void) {
    return y_coord;
}

double Rectangle::get_width(void) {
    return width;
}

double Rectangle::get_height(void) {
    return height;
}

double Rectangle::area(void) const {
    return height * width;
}

void Rectangle::make_mirror_origin(void) {
    x_coord *= -1;
    y_coord *= -1;
}

void Rectangle::make_mirror_x(void) {
    y_coord *= -1;
}

void Rectangle::make_mirror_y(void) {
    x_coord *= -1;
}

void Rectangle::print_attribs(void) {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Origin: (" << get_x_coord() << ", " << get_y_coord() << ")" << std::endl;
    std::cout << "Width: " << std::setw(10) << std::left << get_width() << ", Height: " << std::setw(10) << std::left << get_height() << std::endl;
}

bool Rectangle::operator> (const Rectangle &rhs) {
    return (this->area() > rhs.area());
}

double Rectangle::operator- (const Rectangle &rhs) {
    return fabs(this->area() - rhs.area());
}

double Rectangle::compute_IOU (Rectangle &rhs) {
    Rectangle r1, r2;
    double iw, ih, overlap;

    if (this->get_x_coord() >= rhs.get_x_coord()) {
        r2 = *this;
        r1 = rhs;
    } else {
        r2 = rhs;
        r1 = *this;
    }
    
    double Ax1, Ax2, Ay1, Ay2, Bx1, Bx2, By1, By2;

    Ax1 = r1.get_x_coord();
    Ay1 = r1.get_y_coord();
    Ax2 = r1.get_x_coord() + r1.get_width();
    Ay2 = r1.get_y_coord() + r1.get_height();
    Bx1 = r2.get_x_coord();
    By1 = r2.get_y_coord();
    Bx2 = r2.get_x_coord() + r2.get_width();
    By2 = r2.get_y_coord() + r2.get_height();

    // std::cout << "Ax1: " << Ax1 << ", Ax2: " << Ax2 << ", Ay1: " << Ay1 << ", Ay2 :" << Ay2 << std::endl;
    // std::cout << "Bx1: " << Bx1 << ", Bx2: " << Bx2 << ", By1: " << By1 << ", By2 :" << By2 << std::endl;

    if (Ax2 >= Bx1 && Ax1 <= Bx1 && Ax2 <= Bx2) {
        iw = fabs(Ax2 - Bx1);
        // std::cout << "iw: " << iw << std::endl;
        if (By1 >= Ay1) {
            ih = fabs(Ay2 - By1);
        } else {
            ih = fabs(By2 - Ay1);
        }
        // std::cout <<"ih: " << ih << std::endl;
    } else if (Ax1 <= Bx1 && Ax2 >= Bx2 && Ay1 <= By1 && Ay2 >= By2) {
        // std::cout << "inside" << std::endl;
        iw = fabs(Ax1 - Ax2) - fabs(Ax1 - Bx1) - fabs(Ax2 - Bx2);
        ih = fabs(Ay1 - Ay2) - fabs(Ay1 - By1) - fabs(Ay2 - By2);
    } else if (Ay2 < By1 || Ax2 < Bx1) {
        iw = 0;
        ih = 0;
    } else {
        std::cout << "This case has not been implemented due to lab requirements and time constraints." << std::endl;
    }

    overlap = ih * iw;
    return (overlap / (r1.area() + r2.area() - overlap));
}