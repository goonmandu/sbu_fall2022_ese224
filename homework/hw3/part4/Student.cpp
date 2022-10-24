#include "Student.h"
#include <iostream>

Student::Student(std::string first, std::string last) {
    first_name = first;
    last_name = last;
}

std::string Student::get_first_name() {
    return first_name;
}

std::string Student::get_last_name() {
    return last_name;
}

int strcmp(const char* s1, const char* s2) {
    while(*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

void swap(Student &s1, Student &s2) {
    Student temp = s1;
    s1 = s2;
    s2 = temp;
}

void sort_last_name(std::vector<Student> &vec) {
    int sorted = 0;
    while (sorted < vec.size() - 1) {
        sorted = 0;
        for (int i = 0; i < vec.size() - 1; i++) {
            if (strcmp(vec[i].get_last_name().c_str(), vec[i+1].get_last_name().c_str()) > 0) {
                swap(vec[i], vec[i+1]);
            } else {
                sorted++;
            }
        }
    }
}

void print_all_students(std::vector<Student> vec) {
    for (Student student : vec) {
        std::cout << "First name: " << student.get_first_name() << ", Last name: " << student.get_last_name() << std::endl;
    }
    std::cout << std::endl;
}