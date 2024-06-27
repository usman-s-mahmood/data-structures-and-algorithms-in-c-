#include "RBTree.h"

int main()
{

    
    RBTree<int> obj2;
    obj2.insertNode(1);
    obj2.insertNode(2);
    obj2.insertNode(3);
    obj2.insertNode(4);
    obj2.insertNode(5);
    obj2.insertNode(6);
    obj2.inOrder();
    obj2.deleteNode(1);
    obj2.inOrder();
    system("pause");
    RBTree<int> obj;
    cout << "Welcome To Red Black Tree Demonstration System" << endl;
    int ch = -1;
    while (ch != 12)
    {
        cout << "Select your desired option" << endl
            << "Press 1 to insert values in the tree(one by one)\nPress 2 for searching a value from the tree\nPress 3 for pre-order traversalNLR\nPress 4 for in-order traversalLNR\nPress 5 for post-order traversalLRN\nPress 6 for pre-order traversal2 NRL\nPress 7 for in-order traversal2 RNL\nPress 8 for post-order traversal2 RLN\nPress 9 for displaying parent of a node present in Tree\nPress 10 to read integer values from the file input.txt to create a red-black tree\nPress 11 to destroy the complete tree \nPress 12 to EXIT" << endl
        << "Enter your choice: ";
        cin >> ch;
        if (ch == 1)
        {
            cout << "Enter a value to insert: " ;
            int value;
            cin >> value;
            obj.insertNode(value);
            system("pause");
        }
        else if (ch == 2)
        {
            cout << "Enter a value to search: ";
            int value;
            cin >> value;
            obj.search(value);
            system("pause");
        }
        else if (ch == 3)
        {
            obj.preOrder();
            system("pause");
        }
        else if (ch == 4)
        {
            obj.inOrder();
            system("pause");
        }
        else if (ch == 5)
        {
            obj.postOrder();
            system("pause");
        }
        else if (ch == 6)
        {
            obj.preorder2();
            system("pause");
        }
        else if (ch == 7)
        {
            obj.inorder2();
            system("pause");
        }
        else if (ch == 8)
        {
            obj.postorder2();
            system("pause");
        }
        else if (ch == 9)
        {
            obj.inOrder();
            cout << "Enter a value in this range to display the it's parent: ";
            int value;
            cin >> value;
            obj.parentNode(value);
            system("pause");
        }
        else if (ch == 10)
        {
            // to be designed
            system("pause");
        }
        else if (ch == 11)
        {
            obj.destroyRBTree();
            system("pause");
        }
        else if (ch == 12)
        {
            cout << "Program terminated successfully!" << endl;
            return 0;
        }
        else
        {
            cout << "Invalid Operation! Program terminated" << endl;
            return -1;
        }
    }
}