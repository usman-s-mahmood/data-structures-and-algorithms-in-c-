#include "Heap.h"

template <class T>
class MinHeap: public Heap<T>
{
    public:
        MinHeap();
        MinHeap(int);
        void insertValue(T);
        T deleteValue();
        void printHeap();
        bool isEmpty();
        bool isFull();
        ~MinHeap();
};

template <class T>
MinHeap<T>::MinHeap():
    Heap<T>::Heap()
{}

template <class T>
bool MinHeap<T>::isEmpty()
{
    return (this->size == 0);
}

template <class T>
bool MinHeap<T>::isFull()
{
    return (this->size == this->capacity);
}

template <class T>
void MinHeap<T>::insertValue(T value)
{
    if (!isFull())
    {
        this->arr[this->size] = value;
        this->size++;
        return ;
    }
    cout << "Invalid Operation! Heap is full" << endl;
    return ;
}

template <class T>
void MinHeap<T>::printHeap()
{
    if (!isEmpty())
    {
        for (int i = 0; i < this->size; i++)
            cout << this->arr[i] << ' ';
        cout << endl;
        return ;
    }
    cout << "Invalid Operation! Heap is empty" << endl;
    return ;
}

template <class T>
T MinHeap<T>::deleteValue()
{
    if (!isEmpty())
    {
        T temp[this->size];
        T value = this->arr[0];
        for (int i = 0; i < this->size; i++)
            if (this->arr[i] < value)
                value = this->arr[i];
        for (int i = 0; i < this->size; i++)
            if (this->arr[i] == value)
                break;
        
        return value;
    }
    cout << "Invalid Operation! Heap is empty" << endl;
    return T();
}

template <class T>
MinHeap<T>::MinHeap(int capacity):
    Heap<T>::Heap(capacity)
{}

template <class T>
MinHeap<T>::~MinHeap()
{
    Heap<T>::~Heap();
}