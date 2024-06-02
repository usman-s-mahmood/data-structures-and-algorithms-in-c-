#include "MyLinkedList.h"

template <class T>
void isPalindrome(MyLinkedList<T> str)
{
    bool flag = true;
    while (!str.isEmpty())
    {
        T v1 = str.deleteAtHead(), v2 = str.deleteAtTail();
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
    return ;
}

int main()
{
    MyLinkedList<int> obj;
    MyLinkedList<char> str;
    str.insertAtHead('r');
    str.insertAtHead('a');
    str.insertAtHead('c');
    str.insertAtHead('e');
    str.insertAtHead('c');
    str.insertAtHead('a');
    str.insertAtHead('r');
    str.isPalindrome();
    return 0;
}