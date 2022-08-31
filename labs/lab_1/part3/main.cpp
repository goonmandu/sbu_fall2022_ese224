#include <iostream>
#include "Student.h"

int main() {
    Student s1 = Student();
    Student s2 = Student("Mingi Hwang", "114639231", "Computer Engineering", "mingi.hwang@stonybrook.edu");
    s1.print_attribs();
    s2.print_attribs();
    s1.set_name("Default Constructor");
    s1.set_id("987654321");
    s1.set_major("Computer Science");
    s1.set_email("default.constructor@stonybrook.edu");
    s1.print_attribs();
}