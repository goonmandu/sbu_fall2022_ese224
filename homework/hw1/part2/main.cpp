#include <iostream>
#include <iomanip>
#include <cctype>

int main() {
    char letter_grade;

    std::cout << "Enter letter grade: ";
    std::cin >> letter_grade;

    std::cout << std::fixed << std::setprecision(2);

    switch (toupper(letter_grade)) {
        case 'A':
            std::cout << 4.00 << std::endl;
            break;
        case 'B':
            std::cout << 3.00 << std::endl;
            break;
        case 'C':
            std::cout << 2.00 << std::endl;
            break;
        case 'D':
            std::cout << 1.00 << std::endl;
            break;
        case 'F':
            std::cout << 0.00 << std::endl;
            break;
        default:
            std::cerr << "Invalid letter grade. Enter A, B, C, D, or F." << std::endl;
    }
}