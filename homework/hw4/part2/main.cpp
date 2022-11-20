#include <list>
#include <vector>
#include <iterator>
#include <iostream>

template <typename T>
void remove_dupes(std::list<T> &lst);

template <typename T>
void print_list(std::list<T> lst);

template <typename T>
bool vector_contains(std::vector<T> vec, T target);

int main() {
    std::list<int> cars = {1, 2, 3, 3, 4, 4, 4, 4, 6, 7, 9, 10, 10};
    print_list(cars);
    remove_dupes(cars);
    print_list(cars);
}

template <typename T>
void print_list(std::list<T> lst) {
    for (T t : lst) {
        std::cout << t << " ";
    }
    std::cout << std::endl;
}

template <typename T>
bool vector_contains(std::vector<T> vec, T target) {
    for (T t : vec) {
        if (target == t) {
            return true;
        }
    }
    return false;
}

template <typename T>
void remove_dupes(std::list<T> &lst) {
    std::vector<T> seen;
    std::vector<int> to_remove;
    auto l_front = lst.begin();
    for (int i = 0; i < lst.size(); ++i) {
        if (!vector_contains(seen, *l_front)) {
            seen.push_back(*l_front);
        } else {
            if (!vector_contains(to_remove, i - 1)) {
                to_remove.push_back(i - 1);
            }
            to_remove.push_back(i);
        }
        std::advance(l_front, 1);
    }
    while (!to_remove.empty()) {
        auto l_del = lst.begin();
        int idx = to_remove.back();
        to_remove.pop_back();
        std::advance(l_del, idx);
        lst.erase(l_del);
    }
}