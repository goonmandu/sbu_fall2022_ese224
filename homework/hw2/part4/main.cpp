#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cmath>

const double PI = 3.141592653589793;

double rmse(std::vector<double> dvec) {
    double sum = 0;
    for (double item : dvec) {
        double result = pow(fabs(item - 1), 2);
        sum += result;
    }
    return sqrt(sum / dvec.size());
}

int main() {
    std::fstream sine, cosine, result;
    int points;
    sine.open("sine.txt", std::fstream::out);
    if (sine.fail()) {
        std::cerr << "Error opening sine file!" << std::endl;
        return 2;
    }
    cosine.open("cosine.txt", std::fstream::out);
    if (cosine.fail()) {
        std::cerr << "Error opening cosine file!" << std::endl;
        return 2;
    }
    result.open("result.txt", std::fstream::out);
    if (result.fail()) {
        std::cerr << "Error opening result file!" << std::endl;
        return 2;
    }

    std::cout << "How many values to interpolate (min 50): ";
    std::cin >> points;

    for (int i = 0; i < points; i++) {
        sine << std::setprecision(2) << std::showpoint << std::fixed << 360 * ((double) i / points)\
             << '\t' << sin(2 * PI * ((double) i / points)) << std::endl;
        cosine << std::setprecision(2) << std::showpoint << std::fixed << 360 * ((double) i / points)\
               << '\t' << cos(2 * PI * ((double) i / points)) << std::endl;
    }
    sine.close();
    cosine.close();

    sine.open("sine.txt", std::fstream::in);
    cosine.open("cosine.txt", std::fstream::in);

    double s, c, sinval, cosval;
    for (int i = 0; i < points; i++) {
        sine >> s >> sinval;
        cosine >> c >> cosval;
        result << pow(sinval, 2) + pow(cosval, 2) << std::endl;
    }
    result.close();

    result.open("result.txt");
    double resval;
    std::vector<double> identity;
    for (int i = 0; i < points; i++) {
        result >> resval;
        identity.push_back(resval);
    }

    std::cout << "Root mean square error is " << rmse(identity) << std::endl;
    return 0;
}