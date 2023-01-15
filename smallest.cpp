#include <fstream>
#include <iostream>

int main() {
    std::ifstream fin;
    int read;
    int smallest = INT_MIN;
    fin.open("numbers.txt");
    while (!fin.eof()) {
        fin >> read;
        if (!read) {
            std::cout << smallest << std::endl;
            smallest = INT32_MAX;
            continue;
        }
        if (read < smallest) {
            smallest = read;
        }
    }
}