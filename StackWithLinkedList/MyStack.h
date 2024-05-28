#include "Stack.h"

class MyStack: public Stack
{
    public:
        MyStack();
        bool isEmpty();
        void push(int value);
        int pop();
        int top();
        void display();
        ~MyStack(){}
};

MyStack::MyStack():
    Stack::Stack()
{}

bool MyStack::isEmpty()
{
    return (this->currentSize == 0);
}

void MyStack::push(int value)
{
    this->arr->insertAtTail(value);
    this->currentSize++;
}

int MyStack::pop()
{
    if(isEmpty())
    {
        cout<<"Empty Stack has no values for pop operation!"<<endl;
        return -1;
    }
    int value = this->arr->deleteAtTail();
    this->currentSize--;
    return value;
}

int MyStack::top()
{
    if(isEmpty())
    {
        cout<<"No values are in the stack!"<<endl;
        return -1;
    }
    int value = this->arr->tailValue();
    return value;
}

void MyStack::display()
{
    if (isEmpty())
    {
        cout<<"Stack is Empty!"<<endl;
        return ;
    }
    this->arr->display();
}