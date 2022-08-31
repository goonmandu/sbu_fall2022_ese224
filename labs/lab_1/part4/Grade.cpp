#include <iostream>
#include "Grade.h"

Grade::Grade() {
    homework = 100;
    lab = 100;
    project = 100;
    finalexam = 100;
    overall = 100;
}

Grade::Grade(double homework, double lab, double project, double finalexam) {
    this->homework = homework;
    this->lab = lab;
    this->project = project;
    this->finalexam = finalexam;
    new_overall();
}

void Grade::new_overall() {
    overall = homework * 0.2 + lab * 0.15 + project * 0.35 + finalexam * 0.3;
}

double Grade::get_homework() {
    return homework;
}

double Grade::get_lab() {
    return lab;
}

double Grade::get_project() {
    return project;
}

double Grade::get_finalexam() {
    return finalexam;
}

double Grade::get_overall() {
    return overall;
}

void Grade::set_homework(double homework) {
    this->homework = homework;
    new_overall();
}

void Grade::set_lab(double lab) {
    this->lab = lab;
    new_overall();
}

void Grade::set_project(double project) {
    this->project = project;
    new_overall();
}

void Grade::set_finalexam(double finalexam) {
    this->finalexam = finalexam;
    new_overall();
}

void Grade::print_attribs() {
    std::cout << "Homework: " << get_homework() << std::endl;
    std::cout << "Labs:     " << get_lab() << std::endl;
    std::cout << "Project:  " << get_project() << std::endl;
    std::cout << "Final:    " << get_finalexam() << std::endl;
    std::cout << "Overall:  " << get_overall() << std::endl << std::endl;
}