#include "MyLinkedList.h"

int main()
{
    MyLinkedList obj;
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
    return 0;
}