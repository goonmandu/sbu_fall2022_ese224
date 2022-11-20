#include <list>
#include <iterator>
#include <iostream>

template <typename T>
void reverse_range(std::list<T> &list, int start, int end) {
    auto l_start = list.begin();
    auto l_end = list.begin();
    std::advance(l_start, start);
    std::advance(l_end, end);
    for (int i = 0; i < (end - start) / 2; ++i) {
        std::swap(*l_start, *l_end);
        std::advance(l_start, 1);
        std::advance(l_end, -1);
    }
}

template <typename T>
void print_list(std::list<T> lst) {
    for (T t : lst) {
        std::cout << t << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::list<int> intlist = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    reverse_range(intlist, 1, 5);
    print_list(intlist);
}