#include "Queue.h"

template <class T>
Queue<T>::Queue()
{
    this->maxSize = 10;
    this->currentSize = 0;
    this->front = 0;
    this->rear = 0;
    this->arr = new T[this->maxSize];
}

template <class T>
Queue<T>::Queue(int maxSize)
{
    this->maxSize = maxSize;
    this->currentSize = 0;
    this->front = 0;
    this->rear = 0;
    this->arr = new T[maxSize];
}
