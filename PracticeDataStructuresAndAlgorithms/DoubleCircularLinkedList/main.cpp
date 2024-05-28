#include "DoubleCircularLinkedList.h"

int main()
{
    DoubleCircularLinkedList<int> obj; /*
    obj.insertAtHead(12);
    obj.insertAtHead(11);
    obj.insertAtHead(10);
    obj.insertAtHead(9);
    obj.insertAtTail(20);
    obj.insertAtTail(30);
    obj.insertAtTail(15);
    obj.display();
    cout << obj.deleteFromHead() << endl;
    cout << obj.deleteFromTail() << endl; */
    obj.insertSorted(4);
    obj.insertSorted(40);
    obj.insertSorted(-1);
    obj.insertSorted(200);
    obj.insertSorted(1);
    obj.insertSorted(3);
    obj.insertSorted(5);
    obj.display();
    return 0;
}