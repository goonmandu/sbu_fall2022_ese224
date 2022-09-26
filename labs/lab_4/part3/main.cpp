#include <iostream>
#include <cstdlib>
#include <ctime>

double randrange(double min, double max) {
    return min + (((double) rand() / RAND_MAX) * (max - min));
}

int main() {
    int count;
    double tot = 0, avg, min = 2, max = 1;
    srand(time(NULL));
    std::cout << "How many random numbers: ";
    std::cin >> count;
    for (int i = 0; i < count; i++) {
        double gen = randrange(1, 2);
        if (gen < min) {
            min = gen;
        }
        if (gen > max) {
            max = gen;
        }
        tot += gen;
        std::cout << gen << std::endl;
    }
    avg = tot / count;
    std::cout << "min = " << min << ", max = " << max << ", avg = " << avg << std::endl;
}