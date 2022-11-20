#include <list>
#include <stack>
#include <iostream>
#include <iterator>

template <typename T>
void print_list(std::list<T> lst) {
    for (T t : lst) {
        std::cout << t << " ";
    }
    std::cout << std::endl;
}

std::list<int> add_lists(std::list<int> lhs, std::list<int> rhs) {
    auto lhs_lsd = lhs.begin();
    auto rhs_lsd = rhs.begin();
    int lsize = lhs.size();
    int rsize = rhs.size();
    std::stack<int> digitstack;
    std::list<int> result;
    std::advance(lhs_lsd, lsize - 1);
    std::advance(rhs_lsd, rsize - 1);
    bool carry = false;
    int sum = 0;
    for (int i = 0; i < std::max(lsize, rsize) + 1; ++i) {
        if (i < lsize) {
            sum += *lhs_lsd;
            std::advance(lhs_lsd, -1);
        }
        if (i < rsize) {
            sum += *rhs_lsd;
            std::advance(rhs_lsd, -1);
        }
        sum += carry;
        if (sum >= 10) {
            digitstack.push(sum - 10);
            carry = true;
        } else {
            digitstack.push(sum);
            carry = false;
        }
        sum = 0;
    }
    if (!digitstack.top()) {
        digitstack.pop();
    }
    while (!digitstack.empty()) {
        result.push_back(digitstack.top());
        digitstack.pop();
    }
    return result;
}

int main() {
    std::list<int> lhs = {6, 0, 8};
    std::list<int> rhs = {9, 2};
    print_list(add_lists(lhs, rhs));
}