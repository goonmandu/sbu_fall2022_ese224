#include <list>
#include <vector>
#include <iostream>
#include <iterator>

template <typename T>
std::list<T> merge(std::list<T> &lst1, std::list<T> &lst2) {
    std::list<T> lst;

    while (lst1.size() && lst2.size()) {
        if (lst1.front() < lst2.front()) {
            lst.push_back(lst1.front());
            lst1.erase(lst1.begin());
        } else {
            lst.push_back(lst2.front());
            lst2.erase(lst2.begin());
        }
    }
    if (lst1.size()) {
        while (lst1.size()) {
            lst.push_back(lst1.front());
            lst1.erase(lst1.begin());
        }
    } else {
        while (lst2.size()) {
            lst.push_back(lst2.front());
            lst2.erase(lst2.begin());
        }
    }
    return lst;
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

int main() {
    std::vector<int> intvec1 = {3, 5, 7, 9, 11};
    std::vector<int> intvec2 = {2, 4, 6, 12, 14};
    std::vector<int> intdupes = {1, 1, 3, 4, 4, 6, 6, 6, 7, 0};
    std::list<int> intlist1, intlist2, intdupeslist;
    for (int num : intvec1) {
        intlist1.push_back(num);
    }
    for (int num : intvec2) {
        intlist2.push_back(num);
    }
    for (int num : intdupes) {
        intdupeslist.push_back(num);
    }
    std::cout << "Part 2" << std::endl;
    auto result = merge(intlist1, intlist2);
    print_list(result);
    std::cout << "Part 4" << std::endl;
    print_list(intdupeslist);
    remove_dupes(intdupeslist);
    print_list(intdupeslist);
}