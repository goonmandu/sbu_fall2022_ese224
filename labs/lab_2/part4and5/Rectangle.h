#pragma once

class Rectangle {
    private:
        double x_coord, y_coord;
        double width, height;

    public:
        Rectangle(void);
        Rectangle(double x, double y, double w, double h);
        double get_x_coord(void);
        double get_y_coord(void);
        double get_width(void);
        double get_height(void);
        double area(void) const;
        void make_mirror_x(void);
        void make_mirror_y(void);
        void make_mirror_origin(void);
        void print_attribs(void);
        bool operator> (const Rectangle &);
        double operator- (const Rectangle &);
        double compute_IOU(const Rectangle &);
};