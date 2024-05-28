#include "DoubleCircularLinkedList.h"

int main()
{
    DoubleCircularLinkedList<int> obj;
    // obj.insertAtHead(1);
    // obj.insertAtTail(10);
    // obj.insertAtTail(100);
    // obj.insertAtTail(1000);
    // obj.insertAtHead(10000);
    // obj.display();
    // cout << "Value delete from head: " << obj.deleteFromHead() << endl;
    // cout << "Value delete from head: " << obj.deleteFromTail() << endl;
    obj.insertSorted(900);
    obj.insertSorted(9);
    obj.insertSorted(90);
    obj.insertSorted(9000);
    obj.insertSorted(-900);
    obj.insertSorted(1);
    obj.display();
    return 0;
}