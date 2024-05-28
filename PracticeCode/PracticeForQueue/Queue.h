#include <iostream>
#include <cmath>
#include <string>

using namespace std;

template <class T>
class Queue
{
    protected:
        int maxSize, currentSize;
        T *arr;
    public:
        Queue();
        Queue(int);
        virtual void enqueue(T) = 0;
        virtual T dequeue() = 0;
        ~Queue()
        {
            delete [] arr;
        }
};

template <class T>
Queue<T>::Queue()
{
    this->maxSize = 10;
    this->currentSize = 0;
    this->arr = new T[this->maxSize];
}

template <class T>
Queue<T>::Queue(int maxSize)
{
    this->maxSize = maxSize;
    this->currentSize = 0;
    this->arr = new T[this->maxSize];
}