#include <iostream>
#include <vector>

template <typename Type>
struct Node
{
    Type value;
    Node* next;
    Node() : next(nullptr) {}
    Node(Type x, Node* ptr = nullptr) : value(x), next(ptr) {}
    ~Node() {}
    bool operator== (Node<Type> rhs) {
        if (value == rhs.value && next == rhs.next) {
            return true;
        }
        return false;
    }
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
void traverse(Node<Type>* head, int nodes)
{
    Node<Type>* tmp = head;
    while (tmp && nodes--)
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

template <typename T>
bool vector_contains(std::vector<T> vec, T target) {
    for (T t : vec) {
        if (target == t) {
            return true;
        }
    }
    return false;
}

template <typename T>
void print_cut_cycle(Node<T>* head) {
    Node<T>* tmp = head;
    std::vector<Node<T>> seen;
    while (tmp) {
        if (!vector_contains(seen, *tmp)) {
            seen.push_back(*tmp);
        } else {
            break;
        }
        std::cout << tmp->value << " ";
        tmp = tmp->next;
    }
    std::cout << std::endl;
};

int main() {
    int arr1[] = {1, 3, 4, 6, 8};
    int arr2[] = {0, 1, 2, 7};
    Node<int> *list1 = createLinkedList(arr1, 5);
    auto list2 = createLinkedList(arr2, 4);
    std::cout << "Part 1" << '\n';
    traverse(list1, -1);
    reverse(list1);
    traverse(list1, -1);
    std::cout << "Part 3" << '\n';
    list1->next->next->next->next = list1->next;
    traverse(list1, 20);
    print_cut_cycle(list1);
}