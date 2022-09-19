#include <iostream>
#include <fstream>

int main() {
    std::ifstream fin;
    fin.open("./input");
    if (fin.fail()) {
        std::cerr << "Error" << std::endl;
    }
    return 0;
}