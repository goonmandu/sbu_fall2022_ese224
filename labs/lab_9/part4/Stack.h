#include <queue>

class Stack {
    private:
        std::queue<int> primary;
        std::queue<int> auxiliary;
    public:
        void push(int x);
        void pop();
        int top();
        bool empty();
};

