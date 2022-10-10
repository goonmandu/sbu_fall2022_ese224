#include <iostream>
#include <fstream>
#include <algorithm>



int main() {
    std::ifstream fin;
    std::ofstream fout;
    std::string word, copy;

    fin.open("input");
    if (fin.fail()) {
        std::cerr << "Error opening input file!" << std::endl;
        return 1;
    }

    fout.open("newfile.txt");
    if (fout.fail()) {
        std::cerr << "Error opening output file!" << std::endl;
        return 2;
    }

    do {
        fin >> word;
        std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c){ return std::tolower(c); });
        copy = word;
        std::reverse(copy.begin(), copy.end());
        if (word == copy) {
            fout << word << std::endl;
        } else {
            std::cout << word << std::endl;
        }

    } while (!fin.eof());
}