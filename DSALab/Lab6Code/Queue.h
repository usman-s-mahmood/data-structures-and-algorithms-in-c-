#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

template <class T>
class Queue
{
    protected:
        int maxSize, currentSize;
        T *array;
    public:
        Queue();
        Queue(int);
        virtual void enqueue(int) = 0;
        virtual T dequeue() = 0;
        ~Queue()
        {
            delete [] array;
        }
};

template <class T>
Queue<T>::Queue()
{
    this->maxSize = 10;
    this->currentSize = 0;
    this->array = new T [this->maxSize];
}

template <class T>
Queue<T>::Queue(int maxSize)
{
    this->maxSize = maxSize;
    this->currentSize = 0;
    this->array = new T [this->maxSize];
}