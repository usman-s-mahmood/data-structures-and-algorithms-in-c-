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
        // cout << "Least value is: " << value << endl;
        int itr = 0, temp_itr = 0;
        for (itr; itr < this->size; itr++)
        {
            if (this->arr[itr] == value)
                break;
            temp[temp_itr] = this->arr[itr];
            temp_itr++;
        }
        while (itr < this->size)
        {
            itr++;
            temp[temp_itr] = this->arr[itr];
            temp_itr++;
            if (itr == this->size - 1)
                break;
        }
        for (int i = 0; i < this->size - 1; i++)
            this->arr[i] = temp[i];
        this->size--;
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
    // Heap<T>::~Heap();
}