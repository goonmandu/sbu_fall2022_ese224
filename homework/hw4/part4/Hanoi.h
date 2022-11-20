#pragma once
#include <stack>

class Hanoi {
    private:
        std::stack<int> left, center, right;
    public:
        Hanoi();
        void move(int src, int dest);
        void show();
        void menu();
};