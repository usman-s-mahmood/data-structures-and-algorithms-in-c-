#include "Heap.h"

template <class T>
class MaxHeap: public Heap<T>
{
    public:
        MaxHeap();
        MaxHeap(int);
        void insert(T);
        bool remove(T);
        bool search(T);
        T peek();
        void display();
        bool isEmpty();
        ~MaxHeap();
};

template <class T>
MaxHeap<T>::MaxHeap():
    Heap<T>::Heap()
{}

template <class T>
MaxHeap<T>::MaxHeap(int size):
    Heap<T>::Heap(size)
{}

template <class T>
bool MaxHeap<T>::isEmpty()
{
    return (this->size == 0);
}

template <class T>
T MaxHeap<T>::peek()
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
bool MaxHeap<T>::search(T value)
{
    if (!isEmpty())
    {

    }
    cout << "Invalid Operation! Heap is empty" << endl;
    return false;
}

template <class T>
void MaxHeap<T>::insert(T value)
{

}

template <class T>
bool MaxHeap<T>::remove(T value)
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
void MaxHeap<T>::display()
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
MaxHeap<T>::~MaxHeap()
{
    Heap<T>::~Heap();
}