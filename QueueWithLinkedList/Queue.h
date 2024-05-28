#include "MyLinkedList.h"

class Queue
{
    protected:
        int currentSize;
        MyLinkedList arr;
    public:
        Queue();
        virtual void enqueue(int) = 0;
        virtual int dequeue() = 0;
        ~Queue(){} 
};

Queue::Queue()
{
    this->currentSize = 0;
}