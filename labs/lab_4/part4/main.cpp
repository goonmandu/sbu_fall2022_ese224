#include <iostream>

long long int fib(int num);

int main() {
    int steps;
    std::cout << "How many steps in the staircase: ";
    std::cin >> steps;
    std::cout << "There are " << fib(steps + 1) << " way(s) to get to the top." << std::endl;
}

long long int fib(int num) {
    if (num < 2) {
        return num;
    }
    long long int i1 = 0;
    long long int i2 = 1;
    long long int n;
    for (int i = 0; i <= num - 2; i++) {
        n = i1 + i2;
        i1 = i2;
        i2 = n;
    }
    return n;
}