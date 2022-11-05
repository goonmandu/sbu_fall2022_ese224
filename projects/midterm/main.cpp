#include <iostream>
#include "Student.h"
#include "Library.h"

int main() {
    Library lib = Library();
    lib.delete_book(4);
    lib.print_all_books();
    Book book1;
    

    //           ^^^^^^^^this function returns a Book struct^^^^^^^^
}