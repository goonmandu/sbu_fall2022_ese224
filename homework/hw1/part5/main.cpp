#include <iostream>
#include <cmath>

int main() {
    double temp, max = -1;
    do {
        std::cout << "Enter a temperature: ";
        std::cin >> temp;
        if (temp > max) {
            max = temp;
        }
    } while (temp > 0);
    double diff = fabs(max - (int) max);
    double newmax = (int) (max * 100) / (double) 100;
    if (max > -1) {
        std::cout.setf(std::ios::fixed);
        std::cout.precision(2);
        std::cout << max << std::endl;
    } else {
        std::cout << "No valid temperature was recorded." << std::endl;
    }
}