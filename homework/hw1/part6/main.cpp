#include <iostream>
#include <iomanip>

int main() {
    double temp, low;
    int no_data = 0;
    for (int i = 0; i < 7; i++) {
        if (!no_data) {
            low = temp;
            no_data = 1;
        }
        std::cout << "Enter a temperature: ";
        std::cin >> temp;
        if (temp < low) {
            low = temp;
        }
    }
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Lowest temperature recorded is " << low << "°C" << std::endl;
}