#include <iostream>
#include <vector>

template<typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
void selection_sort(std::vector<T> &vec) {
    int min_idx;
    int len = vec.size();
    for (int i = 0; i < len - 1; i++) {  // step by step
        min_idx = i;
        for (int j = i + 1; j < len; j++) {  // look for minimum
            if (vec[j] <= vec[min_idx]) {
                min_idx = j;
            }
        }
        swap(vec[min_idx], vec[i]);
    }
}

template<typename T>
int locate(std::vector<T> vec, T target) {
    int idx = 0;
    for (T item : vec) {
        if (item == target) {
            return idx;
        }
        idx++;
    }
    return -1;
}

template<typename T>
std::vector<T> find_greatest_count(std::vector<T> vec, int count) {
    std::vector<T> ret;
    for (int i = vec.size() - 1; i > vec.size() - count - 1; i--) {
        ret.push_back(vec[i]);
    }
    return ret;
}

template<typename T>
void print_simple_vector(std::vector<T> vec) {
    for (T item : vec) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> intvec = {4, 5, 9, 12, 9, 22, 45, 7};
    std::vector<int> copy = intvec;
    selection_sort(intvec);
    print_simple_vector(intvec);
    print_simple_vector(find_greatest_count(intvec, 4));
    std::cout << "Item is at index " << locate(copy, 9) << std::endl;
}