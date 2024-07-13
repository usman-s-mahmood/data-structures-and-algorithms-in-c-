<<<<<<< HEAD
#include "DoubleCircularLinkedList.h"

int main()
{
    DoubleCircularLinkedList<int> obj;
    obj.insertAtHead(1);
    obj.insertAtHead(3);
    obj.insertAtHead(4);
    obj.insertAtHead(7);
    obj.insertAtTail(17);
    obj.insertAtTail(19);
    obj.insertAtTail(20);
    obj.insertAtTail(50);
    obj.display();
    obj.size();
    cout << "After deleting value from head: " << obj.deleteFromHead() << endl; 
    obj.display();
    cout << "After deleting value from tail: " << obj.deleteFromTail() << endl; 
    obj.display();
    obj.deleteValue(17);
    obj.display();
    return 0;
=======
#include "DoubleCircularLinkedList.h"

int main()
{
    DoubleCircularLinkedList<int> obj;
    obj.insertAtHead(1);
    obj.insertAtHead(3);
    obj.insertAtHead(4);
    obj.insertAtHead(7);
    obj.insertAtTail(17);
    obj.insertAtTail(19);
    obj.insertAtTail(20);
    obj.insertAtTail(50);
    obj.display();
    obj.size();
    cout << "After deleting value from head: " << obj.deleteFromHead() << endl; 
    obj.display();
    cout << "After deleting value from tail: " << obj.deleteFromTail() << endl; 
    obj.display();
    obj.deleteValue(17);
    obj.display();
    return 0;
>>>>>>> 6b2f82d8e44f7796eed3207ffa1665bcdc1c3fed
}