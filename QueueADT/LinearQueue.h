#include "Queue.h"

template <class T>
class LinearQueue: public Queue<T>
{
    public:
        LinearQueue();
        LinearQueue(int);
        bool isFull();
        bool isEmpty();
        void enqueue(int);
        T dequeue();
        void display();
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
void LinearQueue<T>::enqueue(int value)
{
    if(isFull())
    {
        cout<<"Queue is full and no more values can be inserted!"<<endl;
        return ;
    }
    this->array[this->currentSize] = value;
    this->currentSize++;
}

template <class T>
T LinearQueue<T>::dequeue()
{
    if(isEmpty())
    {
        cout<<"Queue is empty!"<<endl;
        return -1;
    }
    T value = this->array[0];
    for (int i = 0; i < this->currentSize; i++)
        this->array[i] = this->array[i+1];
    this->currentSize--;
    return value;
}

template <class T>
void LinearQueue<T>::display()
{
    if(isEmpty())
    {
        cout<<"No values in queue!"<<endl;
        return ;
    }
    cout<<"Current Size: "<<this->currentSize<<endl
        <<"Max Size: "<<this->maxSize
    <<endl;
    for(int i = 0; i < this->currentSize; i++)
        cout<<this->array[i]<<' ';
    cout<<endl;
}
