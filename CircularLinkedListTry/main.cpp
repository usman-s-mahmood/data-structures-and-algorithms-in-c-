#include "CircularLinkedList.h"

int main()
{
    /*
    CircularLinkedList<int> obj;
    obj.insertAtTail(1);
    obj.insertAtHead(2);
    obj.insertAtHead(3);
    obj.insertAtTail(4);
    obj.insertAtTail(5);
    obj.insertAtTail(6);
    obj.insertAtTail(7);
    obj.insertAtTail(8);
    obj.insertAtTail(9);
    obj.display();
    cout << "Deletion from Head: " << endl
        << obj.deleteFromHead() << endl
        << obj.deleteFromHead() << endl
        << obj.deleteFromHead() 
    << endl;
    obj.display();
    cout << "Deletion from tail: " << endl
        << obj.deleteFromTail() << endl
        << obj.deleteFromTail() << endl
        << obj.deleteFromTail() 
    << endl;
    obj.display();
    cout << "Value 6 in Linked List: " << obj.search(6) << endl;
    cout << "Value 16 in Linked List: " << obj.search(16) << endl; */
    CircularLinkedList<int> obj;
    obj.insertSortedDSC(1);
    obj.insertSortedDSC(10);
    obj.insertSortedDSC(5);
    obj.insertSortedDSC(9);
    obj.insertSortedDSC(-3);
    obj.insertSortedDSC(200);
    obj.insertSortedDSC(90);
    obj.insertSortedDSC(100);
    obj.display();
    return 0;
}