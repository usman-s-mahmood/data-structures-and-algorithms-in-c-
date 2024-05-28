#include "MyQueue.h"

template <class T>
MyQueue<T>::MyQueue():
    Queue<T>::Queue()
{}

template <class T>
MyQueue<T>::MyQueue(int maxSize):
    Queue<T>::Queue(maxSize)
{}

template <class T>
MyQueue<T>::MyQueue(MyQueue &copy)
{
    this->front = copy.front;
    this->rear = copy.rear;
    this->maxSize = copy.maxSize;
    this->currentSize = copy.currentSize;
    this->arr = copy.arr;
}

template <class T>
bool MyQueue<T>::isFull()
{
    return ((this->rear + 1) % this->maxSize == this->front);
}

template <class T>
bool MyQueue<T>::isEmpty()
{
    return (this->front == this->rear);
}

template <class T>
void MyQueue<T>::enqueue(T value)
{
    if (isFull())
    {
        cout<<"Queue Overflow!"<<endl;
        return ;
    }
    this->arr[this->rear % this->maxSize] = value;
    this->rear++;
}

template <class T>
T MyQueue<T>::dequeue()
{
    if (isEmpty())
    {
        cout<<"Queue Underflow!"<<endl;
        return -1;
    }
    T value = this->arr[this->front % this->maxSize];
    this->front++;
    return value;
}

template <class T>
void MyQueue<T>::display()
{
    if (isEmpty())
    {
        cout<<"Queue Underflow"<<endl;
        return ;
    }
    for (int i = this->front; i < this->rear; i++)
        cout<<this->arr[i % this->maxSize]<<' ';
    cout<<endl;
}

template <class T>
int MyQueue<T>::size()
{
    return (this->rear - this->front);
}

template <class T>
T MyQueue<T>::peek()
{
    if (isEmpty())
    {
        cout<<"Queue Underflow!"<<endl;
        return -1;
    }
    T value = this->arr[this->front % this->maxSize];
    return value;
}