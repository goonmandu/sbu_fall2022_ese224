#include <iostream>
#include <fstream>

int main() {
    std::ifstream fin;
    std::ofstream fout;
    std::string content;

    fin.open("input.dat");
    if (fin.fail()) {
        std::cerr << "Error opening input file!" << std::endl;
        return 1;
    }

    fout.open("output.dat");
    if (fout.fail()) {
        std::cerr << "Error opening output file!" << std::endl;
        return 2;
    }

    fin >> content;
    fout << content;

    fin.close();
    fout.close();
}