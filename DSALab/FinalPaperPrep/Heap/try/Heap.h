#include <iostream>
#include <cmath>
#include <string>

using namespace std;

template <class T>
class Heap
{
    protected:
        int size, capacity;
        T *arr;
    public:
        Heap();
        Heap(int);
        virtual void insertValue(T) = 0;
        virtual T deleteValue() = 0;
        ~Heap();
};

template <class T>
Heap<T>::Heap()
{
    this->capacity = 100;
    this->size = 0;
    this->arr = new T[this->capacity];
}

template <class T>
Heap<T>::Heap(int capacity)
{
    this->capacity = capacity;
    this->size = 0;
    this->arr = new T[this->capacity];
}

template <class T>
Heap<T>::~Heap()
{
    delete[] this->arr;
}