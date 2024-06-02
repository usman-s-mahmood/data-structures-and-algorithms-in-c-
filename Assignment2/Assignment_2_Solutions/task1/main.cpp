#include "MyDoubleLinkedList.h"

int main()
{
    MyDoubleLinkedList<int> obj;
    obj.insertAtHead(1);
    obj.insertAtTail(2);
    obj.insertAtTail(3);
    obj.insertAtTail(4);
    obj.insertAtTail(5);
    obj.insertAtTail(6);
    // obj.display();
    // obj.insertAtPosition(11, 3);
    // cout << obj.size() << endl;
    // obj.display();
    // cout << "Deleting element at 3rd position: " << obj.deleteFromPosition(3) << endl;
    obj.display();
    obj.reverseList();
    obj.display();
    return 0;
}