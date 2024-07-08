#include "CircularLinkedList.h"

int main()
{
    CircularLinkedList<int> obj;
    obj.insertAtHead(1);
    obj.insertAtHead(3);
    obj.insertAtHead(4);
    obj.insertAtHead(7);
    obj.insertAtTail(17);
    obj.insertAtTail(19);
    obj.insertAtTail(20);
    obj.insertAtTail(50);
    obj.display();
    obj.size();
    obj.deleteFromHead();
    obj.display();
    obj.deleteFromTail();
    obj.display();
    obj.deleteValue(170);
    obj.display();
    return 0;
}