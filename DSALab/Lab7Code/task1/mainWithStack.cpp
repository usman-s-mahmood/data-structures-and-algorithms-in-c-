#include "MyStack.cpp"
// #include "MyQueue.cpp"

int main()
{
    cout<<"Stack Implementation!"<<endl;
    MyStack<int> stk;
    stk.push(16);
    stk.push(32);
    stk.push(96);
    stk.push(81);
    stk.push(90);
    stk.push(44);
    stk.push(57);
    stk.display();
    cout<<stk.pop()<<endl;
    cout<<stk.pop()<<endl;
    cout<<stk.pop()<<endl;
    stk.display(); /*
    cout<<"Queue Implementation!"<<endl;
    MyQueue<int> queue;
    queue.enqueue(17);
    queue.enqueue(2);
    queue.enqueue(7);
    queue.enqueue(56);
    queue.enqueue(99);
    queue.enqueue(5);
    queue.display();
    cout<<queue.dequeue()<<endl;
    cout<<queue.dequeue()<<endl;
    cout<<queue.dequeue()<<endl;
    queue.display(); */
    return 0;
}