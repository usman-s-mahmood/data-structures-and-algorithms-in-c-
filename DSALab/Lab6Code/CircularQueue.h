#include "Queue.h"

template <class T>
class CircularQueue: public Queue<T>
{
    protected:
        int front, rear;
    public:
        CircularQueue();
        CircularQueue(int);
        bool isFull();
        bool isEmpty();
        void enqueue(T);
        T dequeue();
        void display();
        T top();
        ~CircularQueue(){}
};

template <class T>
CircularQueue<T>::CircularQueue():
    front(0),
    rear(0),
    Queue<T>::Queue()
{}

template <class T>
CircularQueue<T>::CircularQueue(int maxSize):
    front(0),
    rear(0),
    Queue<T>::Queue(maxSize)
{}

template <class T>
bool CircularQueue<T>::isEmpty()
{
    return (this->front == this->rear);
}

template <class T>
bool CircularQueue<T>::isFull()
{
    return ((this->rear + 1) % this->maxSize == this->front);
}

template <class T>
void CircularQueue<T>::enqueue(T value)
{
    if(isFull())
    {
        cout<<"Queue Overflow!"<<endl;
        return ;
    }
    this->array[this->rear % this->maxSize] = value;
    this->rear++;
}

template <class T>
T CircularQueue<T>::dequeue()
{
    if(isEmpty())
    {
        cout<<"Queue Underflow!"<<endl;
        return -1;
    }
    T value = this->array[this->front % this->maxSize];
    this->front++;
    return value;
}

template <class T>
void CircularQueue<T>::display()
{
    if(isEmpty())
    {
        cout<<"Queue Under flow!"<<endl;
        return ;
    }
    cout<<"Value of Front: "<<front<<endl
        <<"Value of rear: "<<rear<<endl
        <<"Value of max size: "<<this->maxSize<<endl
        <<"Value of current Size: "<<rear - front<<endl
        <<"Value at top: "<<this->array[this->front % this->maxSize]<<endl
        <<"Index of top value: "<<this->front % this->maxSize
    <<endl;
    for (int i = this->front; i < this->rear; i++)
        cout<<i%this->maxSize<<". "<<this->array[i%this->maxSize]<<endl;
}


template <class T>
T CircularQueue<T>::top()
{
    if(isEmpty())
    {
        cout<<"Queue Underflow!"<<endl;
        return -1;
    }
    T value = this->array[this->front % this->maxSize];
    // this->front++;
    return value;
}
