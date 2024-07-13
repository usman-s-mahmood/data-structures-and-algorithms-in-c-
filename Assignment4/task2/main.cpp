#include "MinHeap.h" // MaxHeap is already included in MinHeap file to avoid re declaration

int main()
{
    fstream fileObj1("input.txt", ios::in);
    int size = 0;
    int dump = int();
    while (fileObj1 >> dump)
        size += 1;
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

    cout << "Insertion of input values in min heap: " << endl;
    MinHeap<int> minHeap(size);
    for (int i = 0; i < size; i++)
        minHeap.insert(arr[i]);
    minHeap.display();
    cout << "After removing of values from min heap: " << endl;
    while (!minHeap.isEmpty())
        cout << minHeap.remove() << ' ';
    cout << endl;
    return 0;
}
