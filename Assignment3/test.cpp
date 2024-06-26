#include "BinarySearchTree.h"

int main()
{
    BinarySearchTree<int> obj;
    obj.insert(12);
    obj.insert(24);
    obj.insert(13);
    obj.insert(21);
    obj.insert(30);
    obj.arrayFun();
    obj.search(0);
    return 0;
}