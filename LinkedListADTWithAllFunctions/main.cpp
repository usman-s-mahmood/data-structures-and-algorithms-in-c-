#include "MyLinkedList.h"

int main()
{
    MyLinkedList<int> obj;
    obj.insertAtTail(15);
    obj.insertAtTail(16);
    obj.insertAtTail(17);
    obj.insertAtTail(18);

    obj.insertAtHead(1);
    obj.insertAtHead(2);
    obj.insertAtHead(3);

    obj.display();
    cout<<obj.deleteAtHead()<<endl;
    cout<<obj.deleteAtTail()<<endl;
    cout<<obj.deleteAtTail()<<endl;
    obj.display();
    obj.search(2);
    obj.search(16);
    obj.search(15);
    obj.search(1);
    obj.search(0);
    obj.deleteValue(15);
    obj.display();
    obj.insertAtValue(11, 12);
    obj.insertAfterValue(17, 12);
    obj.insertBeforeValue(171, 55);
    obj.display();
    return 0;
}