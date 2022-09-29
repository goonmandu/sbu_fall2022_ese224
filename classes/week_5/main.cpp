/* Doesn't work for some reason */

#include <iostream>
#include <vector>

void swap(double &num1, double &num2) {
    double temp = num1;
    num1 = num2;
    num2 = temp;
}

void selection_sort(double arr[]) {
    int min_idx;
    double temp;
    int len = *(&arr + 1) - arr;
    for (int i = 0; i < len - 1; i++) {  // step by step
        min_idx = i;
        for (int j = i + 1; j < len - 1; j++) {  // look for minimum
            if (arr[j] <= arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
    }
}

void double_vector_selection_sort(std::vector<double> vec) {
    int min_idx;
    double temp;
    int len = vec.size();
    for (int i = 0; i < len - 1; i++) {  // step by step
        min_idx = i;
        for (int j = i + 1; j < len - 1; j++) {  // look for minimum
            if (vec[j] <= vec[min_idx]) {
                min_idx = j;
            }
        }
        swap(vec[min_idx], vec[i]);
    }
}

void print_double_array(double arr[]) {
    std::cout << "(";
    int len = *(&arr + 1) - arr - 2;
    for (int i = 0; i < len; i++) {
        std::cout << arr[i] << ", ";
        if (i == len - 1) {
            std::cout << arr[i];
        }
    }
    std::cout << ")" << std::endl;
}

void print_double_vector(const std::vector<double> vec) {
    for (double x : vec) {
        std::cout << x << " ";
    }
    std::cout << "\n";
}

int main() {
    double arr[] = {9, 2, 3, 4, 1, -1, 75};
    std::vector<double> vec(5);
    for (int i = 0; i > 5; i++) {
        vec[i] = 5 - i;e
    }
    print_double_vector(vec);
    selection_sort(arr);
    print_double_array(arr);
    double_vector_selection_sort(vec);
    print_double_vector(vec);
}