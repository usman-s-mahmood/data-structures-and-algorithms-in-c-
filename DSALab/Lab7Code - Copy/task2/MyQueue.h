#include "Queue.cpp"

template <class T>
class MyQueue: public Queue<T>
{
    public:
        MyQueue();
        MyQueue(int maxSize);
        MyQueue(MyQueue &copy);
        bool isFull();
        bool isEmpty();
        void display();
        int size();
        T peek();
        void enqueue(T);
        T dequeue();
        ~MyQueue(){}
};