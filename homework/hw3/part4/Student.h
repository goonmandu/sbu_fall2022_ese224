#pragma once
#include <string>
#include <vector>

class Student {
    private:
        std::string first_name;
        std::string last_name;

    public:
        Student(std::string first, std::string last);
        std::string get_first_name();
        std::string get_last_name();
};

int strcmp(const char* s1, const char *s2);
void sort_last_name(std::vector<Student> &vec);
void print_all_students(std::vector<Student> vec);