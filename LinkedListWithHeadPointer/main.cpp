#include "MyLinkedList.h"

int main()
{
    MyLinkedList<int> obj;
    obj.insertSorted(100);
    obj.insertSorted(90);
    obj.insertSorted(80);
    obj.insertSorted(70);
    obj.insertSorted(75);
    obj.insertSorted(105);
    obj.insertSorted(1050);
    obj.insertSorted(120);
    obj.display();
    return 0;
}