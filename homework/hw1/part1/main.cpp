#include <iostream>
#include <iomanip>
#include "AminoAcid.h"

int main() {
    int o, c, n, s, h;

    std::cout << "How many oxygens? ";
    std::cin >> o;
    
    std::cout << "How many carbons? ";
    std::cin >> c;
    
    std::cout << "How many nitrogens? ";
    std::cin >> n;
    
    std::cout << "How many sulfurs? ";
    std::cin >> s;
    
    std::cout << "How many hydrogens? ";
    std::cin >> h;
    
    AminoAcid molecule = AminoAcid(o, c, n, s, h);

    std::cout << std::fixed << std::setprecision(3);
    std::cout << molecule.get_molecular_weight() << std::endl;

}