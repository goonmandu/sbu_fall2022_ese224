#include <vector>
#include <iostream>

void print_vec(std::vector<int> vec);
void swap(int &a, int &b);
int partition(std::vector<int> &vec, int low, int high);
void quicksort(std::vector<int> &vec, int low, int high);

int main() {
    std::vector<int> rvec = {1, 2, 4, 3, 8, 5, 10, 842, -8};
    //partition(rvec, 0, rvec.size());
    quicksort(rvec, 0, rvec.size());
    print_vec(rvec);
}

void print_vec(std::vector<int> vec) {
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(std::vector<int> &vec, int low, int high) {
    int pivot = vec[low];
    int i = low, j = high;
    while (i < j) {
        do {
            i++;
            if (i > j) {
                break;
            }
            std::cout << "i=" << vec[i] << " ";
        } while (vec[i] <= vec[low]);
        std::cout << std::endl;
        do {
            j--;
            std::cout << "j=" << vec[j] << " ";
        } while (vec[j] > pivot);
        std::cout << std::endl;
        if (i < j) {
            std::cout << "Swap i with j" << std::endl;
            swap(vec[i], vec[j]);
        }
    }
    std::cout << "Swap pivot with right" << std::endl;
    swap(vec[low], vec[j]);
    std::cout << j << std::endl;
    return j;
}

void quicksort(std::vector<int> &vec, int low, int high) {
    if (low < high) {
        int j = partition(vec, low, high);
        quicksort(vec, low, j);
        quicksort(vec, j + 1, high);
    }
}