#include "Stack.h"

template <class T>
class MyStack: public Stack<T>
{
    public:
        MyStack();
        MyStack(int);
        MyStack(MyStack<T> &copy);
        void push(T);
        T pop();
        bool isFull();
        bool isEmpty();
        T top();
        void display();
        ~MyStack(){}
};

template <class T>
MyStack<T>::MyStack():
    Stack<T>::Stack()
{}

template <class T>
MyStack<T>::MyStack(int maxSize):
    Stack<T>::Stack(maxSize)
{}

template <class T>
MyStack<T>::MyStack(MyStack<T> &copy)
{
    this->maxSize = copy.maxSize;
    this->currentSize = copy.currentSize;
    this->arr = copy.arr;
}

template <class T>
bool MyStack<T>::isFull()
{
    return (this->currentSize == this->maxSize);
}

template <class T>
bool MyStack<T>::isEmpty()
{
    return (this->currentSize == 0);
}

template <class T>
void MyStack<T>::push(T value)
{
    if(isFull())
    {
        cout<<"Stack Overflow!"<<endl;
        return ;
    }
    this->arr[this->currentSize] = value;
    this->currentSize++;
}

template <class T>
T MyStack<T>::pop()
{
    if(isEmpty())
    {
        cout<<"Stack Underflow!"<<endl;
        return -1;
    }
    T value = this->arr[this->currentSize-1];
    this->currentSize--;
    return value;
}

template <class T>
T MyStack<T>::top()
{
    if(isEmpty())
    {
        cout<<"Stack Underflow!"<<endl;
        return -1;
    }
    return this->arr[this->currentSize - 1];
}

template <class T>
void MyStack<T>::display()
{
    if(isEmpty())
    {
        cout<<"Stack Underflow!"<<endl;
        return ;
    }
    cout<<"Max Size: "<<this->maxSize<<endl
        <<"Current Size: "<<this->currentSize<<endl
        <<"Values with there indexes: "
    <<endl;
    for (int i = 0; i < this->currentSize; i++)
        cout<<i<<". "<<this->arr[i]<<endl;
}