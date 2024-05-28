#include <iostream>
#include <string>
#include <cmath>
#include <conio.h>

using namespace std;

template <class T>
class Queue
{
    protected:
        int currentSize, maxSize, front, rear;
        T *arr;
    public:
        Queue();
        Queue(int maxSize);
        virtual void enqueue(T) = 0;
        virtual T dequeue() = 0;
        virtual bool isFull() = 0;
        virtual bool isEmpty() = 0;
        virtual void display() = 0;
        virtual int size() = 0;
        virtual T peek() = 0;
        ~Queue()
        {
            delete [] arr;
        }
};