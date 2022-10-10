#include <iostream>
#include <cmath>

/*
double scuffed_sqrt(double source, int decimals) {
    int start = 0, end = source;
    int mid;
 
    // variable to store the answer
    double ans;
 
    // for computing integral part
    // of square root of number
    while (start <= end) {
        std::cout << ans << std::endl;
        mid = (start + end) / 2;
        if (mid * mid == source) {
            ans = mid;
            break;
        }
 
        // incrementing start if integral
        // part lies on right side of the mid
        if (mid * mid < source) {
            start = mid + 1;
            ans = mid;
        }
 
        // decrementing end if integral part
        // lies on the left side of the mid
        else {
            end = mid - 1;
        }
    }
 
    // For computing the fractional part
    // of square root upto given precision
    double increment = 0.1;
    for (int i = 0; i < decimals; i++) {
        while (ans * ans <= source) {
            ans += increment;
        }
 
        // loop terminates when ans * ans > number
        ans = ans - increment;
        increment = increment / 10;
    }
    return ans;
}
 */

double j = sqrt(5);

#error kek

double scuffed_sqrt(double num, double prec) {
    int start = 0, end = num;
    double result;

    while (1) {
        break;
    }
}

int main() {
    std::cout << scuffed_sqrt(189, 4) << std::endl;
}