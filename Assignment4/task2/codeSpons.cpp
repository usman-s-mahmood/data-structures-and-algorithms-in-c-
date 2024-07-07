#include <iostream>
using namespace std;

class MinHeap {
    int* heapArray;
    int capacity;
    int size;

public:
    MinHeap(int cap) : capacity(cap), size(0) {
        heapArray = new int[cap];
    }

    ~MinHeap() {
        delete[] heapArray;
    }

    bool isEmpty() const {
        return size == 0;
    }

    void insert(int key) {
        if (size == capacity) {
            cout << "Heap is full" << endl;
            return;
        }

        int i = size++;
        heapArray[i] = key;

        while (i != 0 && heapArray[parent(i)] > heapArray[i]) {
            swap(&heapArray[i], &heapArray[parent(i)]);
            i = parent(i);
        }
    }

    void display() const {
        if (isEmpty()) {
            cout << "Heap is empty" << endl;
            return;
        }

        for (int i = 0; i < size; ++i) {
            cout << heapArray[i] << " ";
        }
        cout << endl;
    }

private:
    int parent(int i) const { return (i - 1) / 2; }
    int left(int i) const { return 2 * i + 1; }
    int right(int i) const { return 2 * i + 2; }

    void swap(int* x, int* y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
};

int main() {
    MinHeap heap(10);

    heap.display(); // should print "Heap is empty"

    heap.insert(3);
    heap.insert(1);
    heap.insert(6);
    heap.insert(5);
    heap.insert(2);
    heap.insert(4);

    heap.display(); // should print the elements in the heap

    return 0;
}
