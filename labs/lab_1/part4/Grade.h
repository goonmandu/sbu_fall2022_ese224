#pragma once

class Grade {
    private:
        double homework;
        double lab;
        double project;
        double finalexam;
        double overall;

    public:
        Grade();
        Grade(double homework, double lab, double project, double finalexam);
        void new_overall();
        double get_homework();
        double get_lab();
        double get_project();
        double get_finalexam();
        double get_overall();
        void set_homework(double homework);
        void set_lab(double lab);
        void set_project(double project);
        void set_finalexam(double finalexam);
        void print_attribs();
};