#include "List.h"
#include <iostream>

template <typename T>
List<T>::List() {
    head = nullptr;
    count = 0;
}

template <typename T>
List<T>::~List() {

}

template <typename T>
void List<T>::print() {
    Node<T>* tmp = head;
    while (tmp) {
        std::cout << tmp->data << " ";
        tmp = tmp->next;
    }
    std::cout << std::endl;
}

template <typename T>
void List<T>::insert(int pos, const T &val) {
    Node<T>* node = new Node<T>(val);
    Node<T>* tmp = head;
    if (pos == 1) {
        node->next = tmp;
        head = node;
    } else {
        for (int j = 1; j < pos - 1; ++j) {
      	    tmp = tmp->next;
        }
        node->next = tmp->next;
        tmp->next = node;
    }
    ++count;
}

template <typename T>
void List<T>::yeet(int pos) {
    Node<T>* tmp = head;
    if (pos == 1) {
        head = head->next;
        delete tmp;
    } else {
        for (int j = 1; j < pos - 1; ++j) {
	        tmp = tmp->next;
        }
        Node<T>* node = tmp->next;
        tmp->next = node->next;
        delete node;
    }
    --count;
}

template <typename T>
bool List<T>::is_empty() {
    return !head ? 0 : 1;
}

template <typename T>
int List<T>::length() {
    Node<T>* temp = head;
    int len;
    while (temp) {
        temp = temp->next;
        len++;
    }
    return len;
}

template <typename T>
int List<T>::search(const T &target) {
    Node<T>* temp = head;
    int idx = 0;
    while (temp->value != target) {
        if (!temp->next) {
            return -1;
        }
        temp = temp->next;
        idx++;
    }
    return idx;
}