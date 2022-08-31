#include <iostream>
#include "WaterLevel.h"

int main() {
    WaterLevel monitor = WaterLevel();
    double data;

    for (int i = 0; i < 10; i++) {
        std::cout << "Enter data #" << monitor.get_count() + 1 << ": " << std::endl;
        std::cin >> data;
        monitor.new_data(data);
        monitor.print_stats();
    }
}