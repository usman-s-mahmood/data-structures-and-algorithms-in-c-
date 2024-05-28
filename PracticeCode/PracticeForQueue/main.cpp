#include "CircularQueue.h"

int main()
{
    CircularQueue<int> obj(10);
    obj.enqueue(12);
    obj.enqueue(13);
    obj.enqueue(14);
    obj.enqueue(15);
    obj.peek();
    obj.display();
    int arr[] = {
        obj.dequeue(),
        obj.dequeue(),
        obj.dequeue()
    };
    obj.display();
    obj.enqueue(16);
    obj.enqueue(17);
    obj.enqueue(18);
    obj.enqueue(19);
    obj.display();
    obj.dequeue();
    obj.dequeue();
    obj.dequeue();
    obj.dequeue();
    obj.enqueue(161);
    obj.enqueue(171);
    obj.enqueue(181);
    obj.enqueue(191);
    obj.enqueue(192);
    obj.enqueue(193);
    obj.enqueue(194);
    obj.enqueue(195);
    obj.enqueue(196);
    obj.enqueue(197);
    obj.enqueue(197);
    obj.enqueue(197);
    obj.enqueue(197);
    obj.enqueue(197);
    obj.enqueue(197);
    obj.enqueue(197);
    obj.display();
    return 0;
}