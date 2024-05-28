#include "MyDoubleLinkedList.h"

int main()
{
    MyDoubleLinkedList<int> obj;
    obj.insertSortedDSC(1);
    obj.insertSortedDSC(5);
    obj.insertSortedDSC(9);
    obj.insertSortedDSC(-9);
    obj.insertSortedDSC(10);
    obj.insertSortedDSC(80);
    obj.insertSortedDSC(99);
    obj.insertSortedDSC(990);
    obj.insertSortedDSC(100);
    obj.display();
    cout << "Deleted Values from Linked List: " << endl
        << obj.deleteFromHead() << endl
        << obj.deleteFromHead() << endl
        << obj.deleteFromTail()
    << endl;
    obj.display();
    cout << "Value 5 in Linked List: " << obj.search(5) << endl;
    return 0;
}