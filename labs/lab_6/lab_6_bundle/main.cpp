#include <vector>
#include <iostream>
#include "Lab6.h"

int main() {
    std::cout << "/*   PART 1   */" << std::endl;
    std::vector<std::string> inputs1 = {
        "flower",
        "flow",
        "flight"
    };
    std::vector<std::string> inputs2 = {
        "dog",
        "racecar",
        "car"
    };

    std::cout << longest_common_prefix(inputs1) << std::endl;
    std::cout << longest_common_prefix(inputs2) << std::endl;

    std::cout << std::endl;
    std::cout << "/*   PART 2   */" << std::endl;
    std::vector<int> candies1 = {1, 4, 2};
    std::vector<int> candies2 = {5, 3, 2, 4, 6, 8, 9};
    std::vector<int> candies3 = {5, 3, 3, 4, 6, 18, 9};

    std::cout << non_adjacent_candies(candies1) << std::endl;
    std::cout << non_adjacent_candies(candies2) << std::endl;
    std::cout << non_adjacent_candies(candies3) << std::endl;

    std::cout << std::endl;
    std::cout << "/*   PART 3   */" << std::endl;
    std::vector<double> rvec = {1, 2, 4, 3, 8, 5, 10, 842, -8};
    print_vec(mergesort(rvec));

    std::cout << std::endl;
    std::cout << "/*   PART 4   */" << std::endl;
    quicksort(rvec, 0, rvec.size());
    print_vec(rvec);
}