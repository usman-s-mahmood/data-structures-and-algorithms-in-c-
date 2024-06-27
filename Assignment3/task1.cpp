#include "BinarySearchTree.h"

int main()
{
    BinarySearchTree<int> obj;
    obj.insert(10);
    obj.insert(-15);
    obj.insert(-40);
    obj.insert(20);
    obj.insert(50);
    obj.insert(15);
    obj.insert(3);
    obj.insert(15);
    // obj.inorder();
    obj.target_subset(20);
    return 0;
}