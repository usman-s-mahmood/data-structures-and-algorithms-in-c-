#include <iostream>
#include <stdexcept>

using namespace std;

class MinHeap {
private:
    int* heap;
    int capacity;
    int size;

    void heapifyUp(int index) {
        if (index && heap[parent(index)] > heap[index]) {
            swap(heap[index], heap[parent(index)]);
            heapifyUp(parent(index));
        }
    }

    void heapifyDown(int index) {
        int leftChild = left(index);
        int rightChild = right(index);
        int smallest = index;

        if (leftChild < size && heap[leftChild] < heap[smallest])
            smallest = leftChild;

        if (rightChild < size && heap[rightChild] < heap[smallest])
            smallest = rightChild;

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    int parent(int index) { return (index - 1) / 2; }
    int left(int index) { return (2 * index + 1); }
    int right(int index) { return (2 * index + 2); }

public:
    MinHeap(int capacity) {
        this->capacity = capacity;
        size = 0;
        heap = new int[capacity];
    }

    ~MinHeap() {
        delete[] heap;
    }

    void insert(int value) {
        if (size == capacity)
            throw overflow_error("Heap is full!");

        heap[size] = value;
        heapifyUp(size);
        size++;
    }

    int extractMin() {
        if (size == 0)
            throw out_of_range("Heap is empty!");

        int root = heap[0];
        heap[0] = heap[--size];
        heapifyDown(0);
        
        return root;
    }

    int getMin() const {
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
    MinHeap minHeap(10);
    minHeap.insert(3);
    minHeap.insert(2);
    minHeap.insert(15);
    minHeap.insert(5);
    minHeap.insert(4);
    minHeap.insert(45);

    minHeap.printHeap();

    cout << "Extracted min: " << minHeap.extractMin() << endl;
    minHeap.printHeap();

    cout << "Minimum value: " << minHeap.getMin() << endl;
    
    return 0;
}
