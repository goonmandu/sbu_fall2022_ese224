#include <iostream>
#include "Student.h"

int main() {
    Student student = Student();
    student.print_userdata(student.get_userdata(std::cin));
}