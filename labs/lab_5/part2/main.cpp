#include <iostream>

double scuffed_sqrt(double source, int decimals) {
    int start = 0, end = source;
    int mid;
 
    double ans;
 
    while (start <= end) {
        // DEBUG: std::cout << ans << std::endl;
        mid = (start + end) / 2;
        if (mid * mid == source) {
            ans = mid;
            break;
        }
 
        if (mid * mid < source) {
            start = mid + 1;
            ans = mid;
        }
 
        else {
            end = mid - 1;
        }
    }

    double increment = 0.1;
    for (int i = 0; i < decimals; i++) {
        while (ans * ans <= source) {
            ans += increment;
        }
 
        ans = ans - increment;
        increment = increment / 10;
    }
    return ans;
}

int main() {
    double input;
    int prec;
    std::cout << "Enter a number to calculate the square root of: ";
    std::cin >> input;
    std::cout << "How many decimal digits to compute: ";
    std::cin >> prec;
    std::cout << scuffed_sqrt(input, prec) << std::endl;
}