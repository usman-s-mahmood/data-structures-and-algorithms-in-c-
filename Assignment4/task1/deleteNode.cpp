#include "BinarySearchTree.h"

int main()
{
    BinarySearchTree<int> obj;
    obj.insert(10);
    obj.insert(11);
    obj.insert(9);
    obj.insert(7);
    obj.insert(8);
    obj.insert(6);
    obj.insert(30);
    obj.insert(20);
    obj.insert(25);
    // obj.inorder();
    // obj.deleteNode(6);
    obj.inorder();
    obj.deleteNode(11);
    obj.inorder();
    obj.deleteNode(9);
    obj.inorder();
    return 0;
}