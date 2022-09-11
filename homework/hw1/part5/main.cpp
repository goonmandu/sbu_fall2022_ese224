#include <iostream>

int main() {
    double temp, max = -1;
    do {
        std::cout << "Enter a temperature: ";
        std::cin >> temp;
        if (temp > max) {
            max = temp;
        }
    } while (temp > 0);
    max = (int) (max * 10) / (double) 10;
    if (max > -1) {
        // std::cout << std::showpoint;
        std::cout << "Maximum recorded temperature is " << max << "°C" << std::endl;
    } else {
        std::cout << "No valid temperature was recorded." << std::endl;
    }
}