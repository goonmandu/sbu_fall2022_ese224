#include "Hanoi.h"
#include <vector>
#include <iostream>

Hanoi::Hanoi() {
    for (int i = 8; i > 0; --i) {
        left.push(i);
    }
}

void Hanoi::move(int src, int dest) {
    int disk;
    if (src == 1) {
        disk = left.top();
        left.pop();
    } else if (src == 2) {
        disk = center.top();
        center.pop();
    } else if (src == 3) {
        disk = right.top();
        right.pop();
    }
    if (dest == 1) {
        left.push(disk);
    } else if (dest == 2) {
        center.push(disk);
    } else if (dest == 3) {
        right.push(disk);
    }
}

void Hanoi::show() {
    std::vector<int> aux = {};
    while (!left.empty()) {
        aux.push_back(left.top());
        left.pop();
    }
    std::cout << "Tower 1: ";
    for (int i = aux.size() - 1; i > -1; --i) {
        std::cout << aux[i] << " ";
        left.push(aux[i]);
    }
    aux.clear();
    std::cout << std::endl;

    while (!center.empty()) {
        aux.push_back(center.top());
        center.pop();
    }
    std::cout << "Tower 2: ";
    for (int i = aux.size() - 1; i > -1; --i) {
        std::cout << aux[i] << " ";
        center.push(aux[i]);
    }
    aux.clear();
    std::cout << std::endl;

    while (!right.empty()) {
        aux.push_back(right.top());
        right.pop();
    }
    std::cout << "Tower 3: ";
    for (int i = aux.size() - 1; i > -1; --i) {
        std::cout << aux[i] << " ";
        right.push(aux[i]);
    }
    aux.clear();
    std::cout << std::endl;
}

void Hanoi::menu() {
    show();
    while (1) {
        int s, d;
        std::cout << "Source (space) Destination (-1 -1 to quit): ";
        std::cin >> s >> d;
        if (s == -1 && d == -1) {
            return;
        }
        move(s, d);
        show();
    }
}