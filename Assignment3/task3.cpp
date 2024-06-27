#include "BinarySearchTree.h"
#include <heapapi.h>

int main()
{
    BinarySearchTree<int> obj1, obj2;
    obj1.insert(20);
    obj1.insert(30);
    obj1.insert(100);
    obj1.insert(25);
    obj1.insert(10);
    obj2.insert(50);
    obj2.insert(70);
    obj2.insert(5);
    obj1.mergeBSTsIntoDDL(obj1, obj2);
    obj1.parentNode(25);
    return 0;
}