#include "MyLinkedList.cpp"

template <class T>
class Queue
{
    protected:
        MyLinkedList<T> queue;
    public:
        Queue(){}
        virtual void enqueue(T) = 0;
        virtual T dequeue() = 0;
        ~Queue(){}
};