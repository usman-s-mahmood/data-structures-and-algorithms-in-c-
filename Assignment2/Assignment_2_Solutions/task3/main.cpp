#include "MyLinkedList.h"

int main()
{
    MyLinkedList<int> obj;
    obj.insertAtHead(1);
    obj.insertAtTail(2);
    obj.insertAtTail(3);
    obj.insertAtTail(4);
    obj.insertAtTail(5);
    obj.insertAtTail(6);
    obj.display();
    MyLinkedList<int> obj2;
    obj2.insertAtTail(11);
    obj2.insertAtTail(12);
    obj2.insertAtTail(13);
    obj2.insertAtTail(14);
    obj.merge(obj2);
    obj.display();
    return 0;
}

