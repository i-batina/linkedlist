#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:

    // constructors and destructors

    LinkedList();
    ~LinkedList();

    //Methods

    void AddNode(int data, Node* node);     // Adds new Node to specific index
    void ReplaceNode(int data, Node* node); // Replaces specific Node
    void RemoveNode(Node* node);            // Removes Node with specified data
    Node* FindNode(int data);               // Returns pointer to Node with specified data
    int Size();                             // Returns size of list

    void PrintNode(Node* Node);
    void PrintList();                       // Prints the entire list from head (left) to tail (right)
    void Push(int data);                    // Adds node to tail
    void Pop();                             // Removes node at head

private:
    Node* head_;
    Node* tail_;
    int size_;

protected:
    int capacity_ = 10000 / 2;
};

//Typedef Node* nodePtr;

LinkedList::LinkedList() : head_(nullptr), tail_(nullptr), size_(0) {}

LinkedList::~LinkedList() {
    while(head_) {
        Node * current = head_;
        head_ = head_->next;
        delete current;
    }
}

void LinkedList::Push(int val) {
    if (size_ == capacity_) return;

    Node* temp = new Node(val);
    temp->data = val;
    temp->next = nullptr;

    if (!Size()) {
        head_ = temp;
        tail_ = temp;
    }
    else {
        tail_->next = temp;
        tail_ = tail_->next;
    }
    size_++;
}

void LinkedList::Pop() {
    if (!Size()) return;

    Node* temp = head_;
    head_ = temp->next;
    delete temp;
}

void LinkedList::RemoveNode(Node* node) {
    if (!Size()) return; // empty list

    if (node == head_) {
        Pop();
        return;
    }

    Node* current = head_;
    Node* prev = current;

    while (current != node) {
        prev = current;
        current = current->next;
    }

    prev->next = current->next;
    delete current;
}

int LinkedList::Size() {
    return size_;
}

Node* LinkedList::FindNode(int val) {
    Node* current = head_;
    while (current->data != val) current = current->next;

    if (current->data == val) return current;

    else return NULL;
}

void LinkedList::PrintList() {
    Node * current = head_;
    std::cout << std::endl;
    for (int i = 0; i < size_; i++) {
        std::cout << "  " << i + 1 << "|" << current->data;
        current = current->next;
    }
    std::cout << std::endl;
    current = nullptr;
}