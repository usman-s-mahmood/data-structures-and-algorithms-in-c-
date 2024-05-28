#include <conio.h>
#include "MyLinkedList.h"

int main()
{
    cout << "Welcome to Linked List System" << endl;
    MyLinkedList<int> obj;
    while (true)
    {
        cout << "Select your desired option" << endl
            << "1. Insert a value at tail" << endl
            << "2. Delete a value from tail" << endl
            << "3. Insert a value at head" << endl
            << "4. Delete a value from head" << endl
            << "5. Count All Nodes in linked list" << endl
            << "6. Add First 3 Nodes in linked list" << endl
            << "7. Update mid value in linked list" << endl
            << "8. Exit the program" << endl
        << "Your choice: " ;
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            cout << "Enter a value: ";
            int value;
            cin >> value;
            obj.insertAtTail(value);
            cout << "Press any key to continue" << endl;
            getch();
        }
        else if (ch == 2)
        {
            int value = obj.deleteAtTail();
            cout << "Deleted Value is: " << value << endl;
            cout << "Press any key to continue" << endl;
            getch();
        }
        else if (ch == 3)
        {
            cout << "Enter a value: ";
            int value;
            cin >> value;
            obj.insertAtHead(value);
            cout << "Press any key to continue" << endl;
            getch();
        }
        else if (ch == 4)
        {
            int value = obj.deleteAtHead();
            cout << "Deleted Value is: " << value << endl;
            cout << "Press any key to continue" << endl;
            getch();
        }
        else if (ch == 5)
        {
            obj.display();
            int size = obj.countAllNodes();
            cout << "Nodes in linked list are: " << size << endl;
            cout << "Press any key to continue" << endl;
            getch();
        }
        else if (ch == 6)
        {
            obj.display();
            int sum = obj.addnodes();
            cout << "Sum is: "<< sum << endl;
            cout << "Press any key to continue" << endl;
            getch();
        }
        else if (ch == 7)
        {
            int value = 0;
            cout << "Enter a value: ";
            cin >> value;
            obj.display();
            obj.updateMiddleNode(value);
            obj.display();
            cout << "Press any key to continue" << endl;
            getch();
        }
        else if (ch == 8)
        {
            cout << "program terminated!" << endl;
            break;
        }
        else
        {
            cout << "Invalid Option Selected!" << endl;
            break;
        }
    }
    return 0;
}