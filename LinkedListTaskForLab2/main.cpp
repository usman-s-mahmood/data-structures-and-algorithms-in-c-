#include "MyQueue.h"

int main()
{
    MyQueue obj;
    obj.enqueue(12);
    obj.enqueue(13);
    obj.enqueue(14);
    obj.enqueue(15);
    obj.enqueue(16);
    obj.enqueue(17);
    cout<<"Value at top of queue: "<<obj.peek()<<endl;
    obj.display();
    cout<<"Value removed from queue: "<<obj.dequeue()<<endl;
    obj.display();
    return 0;
}