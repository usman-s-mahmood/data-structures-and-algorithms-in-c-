#include "BinarySearchTree.h"
#include <stdio.h>

int main()
{
    BinarySearchTree<int> obj;
    char str[10];
    obj.insert(15);
    obj.insert(18);
    obj.insert(19);
    obj.insert(23);
    obj.insert(5);
    obj.insert(1);
    obj.insert(7);
    obj.insert(17);
    obj.insert(817);
    obj.inorder();
    // string st;
    // cout << "Enter a string: ";
    // getline(cin, st);
    // cout << st << endl;
    return 0;
}