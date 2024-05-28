#include "MyStack.h"
#include "CircularQueue.h"
#include "MyLinkedList.h"

template <class T>
void searchStack(MyStack<T> &obj);

template <class T>
void searchQueue(CircularQueue<T> &obj);

template <class T>
void searchList(MyLinkedList<T> &obj);


int main()
{
    MyStack<int> obj(10);
    obj.push(8);
    obj.push(7);
    obj.push(6);
    obj.push(5);
    obj.push(4);
    // searchStack<int>(obj);
    CircularQueue<int> queue(10);
    queue.enqueue(12);
    queue.enqueue(13);
    queue.enqueue(14);
    queue.enqueue(15);
    queue.enqueue(16);
    queue.enqueue(10);
    queue.enqueue(9);
    queue.enqueue(8);
    // searchQueue<int>(queue);
    MyLinkedList<int> list;
    list.insertAtHead(12);
    list.insertAtHead(14);
    list.insertAtHead(16);
    list.insertAtHead(19);
    list.insertAtHead(21);
    searchList(list);
    return 0;
}

template <class T>
void searchStack(MyStack<T> &obj)
{
    cout << "Enter a value: " ;
    T value;
    cin >> value;
    bool flag = false;
    while(!obj.isEmpty())
        if(value == obj.pop())
        {
            flag = true;
            break;
        }
    if (flag)
        cout << "Value found in the stack!" << endl;
    else
        cout << "Value not found in the stack!" << endl;
}

template <class T>
void searchQueue(CircularQueue<T> &obj)
{
    cout << "Enter a value: " ;
    T value;
    cin >> value;
    bool flag = false;
    while(!obj.isEmpty())
        if(value == obj.dequeue())
        {
            flag = true;
            break;
        }
    if (flag)
        cout << "Value found in the queue!" << endl;
    else
        cout << "Value not found in the queue!" << endl;
}


template <class T>
void searchList(MyLinkedList<T> &obj)
{
    cout << "Enter a value: " ;
    T value;
    cin >> value;
    bool flag = false;
    while (!obj.isEmpty())
    {
        T val = obj.deleteAtHead();
        if (value == val)
        {
            flag = true;
            break;
        }
    }
    if (flag)
        cout << "Value found in the List!" << endl;
    else
        cout << "Value not found in the List!" << endl;
}