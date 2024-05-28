#include "MyStack.h"

template <class T>
bool MyStack<T>::isEmpty()
{
    return (this->stk.isEmpty());
}

template <class T>
void MyStack<T>::push(T value)
{
    this->stk.insertAtTail(value);
}

template <class T>
T MyStack<T>::pop()
{
    if(this->stk.isEmpty())
    {
        cout<<"Stack Underflow!"<<endl;
        return -1;
    }
    T value = this->stk.deleteFromTail();
    return value;
}

template <class T>
void MyStack<T>::display()
{
    if (this->stk.isEmpty())
    {
        cout<<"Stack underflow!"<<endl;
        return ;
    }
    this->stk.display();
}