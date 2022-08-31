#include <iostream>
#include "Student.h"

Student::Student() {
    name = "ESE224 TA";
    id = "123456789";
    major = "Electrical Engineering";
    email = "ese224ta@stonybrook.edu";
}

Student::Student(std::string name, std::string id, std::string major, std::string email) {
    this->name = name;
    this->id = id;
    this->major = major;
    this->email = email;
}

std::string Student::get_name() {
    return name;
}

std::string Student::get_id() {
    return id;
}

std::string Student::get_major() {
    return major;
}

std::string Student::get_email() {
    return email;
}

void Student::set_name(std::string name) {
    this->name = name;
}
void Student::set_id(std::string id) {
    this->id = id;
}

void Student::set_major(std::string major) {
    this->major = major;
}

void Student::set_email(std::string email) {
    this->email = email;
}

void Student::print_attribs() {
    std::cout << "Name: " << name << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "Major: " << major << std::endl;
    std::cout << "Email: " << email << std::endl;
}