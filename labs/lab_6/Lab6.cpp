#include "Lab6.h"

double max(double a, double b) {
    return a < b ? b : a;
}

void swap(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
}

void print_vec(std::vector<double> vec) {
    for (double num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

std::string longest_common_prefix(std::vector<std::string> &strings) {
    int min_len = strings[0].size();
    int common_up_to;
    bool has_deviant = false;
    for (std::string str : strings) {
        if (str.size() < min_len) {
            min_len = str.size();
        }
    }
    for (int c_idx = 0; c_idx < min_len; c_idx++) {
        for (int s_idx = 0; s_idx < strings.size() - 1; s_idx++) {
            if (strings[s_idx][c_idx] != strings[s_idx+1][c_idx]) {
                has_deviant = true;
            }
        }
        if (has_deviant) {
            common_up_to = c_idx;
            break;
        }
    }
    return strings[0].substr(0, common_up_to);
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

int partition(std::vector<double> &vec, int low, int high) {
    int pivot = vec[low];
    int i = low, j = high;
    while (i < j) {
        do {
            i++;
        } while (vec[i] <= pivot);
        do {
            j--;
        } while (vec[j] > pivot);
        if (i < j) {
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[low], vec[j]);
    return j;
}

void quicksort(std::vector<double> &vec, int low, int high) {
    if (low < high) {
        int j = partition(vec, low, high);
        quicksort(vec, low, j);
        quicksort(vec, j + 1, high);
    }
}