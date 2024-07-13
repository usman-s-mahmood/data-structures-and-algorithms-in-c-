#include "BinarySearchTree.h"

int main()
{
    BinarySearchTree<int> bst;
    
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    cout << "Task 1: Part A - Valid BST function" << endl;
    bst.isValidBST();

    cout << "Task 1: Part B - BST to sorted array" << endl;
    bst.arrayFun();

    cout << "Task 1: Part C - Distance between nodes" << endl;
    bst.distanceBetweenNodes(20, 40);

    cout << "Task 1: Part D - Identical trees" << endl;
    BinarySearchTree<int> bst2;
    bst2.insert(50);
    bst2.insert(30);
    bst2.insert(70);
    bst2.insert(20);
    bst2.insert(40);
    bst2.insert(60);
    bst2.insert(80);
    bst.identical_trees(bst, bst2);

    cout << "Task 1: Part E - Balanced binary tree" << endl;
    bst.isBalanced();

    cout << "Task 1: Part F - Height of tree" << endl;
    bst.height();

    return 0;
}
