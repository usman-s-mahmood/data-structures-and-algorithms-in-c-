#include "MyQueue.h"

template <class T>
bool MyQueue<T>::isEmpty()
{
    return (this->queue.isEmpty());
}

template <class T>
void MyQueue<T>::enqueue(T value)
{
    this->queue.insertAtTail(value);
}

template <class T>
T MyQueue<T>::dequeue()
{
    if (isEmpty())
    {
        cout<<"Queue Underflow!"<<endl;
        return -1;
    }
    T value = this->queue.deleteFromHead();
    return value;
}

template <class T>
void MyQueue<T>::display()
{
    if(isEmpty())
    {
        cout<<"Queue Underflow!"<<endl;
        return ;
    }
    this->queue.display();
}