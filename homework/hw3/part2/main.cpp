#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    int array[9] = {1, 2, -10, 4, 12, 15, -1, 2, 3};
    std::vector<int> m;
    int max_num = 0;
    
    m.push_back(array[0]);

    for (int i = 1; i < 9; i++) {
        m.push_back((m[i-1] + array[i] > array[i]) ? m[i-1] + array[i] : array[i]);
        max_num = std::max(max_num, m.back());
    }

    std::cout << max_num << std::endl;
}