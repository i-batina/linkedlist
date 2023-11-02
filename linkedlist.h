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

    //Mutator Methods

    void InsertTail(int data);              // Adds node to tail (Push)
    void RemoveTail();                      // Removes node at tail
    void InsertHead(int data);              // Inserts node at head
    void RemoveHead();                      // Removes node at head (Pop)
    
    void InsertNode(int data, int idx);     // inserts new Node to specific index of existing node
    void ReplaceNode(int data, int idx);    // Replaces specific index
    void RemoveNode(int idx);               // Removes Node at index

    void ReverseList();

    Node* FindNodeFromIdx(int idx);         // Returns node at given index
    Node* FindNode(int data);               // Returns pointer to Node with specified data
    int FindNode(Node* node);               // Returns data associated with specific node
    int FindDataFromIdx(int idx);           // Returns the data from the index of the node

    //void PrintNode(Node* Node);
    void PrintList();                       // Prints the entire list from head (left) to tail (right)

    // Getters

    int GetSize();
    Node* GetHead();
    Node* GetTail();

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

void LinkedList::ReverseList() {
    // TODO: add prev pointer
}

void LinkedList::InsertTail(int val) {
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

void LinkedList::RemoveHead() {
    if (!GetSize()) return;

    Node* temp = GetHead();
    head_ = temp->next;
    delete temp;
    size_--;
}

void LinkedList::InsertHead(int data) {
    Node* newNode = new Node(data);
    if (!GetSize()) {
        head_ = newNode;
        tail_ = newNode;
        size_++;
        return;
    }
    newNode->next = head_;
    head_ = newNode;
    size_++;
}

void LinkedList::RemoveTail() {
    if (GetSize() == 1) {
        delete head_;
        delete tail_;
        size_--;
        return;
    }
    RemoveNode(GetSize());

}

void LinkedList::ReplaceNode(int val, int idx) {
    if (idx < 0 || idx > size_)
        return;
    
    Node* temp = FindNodeFromIdx(idx);
    temp->data = val;
}

void LinkedList::InsertNode(int val, int idx) {
    if (!GetSize() || idx > size_ || idx < 1) return;

    Node* newNode = new Node(val);
    if (idx == GetSize()) {
        InsertTail(val);
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

void LinkedList::RemoveNode(int idx) {
    if (!GetSize() || idx < 1 || idx > GetSize()) return; // Empty list

    if (idx == 1) { // If node is at head position
        RemoveHead();
        return;
    }

    Node* current = head_;
    Node* prev = nullptr;
    int count = 1;

    while (count < idx) {
        prev = current;
        current = current->next;
        count++;
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
    while (current->data != val) 
        current = current->next;

    if (current->data == val) return current;

    else return NULL;
}

int LinkedList::FindNode(Node* node) {
    if (!GetSize()) return -9999;
    else if (head_ == node) return head_->data;
    else if (tail_ == node) return tail_->data;

    Node* current = head_;
    while (current != node) 
        current = current->next;
    return current->data;
}

int LinkedList::FindDataFromIdx(int idx) {
    if (!GetSize() || idx > size_ || idx < 1) 
        return -9999;
    else if (idx == 1) 
        return head_->data;
    
    Node* current = head_;
    int count = 1;

    while (count < idx) {
        current = current->next;
        count++;
    }
    return current->data;
}

Node* LinkedList::FindNodeFromIdx(int idx) {
    if (!GetSize() || idx > size_ || idx < 1) 
        return NULL;
    else if (idx == 1) 
        return head_;
    else if (idx == size_) 
        return tail_;

    Node* current = head_;
    int count = 1;

    while (count < idx) {
        current = current->next;
        count++;
    }
    return current;
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