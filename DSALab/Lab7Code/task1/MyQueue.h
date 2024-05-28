#include "Queue.h"

template <class T>
class MyQueue: public Queue<T>
{
    public:
        MyQueue(){}
        void enqueue(T);
        T dequeue();
        bool isEmpty();
        void display();
        ~MyQueue(){}
};