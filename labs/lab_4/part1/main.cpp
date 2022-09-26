#include <iostream>
#include <fstream>

void swap(double&, double&);

int main() {
    std::ifstream fin;
    std::ofstream fout;
    double v1, v2;

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
    
    do {
        fin >> v1 >> v2;
        swap(v1, v2);
        fout << v1 << " " << v2 << "\n";
    } while(!fin.eof());
}

void swap(double &num1, double &num2) {
    double temp = num1;
    num1 = num2;
    num2 = temp;
}