#include "Queue.h"
#include <iostream>

int main() {
    Queue intqueue = Queue();
    // intqueue.pop();
    intqueue.push(6);
    intqueue.push(9);
    intqueue.push(4);
    intqueue.push(2);
    intqueue.push(0);
    std::cout << intqueue.front() << std::endl;
    intqueue.pop();
    intqueue.pop();
    intqueue.push(69420);
    std::cout << intqueue.front() << std::endl;
    intqueue.pop();
    std::cout << intqueue.front() << std::endl;
    
}