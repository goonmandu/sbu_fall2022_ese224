#include <vector>
#include <iostream>

double max(double a, double b);
void print_vec(std::vector<double> vec);
int non_adjacent_candies(std::vector<int> &candies);

int main() {
    std::vector<int> candies1 = {1, 4, 2};
    std::vector<int> candies2 = {5, 3, 2, 4, 6, 8, 9};
    std::vector<int> candies3 = {5, 3, 3, 4, 6, 18, 9};

    std::cout << non_adjacent_candies(candies1) << std::endl;
    std::cout << non_adjacent_candies(candies2) << std::endl;
    std::cout << non_adjacent_candies(candies3) << std::endl;
}

double max(double a, double b) {
    return a < b ? b : a;
}

void print_vec(std::vector<double> vec) {
    for (double num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int non_adjacent_candies(std::vector<int> &candies) {
    int inclusive = candies[0];
    int exclusive = 0;
    int old_incl;
    for (int idx = 1; idx < candies.size(); idx++) {
        old_incl = inclusive;
        inclusive = max(inclusive, exclusive + candies[idx]);
        exclusive = old_incl;
    }
    return max(inclusive, exclusive);
}