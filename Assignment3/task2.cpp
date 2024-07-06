#include "BinarySearchTree.h"

int main()
{
    BinarySearchTree<int> obj;
    obj.insert(15);
    obj.insert(10);
    obj.insert(8);
    obj.insert(12);
    obj.insert(20);
    obj.insert(16);
    obj.insert(25);
    cout << "Root of existing tree is 15 and inorder traversal is: " << endl;
    obj.inorder();
    cout << "Enter a sequence of values that matches the pre order traversal of this BST" << endl;
    obj.preOrder();
    int size = obj.size_of_tree();
    int arr[size] = {0},
        value = 0;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter value for index " << i << ": ";
        cin >> value;
        arr[i] = value;
    }
    obj.compare_pre_order_array(arr);
    return 0;
}