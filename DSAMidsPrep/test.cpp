#include "MyStack.h"

int main()
{
    MyStack<string> obj(10);
    obj.push("This is a string Value!");
    obj.push("This is a string Value!");
    obj.push("This is a string Value!");
    obj.push("This is a string Value!");
    obj.display();
    return 0;
}