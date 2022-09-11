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
        std::cout << diff << ", " << ((int) (diff * 100)) % 10 << std::endl;
        if (diff < 0.01) {
            std::cout << "Maximum recorded temperature is " << newmax << ".00°C" << std::endl;
        } else if (((int) (diff * 100)) % 10 < 0.01) {
            std::cout << "Maximum recorded temperature is " << newmax << "0°C" << std::endl;
        } else {
            std::cout << "Maximum recorded temperature is " << newmax << "°C" << std::endl;
        }
    } else {
        std::cout << "No valid temperature was recorded." << std::endl;
    }
}