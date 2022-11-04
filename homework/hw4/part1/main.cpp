#include <iostream>
#include <cstring>

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::cin >> input;
    int len = input.size() + 1;
    char *cptr;
    cptr = new char[len];
    char *printing_ptr = cptr;
    for (char c : input) {
        if (c == 'g') {
            *(cptr++) = 'b';
        } else if (c == 'b') {
            *(cptr++) = 'a';
        } else {
            *(cptr++) = c;
        }
    }
    *cptr = '\0';
    while (*printing_ptr) {
        std::cout << *(printing_ptr++);
    }
    std::cout << std::endl;
}
