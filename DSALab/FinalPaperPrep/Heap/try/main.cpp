#include "MinHeap.h"

int main()
{
    MinHeap<int> obj;
    obj.insertValue(6);
    obj.insertValue(62);
    obj.insertValue(8);
    obj.insertValue(13);
    obj.insertValue(12);
    obj.insertValue(24);
    obj.insertValue(15);
    obj.insertValue(10);
    obj.insertValue(50);
    obj.insertValue(77);
    obj.printHeap();
    cout << "Extracted Values from min heap: ";
    while (!obj.isEmpty())
        cout << obj.deleteValue() << ' ';
    cout << endl;
    return 0;
}