#include "Queue.h"

class MyQueue: public Queue
{
    public:
        MyQueue();
        bool isEmpty();
        void enqueue(int);
        int dequeue();
        int peek();
        void display();
        ~MyQueue(){}
};

MyQueue::MyQueue():
    Queue::Queue()
{}

bool MyQueue::isEmpty()
{
    return (this->currentSize == 0);
}

void MyQueue::enqueue(int value)
{
    arr.insertAtTail(value);
    this->currentSize++;
}

int MyQueue::dequeue()
{
    if (isEmpty())
    {
        cout<<"No values are in the queue!"<<endl;
        return -1;
    }
    int value = arr.deleteAtHead();
    this->currentSize--;
    return value;
}

int MyQueue::peek()
{
    if (isEmpty())
    {
        cout<<"No values are in the queue!"<<endl;
        return -1;
    }
    int value = arr.headValue();
    return value;
}

void MyQueue::display()
{
    if (isEmpty())
    {
        cout<<"No values are in the queue!"<<endl;
        return ;
    }
    arr.display();
}