#include <iostream>
#include "Grade.h"

int main() {
    Grade g1 = Grade();
    Grade g2 = Grade(69, 42, 74, 96);
    g1.print_attribs();
    g2.print_attribs();
    g1.set_homework(12);
    g1.set_lab(34);
    g1.set_project(56);
    g1.set_finalexam(78);
    g1.print_attribs();
}