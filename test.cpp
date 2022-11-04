#include <iostream>
#include <cstring>

void f2(double &d) {
    d *= 2;
}

void f1(double d) {
    d *= 2;
    f2(d);
}

int main() {
    double dub = 2.5;
    f1(dub);
    std::cout << dub << std::endl;
}