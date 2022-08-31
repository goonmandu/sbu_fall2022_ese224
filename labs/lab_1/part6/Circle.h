#pragma once

class Circle {
    private:
        double cx, cy;
        double radius;
    
    public:
        Circle();
        Circle(double x, double y, double r);
        double get_cx();
        double get_cy();
        double get_radius();
        int contains(int x, int y);
        double dist(int x, int y);
};