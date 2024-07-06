#include "RBTree.h"

int main()
{
    RBTree<int> obj;
    cout << "Welcome To Red Black Tree Demonstration System" << endl;
    int ch = -1,
        file_value = 0,
        size = 0;
    fstream fileObj, fileObj2;
    fileObj.open("input.txt", ios::in);
    while (!fileObj.eof())
    {
        fileObj >> file_value;
        size++;
    }
    fileObj.close();
    fileObj2.open("input.txt", ios::in);
    int arr[size] = {0};
    for (int i = 0; i < size; i++)
    {
        fileObj2 >> file_value;
        arr[i] = file_value;
    }
    fileObj2.close();
    while (ch != 12)
    {
        cout << "Select your desired option" << endl
            << "Press 1 to insert values in the tree(one by one)\nPress 2 for searching a value from the tree\nPress 3 for pre-order traversalNLR\nPress 4 for in-order traversalLNR\nPress 5 for post-order traversalLRN\nPress 6 for pre-order traversal2 NRL\nPress 7 for in-order traversal2 RNL\nPress 8 for post-order traversal2 RLN\nPress 9 for displaying parent of a node present in Tree\nPress 10 to read integer values from the file input.txt to create a red-black tree\nPress 11 to destroy the complete tree \nPress 12 to EXIT\nPress 13 to delete a node" << endl
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
            fileObj.open("input.txt", ios::in);
            cout << "Inorder traversal of Red Black Tree before inserting values from input.txt" << endl;
            obj.inOrder();
            cout << "Values read from input.txt: " << endl;
            for (int i = 0; i < size; i++)
            {
                cout << arr[i] << ' ';
                obj.insertNode(arr[i]);
            }
            cout << endl;
            cout << "Inorder traversal of Red Black Tree after inserting values from input.txt" << endl;
            obj.inOrder();
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
            obj.destroyRBTree();
            return 0;
            break;
        }
        else if (ch == 13)
        {
            cout << "Enter a value within this range to delete it from the Red black tree" << endl;
            obj.inOrder();
            int value;
            cin >> value;
            if (obj.deleteNode(value))
            {
                cout << "Red black tree after deleting " << value << endl;
                obj.inOrder();
            }
        }
        else
        {
            cout << "Invalid Operation! Program terminated" << endl;
            return -1;
        }
    }
    return 0;
}