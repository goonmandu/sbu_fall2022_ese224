#include <iostream>

bool ishappy(int num) {
    int sum = 0;
    while (num) {
        int digit = num % 10;
        // std::cout << digit << " ";
        num = num / 10;
        sum += digit * digit;
        // std::cout << sum << std::endl;
        // std::cin.get();
    }

    if (sum == 1) {
        return true;
    } else if (sum > 1 && sum < 5) {
        return false;
    }

    return ishappy(sum);
}

int main() {
    int in;
    std::cout << "Enter a number: ";
    std::cin >> in;
    std::cout << "Is the given number happy? " << ishappy(in) << std::endl;
}