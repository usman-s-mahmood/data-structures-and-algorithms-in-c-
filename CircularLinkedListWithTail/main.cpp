#include "CircularLinkedList.h"

int main()
{
    CircularLinkedList<int> obj;
    // obj.insertAtHead(1);
    // obj.insertAtTail(12);
    // obj.insertAtHead(2);
    // obj.display();
    // obj.insertAtHead(13);
    // obj.display();
    // cout << "Value deleted from Head: " << obj.deleteFromHead() << endl;
    // cout << "Value deleted from Tail: " << obj.deleteFromTail() << endl;
    // obj.display();
    obj.insertSorted(100);
    obj.insertSorted(1);
    obj.insertSorted(-100);
    obj.insertSorted(10000);
    obj.insertSorted(5);
    obj.display();
    return 0;
}