#include "BinarySearchTree.h"

int main()
{
    BinarySearchTree<int> obj;
    obj.insert(9);
    obj.insert(7);
    obj.insert(12);
    obj.inorder();
    obj.search(90);
    return 0;
}