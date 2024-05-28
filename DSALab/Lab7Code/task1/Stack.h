#include "MyLinkedList.cpp"

template <class T>
class Stack
{
    protected:
        MyLinkedList<T> stk;
    public:
        Stack(){}
        virtual void push(T) = 0;
        virtual T pop() = 0;
        ~Stack(){}
};