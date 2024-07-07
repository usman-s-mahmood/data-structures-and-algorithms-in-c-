#include "BinarySearchTree.h"

int main()
{
    BinarySearchTree<int> obj;
    obj.insert(10);
    obj.insert(20);
    obj.insert(30);
    obj.insert(40);
    obj.insert(50);
    obj.insert(25);
    obj.insert(35);
    obj.insert(90);
    BinarySearchTree<int> obj2;
    obj2.insert(30);
    obj2.insert(10);
    obj2.insert(20);
    obj2.insert(40);
    obj2.insert(50);
    obj2.insert(25);
    obj2.insert(35);
    obj2.insert(90);
    obj2.identical_trees(obj, obj2);
    return 0;
}