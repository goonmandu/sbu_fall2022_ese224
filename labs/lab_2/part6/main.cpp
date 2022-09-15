#include <iostream>
#include <cmath>

int main() {
    int digit;
    int iters = 0;
    int reversed = 0;
    int input, number;
    std::cout << "Enter an integer: ";
    std::cin >> input;
    number = input;
    int digits = (int) log10(number);
    
    while (number) {
        digit = number % 10;
        reversed += digit * pow(10, digits - iters);
        iters++;
        number /= 10;
    }

    std::cout << "Reversed: " << reversed << std::endl;
    if (fabs(input - reversed) < 0.001) {
        std::cout << "The given integer is palindromic.";
    } else {
        std::cout << "The given number is not palindromic.";
    }
    std::cout << std::endl;
}