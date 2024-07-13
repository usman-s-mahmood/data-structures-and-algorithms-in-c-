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
        virtual ~Heap();
};

template <class T>
Heap<T>::Heap()
{
    this->size = 0;
    this->capacity = 100;
    this->arr = new T[this->capacity];
}

template <class T>
Heap<T>::Heap(int capacity)
{
    this->size = 0;
    this->capacity = capacity;
    this->arr = new T[this->capacity];
}

template <class T>
Heap<T>::~Heap()
{
    delete[] this->arr;
}

template <class T>
class MaxHeap : public Heap<T>
{
    public:
        MaxHeap();
        MaxHeap(int);
        void insert(T);
        T remove();
        bool search(T);
        T peek();
        void display();
        bool isEmpty();
        ~MaxHeap();
    private:
        void heapifyUp(int);
        void heapifyDown(int);
};

template <class T>
MaxHeap<T>::MaxHeap() :
    Heap<T>::Heap()
{}

template <class T>
MaxHeap<T>::MaxHeap(int size) :
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
        return this->arr[0];
    }
    cout << "Invalid Operation! Heap is empty" << endl;
    return T();
}

template <class T>
bool MaxHeap<T>::search(T value)
{
    if (!isEmpty())
    {
        for (int i = 0; i < this->size; i++)
            if (this->arr[i] == value)
            {
                cout << "Value is present in the max heap at index: " << i << endl;
                return true;
            }
        cout << "Value is not present in the heap" << endl;
        return false;
    }
    cout << "Invalid Operation! Heap is empty" << endl;
    return false;
}

template <class T>
void MaxHeap<T>::insert(T value)
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
T MaxHeap<T>::remove()
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
void MaxHeap<T>::display()
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
MaxHeap<T>::~MaxHeap()
{}

template <class T>
void MaxHeap<T>::heapifyUp(int index)
{
    while (index > 0 && this->arr[(index - 1) / 2] < this->arr[index])
    {
        swap(this->arr[(index - 1) / 2], this->arr[index]);
        index = (index - 1) / 2;
    }
}

template <class T>
void MaxHeap<T>::heapifyDown(int index)
{
    int largest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    
    if (leftChild < this->size && this->arr[leftChild] > this->arr[largest])
        largest = leftChild;
    
    if (rightChild < this->size && this->arr[rightChild] > this->arr[largest])
        largest = rightChild;
    
    if (largest != index)
    {
        swap(this->arr[index], this->arr[largest]);
        heapifyDown(largest);
    }
}

int main()
{
    fstream fileObj1("input.txt", ios::in);
    int size = 0;
    int dump = int();
    while (fileObj1 >> dump)
    {
        size += 1;
    }
    fileObj1.close();
    cout << "Size of Heap is: " << size << endl;
    
    fstream fileObj2("input.txt", ios::in);
    int arr[size];
    for (int i = 0; i < size; i++)
        fileObj2 >> arr[i];
    fileObj2.close();
    cout << "Values read from input.txt: " << endl;
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << endl;
    cout << "Values inserted in max heap: " << endl;
    MaxHeap<int> heap(size);
    for (int i = 0; i < size; i++)
        heap.insert(arr[i]);
    heap.display();
    cout << "After removing values from max heap: " << endl;
    while (!heap.isEmpty())
        cout << heap.remove() << ' ';
    cout << endl;
    return 0;
}
