#include <iostream>
#include <fstream>

int main() {
    std::ifstream fin;
    std::ofstream fout;
    std::string line;

    fin.open("inputfile");
    if (fin.fail()) {
        std::cerr << "Error while opening input file!" << std::endl;
        return 1;
    }

    fout.open("outputfile");
    if (fout.fail()) {
        std::cerr << "Error while opening output file!" << std::endl;
        return 1;
    }

    for (int i = 0; i < 250; i++) {
        fout << i << " ";
    }

    fout << "\n";

    while (std::getline(fin, line)) {
        std::cout << line << std::endl;
        fout << line;
    }
}