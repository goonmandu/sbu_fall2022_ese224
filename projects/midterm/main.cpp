#include <iostream>
#include "Student.h"
#include "Library.h"

int main() {
    /*
    Student student = Student();
    student.printUserdata(student.getUserdata(std::cin));
     */
    Library lib = Library();
    lib.print_book(lib.search_catalog_by_id(8, 0, lib.num_books()));
}