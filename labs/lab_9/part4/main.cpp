#include "Stack.h"
#include <iostream>

int main() {
    Stack intstack = Stack();
    intstack.push(1);
    std::cout << intstack.top() << std::endl;
    intstack.push(2);
    std::cout << intstack.top() << std::endl;
    intstack.push(3);
    std::cout << intstack.top() << std::endl;
    intstack.push(4);
    std::cout << intstack.top() << std::endl;
    intstack.push(5);
    std::cout << intstack.top() << std::endl;
    intstack.pop();
    std::cout << intstack.top() << std::endl;
    intstack.pop();
    std::cout << intstack.top() << std::endl;
    intstack.push(69420);
    std::cout << intstack.top() << std::endl;
    intstack.pop();
    std::cout << intstack.top() << std::endl;
}