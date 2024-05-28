#include "Stack.h"

template <class T>
class MyStack: public Stack<T>
{
    public:
        MyStack();
        MyStack(int);
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
        T err = 1;
        cout<<"Stack Underflow!"<<endl;
        return err;
    }
    T value = this->arr[this->currentSize-1];
    this->currentSize--;
    return err;
}

template <class T>
T MyStack<T>::top()
{
    if(isEmpty())
    {
        T err = 1;
        cout<<"Stack Underflow!"<<endl;
        return err;
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