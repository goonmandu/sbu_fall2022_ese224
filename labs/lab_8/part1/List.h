#include "Node.h"
#include <iostream>

template <typename T>
class List {
    private: 
        Node<T>* head; 
        int count; 
    public: 
        List();
        ~List();
        int length(); // Return the length of the list
        bool is_empty(); // Return whether the list is empty
        void insert(int pos, const T& x); // Insert a new element
        void yeet(int pos); // Remove an element
        int search(const T &target); // Search an element
        void print();
};