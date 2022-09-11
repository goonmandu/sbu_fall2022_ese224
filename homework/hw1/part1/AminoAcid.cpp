#include <iostream>
#include "AminoAcid.h"

AminoAcid::AminoAcid() {
    O = 0;
    C = 0;
    N = 0;
    S = 0;
    H = 0;
}

AminoAcid::AminoAcid(int O, int C, int N, int S, int H) {
    this->O = O;
    this->C = C;
    this->N = N;
    this->S = S;
    this->H = H;
}

int AminoAcid::get_O() {
    return O;
}

int AminoAcid::get_C() {
    return C;
}

int AminoAcid::get_N() {
    return N;
}

int AminoAcid::get_S() {
    return S;
}

int AminoAcid::get_H() {
    return H;
}

double AminoAcid::get_molecular_weight() {
    return O * O_weight + C * C_weight + N * N_weight + S * S_weight + H * H_weight;
}