#include "Stack.h"
#include <cstdlib>
#include <iostream>

void Stack::push(int x) {
    // std::cout << primary.size() << "";
    primary.push(x);
}

void Stack::pop() {
    if (primary.empty()) {
        std::cerr << "The stack is empty!" << '\n';
        exit(1);
    }
    while (primary.size() > 1) {
        auxiliary.push(primary.front());
        primary.pop();
    }
    primary.pop();
    std::swap(primary, auxiliary);
}

int Stack::top() {
    int last;
    while (!primary.empty()) {
        last = primary.front();
        auxiliary.push(last);
        primary.pop();
    }
    while (!auxiliary.empty()) {
        primary.push(auxiliary.front());
        auxiliary.pop();
    }
    return last;
}

bool Stack::empty() {
    return primary.empty();
}