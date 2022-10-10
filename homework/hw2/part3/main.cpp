#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

long long int fib(int num) {
    if (num < 2) {
        return num;
    }
    long long int i1 = 0;
    long long int i2 = 1;
    long long int n;
    for (int i = 0; i <= num - 2; i++) {
        n = i1 + i2;
        i1 = i2;
        i2 = n;
    }
    return n;
}

void print_fib(std::vector<long long int> vec) {
    std::reverse(vec.begin(), vec.end());
    for (long long int item : vec) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

int upright(std::vector<long long int> vec) {
    int num_rows;
    while (1) {
        for (int i = 0; i < num_rows; i++) {
            // std::cout << "row" << i << "\n";
            for (int j = 0; j < i; j++) {
                std::cout << vec.back() << "\t";
                vec.pop_back();
                if (vec.empty()) {
                    break;
                }
            }
            num_rows++;
            std::cout << std::endl;
            if (vec.empty()) {
                return 0;
            }
        }
    }
}

void inverted(std::vector<long long int> vec) {
    int num_rows = 0, veclen = vec.size();
    while (veclen >= 0) {
        num_rows++;
        veclen -= num_rows;
    }

    if (veclen < 0) {
        veclen *= -1;
    }
    if (veclen == num_rows) {
        veclen = 0;
        num_rows--;
    }
    
    for (int i = num_rows; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (veclen) {
                std::cout << "-\t";
                veclen--;
            } else {
                std::cout << vec.back() << '\t';
                vec.pop_back();
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    int terms;
    std::vector<long long int> sequence;
    
    std::cout << "How many terms? ";
    std::cin >> terms;

    for (int i = 0; i < terms; i++) {
        sequence.push_back(fib(i));
    }
    std::reverse(sequence.begin(), sequence.end());

    print_fib(sequence);
    // std::cout << std::endl;
    upright(sequence);
    std::cout << std::endl;
    inverted(sequence);

    return 0;
}