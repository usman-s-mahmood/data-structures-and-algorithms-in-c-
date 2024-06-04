#include "MyLinkedList.h"

class Stack
{
    protected:
        int currentSize;
        MyLinkedList *arr = new MyLinkedList;
    public:
        Stack();
        virtual void push(int value) = 0;
        virtual int pop() = 0;
        ~Stack()
        {
            delete[] arr;
        }
};

Stack::Stack()
{
    this->currentSize = 0;
    // this->arr = new MyLinkedList;
}