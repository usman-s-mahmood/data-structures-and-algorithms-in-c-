#include "MaxHeap.h"

template <class T>
class MinHeap: public Heap<T>
{
    public:
        MinHeap();
        MinHeap(int);
        void insert(T);
        bool remove(T);
        bool search(T);
        T peek();
        void display();
        bool isEmpty();
        ~MinHeap();
};

template <class T>
MinHeap<T>::MinHeap():
    Heap<T>::Heap()
{}

template <class T>
MinHeap<T>::MinHeap(int size):
    Heap<T>::Heap(size)
{}

template <class T>
bool MinHeap<T>::isEmpty()
{
    return (this->size == 0);
}

template <class T>
T MinHeap<T>::peek()
{
    if (!isEmpty())
    {
        T value = T();
        value = this->arr[0];
        return value;
    }
    cout << "Invalid Operation! Heap is empty" << endl;
    return T();
}

template <class T>
bool MinHeap<T>::search(T value)
{
    if (!isEmpty())
    {

    }
    cout << "Invalid Operation! Heap is empty" << endl;
    return false;
}

template <class T>
void MinHeap<T>::insert(T value)
{

}

template <class T>
bool MinHeap<T>::remove(T value)
{
    if (!isEmpty())
    {
        if (search(value))
        {

        }
        return false;
    }
    cout << "Invalid Operation! Heap is empty" << endl;
    return false;
}

template <class T>
void MinHeap<T>::display()
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
MinHeap<T>::~MinHeap()
{
    Heap<T>::~Heap();
}