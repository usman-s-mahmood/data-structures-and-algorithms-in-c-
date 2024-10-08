#include "MaxHeap.h"
using namespace std;

template <class T>
class MinHeap : public Heap<T>
{
    public:
        MinHeap();
        MinHeap(int);
        void insert(T);
        T remove();
        bool search(T);
        T peek();
        void display();
        bool isEmpty();
        ~MinHeap();
    private:
        void heapifyUp(int);
        void heapifyDown(int);
};

template <class T>
MinHeap<T>::MinHeap() :
    Heap<T>::Heap()
{}

template <class T>
MinHeap<T>::MinHeap(int size) :
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
        return this->arr[0];
    }
    cout << "Invalid Operation! Heap is empty" << endl;
    return T();
}

template <class T>
bool MinHeap<T>::search(T value)
{
    if (!isEmpty())
    {
        for (int i = 0; i < this->size; i++)
            if (this->arr[i] == value)
            {
                cout << "Value is present in the min heap at index: " << i << endl;
                return true;
            }
        cout << "Value is not present in the heap" << endl;
        return false;
    }
    cout << "Invalid Operation! Heap is empty" << endl;
    return false;
}

template <class T>
void MinHeap<T>::insert(T value)
{
    if (this->size == this->capacity)
    {
        cout << "Invalid Operation! Heap is full" << endl;
        return;
    }
    this->arr[this->size] = value;
    this->size += 1;
    heapifyUp(this->size - 1);
}

template <class T>
T MinHeap<T>::remove()
{
    if (!isEmpty())
    {
        T removedValue = this->arr[0];
        this->arr[0] = this->arr[this->size - 1];
        this->size -= 1;
        heapifyDown(0);
        return removedValue;
    }
    cout << "Invalid Operation! Heap is empty" << endl;
    return T();
}

template <class T>
void MinHeap<T>::display()
{
    if (!isEmpty())
    {
        for (int i = 0; i < this->size; i++)
            cout << this->arr[i] << ' ';
        cout << endl;
        return;
    }
    cout << "Invalid Operation! Heap is empty" << endl;
    return;
}

template <class T>
MinHeap<T>::~MinHeap()
{}

template <class T>
void MinHeap<T>::heapifyUp(int index)
{
    while (index > 0 && this->arr[(index - 1) / 2] > this->arr[index])
    {
        swap(this->arr[(index - 1) / 2], this->arr[index]);
        index = (index - 1) / 2;
    }
}

template <class T>
void MinHeap<T>::heapifyDown(int index)
{
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    
    if (leftChild < this->size && this->arr[leftChild] < this->arr[smallest])
        smallest = leftChild;
    
    if (rightChild < this->size && this->arr[rightChild] < this->arr[smallest])
        smallest = rightChild;
    
    if (smallest != index)
    {
        swap(this->arr[index], this->arr[smallest]);
        heapifyDown(smallest);
    }
}
