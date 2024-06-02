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
    obj.insertAtTail(7);
    obj.display();
    cout << obj.mid() << endl;
    return 0;
}