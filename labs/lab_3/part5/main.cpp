#include <iostream>

long long int fib(int num) {
    if (num < 2) {
        return num;
    } else {
        return fib(num - 1) + fib(num - 2);
    }
}

int main() {
    int in;
    std::cout << "Enter a number: ";
    std::cin >> in;
    std::cout << fib(in) << std::endl;
}