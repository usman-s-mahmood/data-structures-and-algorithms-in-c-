#include "MinHeap.h" // MaxHeap is already included in MinHeap file to avoid re declaration

int main()
{
    fstream fileObj1("input.txt", ios::in);
    int size = 0;
    int dump = int();
    while (!fileObj1.eof())
    {
        fileObj1 >> dump;
        size += 1;
    }
    fileObj1.close();
    cout << "Size of Heap is: " << size << endl;
    fstream fileObj2("input.txt", ios::in);
    int arr[size] = {0};
    for (int i = 0; i < size; i++)
        fileObj2 >> arr[i];
    fileObj2.close();
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << endl;
    return 0;
}