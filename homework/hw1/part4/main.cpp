#include <iostream>
#include "Book.h"

int main() {
    Book whatif = Book(1, "What If?", "Randall Munroe", "Nonfiction", 320);
    Book whatif2 = whatif;
    whatif2.set_number(2);
    whatif2.set_title("What if? 2");
    whatif2.set_pages(368);

    Book highcastle = Book(3, "The Man in the High Castle", "Philip K. Dick", "Alternate History", 288);
    Book ggs = Book(4, "Guns, Germs, and Steel", "Jared Diamond", "Nonfiction", 480);
    Book tcpl = Book(5, "The C Programming Language", "Brian Kernighan & Dennis Ritchie", "Tutorials", 228);

    whatif.print_stats();
    std::cout << std::endl;
    whatif2.print_stats();
    std::cout << std::endl;
    highcastle.print_stats();
    std::cout << std::endl;
    ggs.print_stats();
    std::cout << std::endl;
    tcpl.print_stats();
}