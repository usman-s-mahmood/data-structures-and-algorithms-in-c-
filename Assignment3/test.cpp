#include "BinarySearchTree.h"

int main()
{
    BinarySearchTree<int> obj;
    obj.insert(12);
    obj.insert(24);
    obj.insert(13);
    obj.insert(21);
    obj.insert(30);
    obj.insert(-40);
    obj.insert(10);
    obj.insert(50);
    obj.target_subset(40);
    obj.search(0);
    BinarySearchTree<int> obj2;
    obj2.insert(-1);
    obj2.insert(-3);
    obj2.insert(-12);
    obj2.insert(10);
    obj2.insert(5);
    obj2.insert(7);
    obj2.insert(9);
    obj2.insert(30);
    obj2.insert(40);
    obj2.insert(15);
    obj.mergeBSTsIntoDDL(obj, obj2);
    obj.maxValue();
    obj.minValue();
    return 0;
}