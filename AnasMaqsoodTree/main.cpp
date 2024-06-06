#include "BinarySearchTree.h"
/*
CONSTRUCT A BST
• Construct a BST of following data:
70, 50, 25, 90, 10, 101, 85, 62, 120, 55, 77, 20, 110
i. What is height and depth of tree in part b?
4 is the length and depth of tree from left and right extremes
ii. What is height and depth of node having value 90? 
Depth is 1 and height is 3
iii. What is height depth of node having value 20?
that would be 5 as it's path contains 70, 50, 25, 10 and 20
Depth is 4 and height is 0
iv. Write all the leaf nodes of the tree.
5 leaf nodes are in the tree: (20, 55, 77, 85, 110)
*/
int main()
{
    BinarySearchTree<int> obj;
    obj.insert(70);
    obj.insert(50);
    obj.insert(25);
    obj.insert(90);
    obj.insert(10);
    obj.insert(101);
    obj.insert(85);
    obj.insert(62);
    obj.insert(120);
    obj.insert(55);
    obj.insert(77);
    obj.insert(20);
    obj.insert(110);
    obj.inorder();
    return 0;
}