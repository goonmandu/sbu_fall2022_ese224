#include <iostream>
#include "Student.h"
#include "Library.h"

int main() {
    Library lib = Library();
    lib.delete_book(4);
    lib.print_all_books();
    //           ^^^^^^^^this function returns a Book struct^^^^^^^^
}