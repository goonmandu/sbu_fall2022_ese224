#include <iostream>

double soom(double a, double b) {
    return a + b;
}

// Call by value
int cbv_add_1(int num) {
    // A copy of the data passed in is stored inside the function.
    num += 1;
    // The operation is done to the COPY, not the ORIGINAL.
    return num;
    // We can return num, since it was initialized as a data copy.
}

// Call by reference
int cbr_add_1(int &num) {
    // The MEMORY ADDRESS is passed into the function as num.
    num += 1;
    // The operation is done on the ORIGINAL value in memory, since a pointer was passed in.
    return num;
    // We need to return the memory location POINTED BY num.
}

int main() {
    int i = 3;
    std::cout << "i is " << i << std::endl;
    std::cout << "Value returned by calling cbv_add_1(i): " << cbv_add_1(i) << std::endl;
    std::cout << "i is still " << i << std::endl;
    std::cout << "Value returned by calling cbr_add_1(i): " << cbr_add_1(i) << std::endl;
    std::cout << "Now, i is " << i << std::endl;
}