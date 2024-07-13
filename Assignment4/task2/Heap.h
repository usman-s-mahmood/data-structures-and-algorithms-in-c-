#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

template <class T>
class Heap
{
    protected:
        T *arr;
        int size, capacity;
    public:
        Heap();
        Heap(int);
        virtual void insert(T) = 0;
        virtual T remove() = 0;
        virtual bool search(T) = 0;
        virtual T peek() = 0;
        virtual void display() = 0;
        virtual bool isEmpty() = 0;
        ~Heap();
};

template <class T>
Heap<T>::Heap()
{
    this->size = 0;
    this->capacity = 100;
    this->arr = new T[capacity];
}

template <class T>
Heap<T>::Heap(int capacity)
{
    this->size = 0;
    this->capacity = capacity;
    this->arr = new T[capacity];
}

template <class T>
Heap<T>::~Heap()
{
    delete [] this->arr;
}