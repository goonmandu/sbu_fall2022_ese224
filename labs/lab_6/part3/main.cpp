#include <vector>
#include <iostream>

void print_vec(std::vector<double> vec);
std::vector<double> merge(std::vector<double> &vec1, std::vector<double> &vec2);
std::vector<double> mergesort(std::vector<double> &vec);

int main() {
    std::vector<double> rvec = {1, 2, 4, 3, 8, 5, 10, 842, -8};
    print_vec(mergesort(rvec));
}

void print_vec(std::vector<double> vec) {
    for (double num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

std::vector<double> merge(std::vector<double> &vec1, std::vector<double> &vec2) {
    std::vector<double> vec;

    while (vec1.size() && vec2.size()) {
        if (vec1[0] < vec2[0]) {
            vec.push_back(vec1[0]);
            vec1.erase(vec1.begin());
        } else {
            vec.push_back(vec2[0]);
            vec2.erase(vec2.begin());
        }
    }
    if (vec1.size()) {
        while (vec1.size()) {
            vec.push_back(vec1[0]);
            vec1.erase(vec1.begin());
        }
    } else {
        while (vec2.size()) {
            vec.push_back(vec2[0]);
            vec2.erase(vec2.begin());
        }
    }
    return vec;
}

std::vector<double> mergesort(std::vector<double> &vec) {
    if (vec.size() == 1) {
        return vec;
    }
    int const half = vec.size() / 2;
    std::vector<double> firsthalf(vec.begin(), vec.begin() + half);
    std::vector<double> secondhalf(vec.begin() + half, vec.end());

    firsthalf = mergesort(firsthalf);
    secondhalf = mergesort(secondhalf);

    return merge(firsthalf, secondhalf);
}