#include "Student.h"
#include <iostream>

int main() {
    std::vector<Student> students;
    std::string first, last;
    for (int i = 0; i < 5; i++) {
        std::cout << "Enter student " << i << " firstname [space] lastname: ";
        std::cin >> first >> last;
        students.push_back(Student(first, last));
    }
    print_all_students(students);
    sort_last_name(students);
    print_all_students(students);
}