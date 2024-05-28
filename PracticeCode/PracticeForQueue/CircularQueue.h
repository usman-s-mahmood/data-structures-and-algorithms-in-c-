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
        T peek();
        void display();
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
bool CircularQueue<T>::isFull()
{
    return ((this->rear + 1) % this->maxSize == this->front);
}

template <class T>
bool CircularQueue<T>::isEmpty()
{
    return (this->front == this->rear);
}

template <class T>
void CircularQueue<T>::enqueue(T value)
{
    if (isFull())
    {
        cout<<"Queue Overflow!"<<endl;
        return ;
    }
    this->arr[this->rear % this->maxSize] = value;
    this->rear ++;
}

template <class T>
T CircularQueue<T>::dequeue()
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
T CircularQueue<T>::peek()
{
    if (isEmpty())
    {
        cout<<"Queue Underflow!"<<endl;
        return -1;
    }
    T value = this->arr[this->front % this->maxSize];
    return value;
}

template <class T>
void CircularQueue<T>::display()
{
    if (isEmpty())
    {
        cout<<"Queue Underflow!"<<endl;
        return ;
    }
    cout<<"Queue Stats: \n"
        <<"Value of front: "<<this->front<<"\n"
        <<"Value of rear: "<<this->rear<<"\n"
        <<"Index of front: "<<this->front % this->maxSize<<"\n"
        <<"Index of rear: "<<(this->rear % this->maxSize) - 1<<"\n"
        <<"Value at front: "<<this->arr[this->front % this->maxSize]<<"\n"
        <<"Value at rear: "<<this->arr[(this->rear % this->maxSize) - 1]<<"\n"
    <<endl;
    for (int i = this->front; i < this->rear; i++)
        cout<<i % this->maxSize<<". "<<this->arr[i % this->maxSize]<<endl;
}