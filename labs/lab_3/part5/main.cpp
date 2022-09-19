#include <iostream>

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

int main() {
    std::cout << fib(10) << " " << fib(20) << " " << fib(30) << " " << fib(40) << " " << fib(50) << std::endl;
}