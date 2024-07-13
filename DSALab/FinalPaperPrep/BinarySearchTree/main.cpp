#include "BinarySearchTree.h"

int main()
{
    BinarySearchTree<int> obj;
    obj.insertNode(30);
    obj.insertNode(10);
    obj.insertNode(20);
    obj.inorder();
    obj.preorder();
    obj.postorder();
    return 0;
}