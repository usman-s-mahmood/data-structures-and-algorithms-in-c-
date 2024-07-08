#include <iostream>
#include <stdexcept>

using namespace std;

class MaxHeap {
private:
    int* heap;
    int capacity;
    int size;

    void heapifyUp(int index) {
        if (index && heap[parent(index)] < heap[index]) {
            swap(heap[index], heap[parent(index)]);
            heapifyUp(parent(index));
        }
    }

    void heapifyDown(int index) {
        int leftChild = left(index);
        int rightChild = right(index);
        int largest = index;

        if (leftChild < size && heap[leftChild] > heap[largest])
            largest = leftChild;

        if (rightChild < size && heap[rightChild] > heap[largest])
            largest = rightChild;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

    int parent(int index) { return (index - 1) / 2; }
    int left(int index) { return (2 * index + 1); }
    int right(int index) { return (2 * index + 2); }

public:
    MaxHeap(int capacity) {
        this->capacity = capacity;
        size = 0;
        heap = new int[capacity];
    }

    ~MaxHeap() {
        delete[] heap;
    }

    void insert(int value) {
        if (size == capacity)
            throw overflow_error("Heap is full!");

        heap[size] = value;
        heapifyUp(size);
        size++;
    }

    int extractMax() {
        if (size == 0)
            throw out_of_range("Heap is empty!");

        int root = heap[0];
        heap[0] = heap[--size];
        heapifyDown(0);
        
        return root;
    }

    int getMax() const {
        if (size == 0)
            throw out_of_range("Heap is empty!");

        return heap[0];
    }

    bool isEmpty() const {
        return size == 0;
    }

    void printHeap() const {
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap maxHeap(10);
    maxHeap.insert(3);
    maxHeap.insert(2);
    maxHeap.insert(15);
    maxHeap.insert(5);
    maxHeap.insert(4);
    maxHeap.insert(45);

    maxHeap.printHeap();

    cout << "Extracted max: " << maxHeap.extractMax() << endl;
    maxHeap.printHeap();

    cout << "Maximum value: " << maxHeap.getMax() << endl;
    
    return 0;
}
