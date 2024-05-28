#include "Stack.h"

template <class T>
class MyStack: public Stack<T>
{
    public:
        MyStack(){}
        bool isEmpty();
        void display();
        T pop();
        void push(T);
        ~MyStack(){}
};
