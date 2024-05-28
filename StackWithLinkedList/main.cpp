#include "MyStack.h"

int main()
{
    MyStack obj;
    obj.push(1);
    obj.push(2);
    obj.push(3);
    obj.push(4);
    obj.display();
    cout<<obj.pop()<<endl;
    obj.display();
    obj.push(12);
    obj.display();
    return 0;
}