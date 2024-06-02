#include "MyLinkedList.h"
int main()
{
    MyLinkedList<int> obj;
    obj.insertAtTail(1);
    obj.insertAtTail(-3);
    obj.insertAtTail(12);
    obj.insertAtTail(150);
    obj.insertAtTail(81);
    cout << obj.max() << endl;
    return 0;
}