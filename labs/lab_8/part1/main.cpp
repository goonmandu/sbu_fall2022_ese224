#include <iostream>



template <typename Type>
struct Node
{
    Type value;
    Node* next;
    Node() : next(nullptr) {}
    Node(Type x, Node* ptr = nullptr) : value(x), next(ptr) {}
    ~Node() {}
};

// add a new node next to a particular node
template <typename Type>
void insertion(Node<Type>* node, Type val)
{
    std::cout << "Inserting" << std::endl;
    Node<Type> *tmp = new Node<Type>(val);
    tmp->next = node->next;
    node->next = tmp;
    //while (!node->next) {
    //    node = node->next;
    //}
    //node->next = tmp;
};

template <typename Type>
void traverse(Node<Type>* head)
{
    Node<Type>* tmp = head;
    while (tmp)
    {
        std::cout << tmp->value << " ";
        tmp = tmp->next;
    }
    std::cout << std::endl;
};

template <typename Type>
void deletion(Node<Type>* node)
{
    if (node->next)
    {
        node->next = node->next->next;
    }
};

template <typename Type>
Node<Type>* createLinkedList(Type* arr, int n)
{
	if (n <= 0)
	{
		std::cout << "please check your input!" << std::endl;
		return NULL;
	}

	Node<Type> *head = new Node<Type>(arr[0]);
	Node<Type> *tmp = head;

	for (int i = 1; i < n; i++)
	{
		tmp->next = new Node<Type>(arr[i]);
		tmp = tmp->next;
	}
	return head;
}

template <typename Type>
void reverse(Node<Type>* &list) {
    Node<Type> *temp = nullptr;
    Node<Type> *prev = nullptr;
    Node<Type> *current = list;
    while (current != nullptr) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    list = prev;
}

template <typename Type>
Node<Type>* merge(Node<Type>* &list1, Node<Type>* &list2) {
    Node<Type>* result = new Node<Type>(0);
    if (!list1) {
        return list2;
    }
    if (!list2) {
        return list1;
    }
    /*
    if (list1.value > list2.value) {
        insertion(result, list2.value);
        list2 = list1.next;
    } else {
        insertion(result, list1.value);
        list1 = list1.next;
    }
     */
    if (list1->value > list2->value) {
        insertion(result, list2->value);
        list2 = list2->next;
    } else {
        insertion(result, list1->value);
        list1 = list1->next;
    }
    while (list1->next && list2->next) {
        
    }
    if (!list1->next) {
        while (!list2->next) {
            insertion(result, list2->value);
            list2 = list2->next;
        }
    } else if (!list2) {
        while (!list1) {
            insertion(result, list1->value);
            list1 = list1->next;
        }
    }
    return result;
}

int main() {
    int arr1[] = {1, 3, 4, 6, 8};
    int arr2[] = {0, 1, 2, 7};
    Node<int> *list1 = createLinkedList(arr1, 5);
    auto list2 = createLinkedList(arr2, 4);
    traverse(list1);
    // reverse(list1);
    // traverse(list1);
    insertion(list1, 9);
    traverse(list1);
    auto merged = merge(list1, list2);
    traverse(merged);
}