#include "DoubleCircularLinkedList.h"

int main()
{
    DoubleCircularLinkedList<int> obj;
    // 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
    obj.insertAtTail(1);
    obj.insertAtTail(2);
    obj.insertAtTail(3);
    obj.insertAtTail(4);
    obj.insertAtTail(5);
    obj.insertAtTail(6);
    obj.insertAtTail(7);
    obj.insertAtTail(8);
    obj.insertAtTail(9);
    obj.insertAtTail(10);
    obj.insertAtTail(11);
    obj.reverseInGroups(3);
    return 0;
}