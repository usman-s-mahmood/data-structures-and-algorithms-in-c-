// #include "LinearQueue.h"
#include "CircularQueue.h"

int main()
{
    // LinearQueue<int> obj(5);
    // obj.enqueue(12);
    // obj.enqueue(13);
    // obj.enqueue(14);
    // obj.enqueue(15);
    // obj.enqueue(16);
    // obj.display();
    // cout<<"Dequeued Value is: "<<obj.dequeue()<<endl;
    // obj.display();
    CircularQueue <int> obj(8);
    obj.enqueue(4);
    obj.enqueue(5);
    obj.enqueue(6);
    obj.enqueue(7);
    obj.enqueue(8);
    int arr[] = {
        obj.dequeue(),
        obj.dequeue(),
        obj.dequeue()
    };
    obj.enqueue(12);
    obj.enqueue(15);
    obj.display();
    for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
        cout<<arr[i]<<' ';
    cout<<endl;
    cout<<obj.dequeue()<<endl;
    obj.display();
    obj.enqueue(13);
    obj.enqueue(14);
    obj.enqueue(15);
    obj.enqueue(15);
    obj.enqueue(15);
    obj.enqueue(15);
    // obj.dequeue();
    obj.display();
    return 0;
}