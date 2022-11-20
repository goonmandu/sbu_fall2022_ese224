#include "Queue.h"
#include <cstdlib>
#include <iostream>

void Queue::push(int x) {
    primary.push(x);
}

void Queue::pop() {
    if (primary.empty()) {
        std::cerr << "The queue is empty!" << '\n';
        exit(1);
    }
    while (!primary.empty()) {
        auxiliary.push(primary.top());
        primary.pop();
    }
    auxiliary.pop();
    while (!auxiliary.empty()) {
        primary.push(auxiliary.top());
        auxiliary.pop();
    }
}

int Queue::front() {
    if (primary.empty()) {
        std::cerr << "The queue is empty!" << '\n';
        exit(1);
    }
    while (!primary.empty()) {
        auxiliary.push(primary.top());
        primary.pop();
    }
    int f = auxiliary.top();
    while (!auxiliary.empty()) {
        primary.push(auxiliary.top());
        auxiliary.pop();
    }
    return f;
}

bool Queue::empty() {
    return primary.empty();
}