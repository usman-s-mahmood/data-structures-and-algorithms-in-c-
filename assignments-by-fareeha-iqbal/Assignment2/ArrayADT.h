#include <iostream>
#include <string>

using namespace std;

template <class T>
class ArrayADT
{
    protected:
        T *array;
        int size, capacity;
    public:
        ArrayADT();
        ArrayADT(int);
        virtual void append(T) = 0;
        virtual void deleteItem() = 0;
        virtual void display() = 0;
        ~ArrayADT();
};

template <class T>
ArrayADT<T>::ArrayADT()
{
    this->capacity = 100;
    this->size = 0;
    this->array = new T[this->capacity];
}

template <class T>
ArrayADT<T>::ArrayADT(int capacity)
{
    this->capacity = capacity;
    this->size = 0;
    this->array = new T[this->capacity];
}

template <class T>
ArrayADT<T>::~ArrayADT()
{
    delete this->array;
}