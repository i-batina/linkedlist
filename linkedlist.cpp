#include "linkedlist.h"

using namespace std;

int main() {
    LinkedList l;

    for (int i = 1111; i < 1121; i++) {
        l.InsertTail(i);
    }

    l.PrintList();

    l.ReplaceNode(353497, 5);

    l.PrintList();

    //cout << l.FindDataFromIdx(1) << endl;
    
}