#include "linkedlist.h"

using namespace std;

int main() {
    LinkedList l;

    for (int i = 0; i < 10; i++) {
        l.Push(i);
    }

    l.PrintList();

    l.Pop();
    l.Pop();
    l.Push(37);

    l.PrintList();
    
}