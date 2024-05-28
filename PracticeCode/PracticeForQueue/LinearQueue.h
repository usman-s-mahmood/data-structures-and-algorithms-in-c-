#include "Queue.h"

template <class T>
class LinearQueue: public Queue<T>
{
    public:
        LinearQueue();
        LinearQueue(int);
        bool isFull();
        bool isEmpty();
        T peek();
        void display();
        void enqueue(T);
        T dequeue();
        ~LinearQueue(){}
};

template <class T>
LinearQueue<T>::LinearQueue():
    Queue<T>::Queue()
{}

template <class T>
LinearQueue<T>::LinearQueue(int maxSize):
    Queue<T>::Queue(maxSize)
{}

template <class T>
bool LinearQueue<T>::isFull()
{
    return (this->currentSize == this->maxSize);
}

template <class T>
bool LinearQueue<T>::isEmpty()
{
    return (this->currentSize == 0);
}

template <class T>
void LinearQueue<T>::enqueue(T value)
{
    if (isFull())
    {
        cout<<"Queue Overflow!"<<endl;
        return ;
    }
    this->arr[this->currentSize] = value;
    this->currentSize++;
}

template <class T>
T LinearQueue<T>::dequeue()
{
    if(isEmpty())
    {
        cout<<"Queue Underflow!"<<endl;
        return -1;
    }
    T value = this->arr[0];
    for (int i = 0; i < this->currentSize; i++)
        this->arr[i] = this->arr[i+1];
    this->currentSize--;
    return value;
}

template <class T>
T LinearQueue<T>::peek()
{
    if(isEmpty())
    {
        cout<<"Queue Underflow!"<<endl;
        return -1;
    }
    T value = this->arr[0];
    return value;
}

template <class T>
void LinearQueue<T>::display()
{
    if(isEmpty())
    {
        cout<<"Queue Underflow!"<<endl;
        return ;
    }
    for (int i = 0; i < this->currentSize; i++)
        cout<<this->arr[i]<<' ';
    cout<<endl;
}

