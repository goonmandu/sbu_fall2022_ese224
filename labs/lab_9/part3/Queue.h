#include <stack>

class Queue {
    private:
        std::stack<int> primary;
        std::stack<int> auxiliary;
    public:
        void push(int x);
        void pop();
        int front();
        bool empty();
};