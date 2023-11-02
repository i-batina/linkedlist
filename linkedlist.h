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

    void InsertNode(int data, int idx);     // inserts new Node to specific index of existing node
    void ReplaceNode(int data, Node* node); // Replaces specific Node
    void RemoveNode(Node* node);            // Removes Node with specified data
    Node* FindNode(int data);               // Returns pointer to Node with specified data
    int FindNode(Node* node);               // Returns data associated with specific node
    int FindDataFromIdx(int idx);           // Returns the data from the index of the node

    int GetSize();                             // Returns size of list
    Node* GetHead();
    Node* GetTail();

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

    if (!GetSize()) {
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
    if (!GetSize()) return;

    Node* temp = head_;
    head_ = temp->next;
    delete temp;
    size_--;
}

void LinkedList::ReplaceNode(int data, Node* node) {
    // TODO
}

void LinkedList::InsertNode(int val, int idx) {
    if (!GetSize() || idx > size_ || idx < 1) return;

    Node* newNode = new Node(val);
    if (idx == GetSize()) {
        Push(val);
        size_++;
        return;
    }

    if (idx == 1) {
        newNode->next = GetHead();
        head_ = newNode;
        size_++;
        return;
    }

    Node* current = GetHead();
    int count = 1;
    while (current != nullptr && count < idx - 1) {
        current = current->next;
        count++;
    }
    newNode->next = current->next;
    current->next = newNode;
    size_++;
}

void LinkedList::RemoveNode(Node* node) {
    if (!GetSize()) return; // Empty list

    if (node == head_) { // If node is at head position
        Pop();
        size_ = 0;
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
    size_--;
}

int LinkedList::GetSize() {
    return size_;
}

Node* LinkedList::GetHead() {
    return head_;
}

Node* LinkedList::GetTail() {
    return tail_;
}

Node* LinkedList::FindNode(int val) {
    if (!GetSize()) return NULL;
    if (head_->data == val) return GetHead();

    Node* current = head_;
    while (current->data != val) current = current->next;

    if (current->data == val) return current;

    else return NULL;
}

int LinkedList::FindNode(Node* node) {
    if (!GetSize()) return -9999;
    else if (head_ == node) return head_->data;
    else if (tail_ == node) return tail_->data;

    Node* current = head_;
    while (current != node) current = current->next;
    return current->data;
}

int LinkedList::FindDataFromIdx(int idx) {
    if (!GetSize() || idx > size_ || idx < 1) return -9999;
    else if (idx == 1) return head_->data;
    
    Node* current = head_;
    int count = 1;
    while (count != idx) {
        current = current->next;
        count++;
    }
    return current->data;
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