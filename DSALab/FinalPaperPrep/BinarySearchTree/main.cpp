<<<<<<< HEAD
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
=======
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
    cout << "After deleting node with value 10: " << obj.deleteNode(10) << endl; 
    obj.inorder();
    obj.preorder();
    obj.postorder();
    return 0;
>>>>>>> 6b2f82d8e44f7796eed3207ffa1665bcdc1c3fed
}