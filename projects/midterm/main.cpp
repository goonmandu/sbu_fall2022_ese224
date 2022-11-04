#include <iostream>
#include "Student.h"
#include "Library.h"

int main() {
    Library lib = Library();
    std::cout << lib.search_id(761);
    //           ^^^^^^^^this function returns a Book struct^^^^^^^^
}