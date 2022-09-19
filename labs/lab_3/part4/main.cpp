#include <iostream>
#include <fstream>

int main() {
    std::ifstream fin;
    std::ofstream fout;
    int entries;
    double w, h;
    double rectmax = 0, rwmax = 0, rhmax = 0;
    double squmax = 0, swmax = 0, shmax = 0;
    double rectsum = 0, squsum = 0, rectcount = 0, squcount = 0;

    fin.open("./data3.dat");
    if (fin.fail()) {
        std::cerr << "Error opening input file!" << std::endl;
        return 1;
    }

    fout.open("./output.dat");
    if (fout.fail()) {
        std::cerr << "Error opening output file!" << std::endl;
        return 2;
    }

    do {
        fin >> w >> h;
        // std::cout << w << " " << h << std::endl;
        if (w == h) {
            if (w * h >= squmax) {
                squmax = w * h;
                swmax = w;
                shmax = h;
            }
            squsum += w * h;
            squcount++;
        } else {
            if (w * h >= rectmax) {
                rectmax = w * h;
                rwmax = w;
                rhmax = h;
            }
            rectsum += w * h;
            rectcount++;
        }
    } while (!fin.eof());
    std::cout << "Max rectangle area: " << rectmax << ", Width: " << rwmax << ", Height: " << rhmax << std::endl;
    std::cout << "Max square area: " << squmax << ", Width: " << swmax << ", Height: " << shmax << std::endl;
    std::cout << "Average rectangle area: " << rectsum / rectcount << std::endl;
    std::cout << "Average square area: " << squsum / squcount << std::endl;
}