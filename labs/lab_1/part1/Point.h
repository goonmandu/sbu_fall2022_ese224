#pragma once

class Point {
    private:
        double x_coord;
        double y_coord;

    public:
        Point();
        Point(double, double);
        double get_x_coord(void);
        double get_y_coord(void);
        void set_x_coord(double);
        void set_y_coord(double);
        double dist_to_origin(void);
};