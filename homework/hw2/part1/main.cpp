#include <iostream>
#include <cmath>
#include <vector>

std::vector<int> generate_primes(int range) {
    std::vector<int> primes;
    primes.push_back(2);
    primes.push_back(3);
    for (int i = 0; i < range; i++) {
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) 
                break;
            else if (j + 1 > sqrt(i)) {
                primes.push_back(i);
            }
        }   
    }
    return primes;
}

void all_twosum(int num) {
    std::vector<int> vec = generate_primes(num);
    int vecsize = vec.size();
    for (int i = 0; i < vecsize; i++) {
        for (int j = i; j < vecsize; j++) {
            if (vec[i] + vec[j] == num) {
                std::cout << vec[i] << " + " << vec[j] << std::endl;
            }
        }
    }
    std::cout << "No more two primes add up to the given number." << std::endl;
}


int main() {
    int input;
    std::cout << "Enter a number, from 4 to 50000: ";
    std::cin >> input;
    all_twosum(input);
    return 0;
}