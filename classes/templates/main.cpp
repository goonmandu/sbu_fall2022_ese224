#include <iostream>

// T is a placeholder data type name.
// The program will figure out the correct data type
// that T needs to be at runtime.
// This lets you write one do-it-all function
// instead of having separate functions for each data type.

template<typename T>
void swap(T &a, T &b) {  // You can also pass-by-reference by putting the &.
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template <typename T>
void printpair(T a, T b) {
    std::cout << a << ", " << b << std::endl;
}

int main() {
    int a = 420, b = 69;
    double x = 3.142, y = 1.414;

    std::cout << "Before the swap:" << std::endl;
    printpair(a, b);  // even though a, b are ints and x, y are doubles,
    printpair(x, y);  // they can use one function definition

    swap(a, b);
    swap(x, y);

    std::cout << "After the swap:" << std::endl;
    printpair(a, b);
    printpair(x, y);
}