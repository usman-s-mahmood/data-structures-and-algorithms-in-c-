#include "MyStack.h"

int main()
{
    MyStack<int> obj(5);
    obj.push(12);
    obj.push(13);
    obj.push(14);
    cout<<obj.pop()<<endl;
    obj.display();
    cout<<obj.top()<<endl;
    obj.display();
    return 0;
}