#include "CircularLinkedList.h"

int main()
{
    CircularLinkedList<int> obj;
    obj.insertAtHead(1);
    obj.insertAtTail(2);
    obj.insertAtTail(3);
    obj.insertAtTail(4);
    obj.insertAtTail(5);
    obj.display();
    // cout << "Deleted value: " << obj.deleteFromPosition(2) << endl;
    obj.insertAtPosition(33, 3);
    obj.display();
    cout << obj.size() << " is the size of linked list" << endl;
    obj.deleteFromPosition(5);
    obj.display();
    return 0;
}