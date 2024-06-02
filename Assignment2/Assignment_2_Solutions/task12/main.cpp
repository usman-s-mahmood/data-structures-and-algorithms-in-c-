#include "MyLinkedList.h"

int main()
{
    MyLinkedList<int> obj;
    obj.insertAtTail(1);
    obj.insertAtTail(2);
    obj.insertAtTail(3);
    obj.insertAtTail(4);
    obj.insertAtTail(5);
    obj.insertAtTail(1);
    obj.insertAtTail(7);
    obj.insertAtTail(8);
    obj.insertAtTail(1);
    obj.insertAtTail(5);
    obj.insertAtTail(8);
    obj.insertAtTail(18);
    obj.insertAtTail(8);
    obj.insertAtTail(108);
    obj.insertAtTail(119);
    obj.display();
    obj.removeDuplicates();
    obj.display();
    cout << "Length of Linked list is: " << obj.getLength() << endl;
    return 0;
}