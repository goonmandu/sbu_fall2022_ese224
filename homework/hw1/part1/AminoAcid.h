#pragma once
#include <iostream>

class AminoAcid {
    private:
        int O;
        int C;
        int N;
        int S;
        int H;

        const double O_weight = 15.9994;
        const double C_weight = 12.011;
        const double N_weight = 14.00674;
        const double S_weight = 32.066;
        const double H_weight = 1.00794;
        
    public:
        AminoAcid();
        AminoAcid(int O, int C, int N, int S, int H);
        int get_O();
        int get_C();
        int get_N();
        int get_S();
        int get_H();
        double get_molecular_weight();
};