#include "MyStack.h"
#include "CircularQueue.h"
#include "MyLinkedList.h"

int main()
{
    /* algo to remove duplicates in a linked list
    MyLinkedList<int> obj;
    obj.insertAtHead(6);
    obj.insertAtHead(7);
    obj.insertAtHead(8);
    obj.insertAtHead(6);
    obj.insertAtHead(13);
    obj.insertAtHead(14);
    obj.insertAtHead(6);
    int dup = 6;
    cout << "Linked list before removing duplicates: " << endl;
    obj.display();
    cout << "Linked list after removing duplicates: " << endl;
    while (!obj.isEmpty())
    {
        int value = obj.deleteAtHead();
        if (value == dup)
            continue;
        cout << value << ' ';
    } 
    cout << endl; */
    /* algo for palindrome checking in linked list*/
    MyLinkedList<char> str;
    str.insertAtHead('r');
    str.insertAtHead('a');
    str.insertAtHead('c');
    str.insertAtHead('e');
    str.insertAtHead('c');
    str.insertAtHead('a');
    str.insertAtHead('r');
    bool flag = true;
    while (!str.isEmpty())
    {
        char v1 = str.deleteAtHead(), v2 = str.deleteAtTail();
        if (v1 != v2)
        {
            flag = false;
            break;
        }
    }
    if (flag)
        cout << "Word is palindrome!" << endl;
    else
        cout << "This word is not palindrome!" << endl;
    return 0;
}