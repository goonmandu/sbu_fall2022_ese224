template <typename T>
struct Node {
    T value;
    Node* next;
    Node() : next(nullptr) {}
    Node(T x, Node* ptr = nullptr) : value(x), next(ptr) {}
    ~Node() {}
};