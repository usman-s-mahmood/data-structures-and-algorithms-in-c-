#include "MyLinkedList.h"

int main()
{
    cout << "Notepad with Linked List and Stack" << endl;
    MyLinkedList<string> obj;
    int ch = -1;
    string line;
    int del = 0;
    string dLine;
    while (ch != 0)
    {
        ch = -1;
        cout << "Enter 0 to exit the system" << endl;
        cout << "1. To enter a line" << endl
            << "2. To delete a line" << endl
            << "3. To to display all the lines" << endl
            << "4. To empty the file" << endl
            << "5. To check the file (Empty or not)" << endl
            << "Enter your choice: ";
        cin >> ch;
        if (ch == 1)
        {
            cout << "Enter some text (without spaces, use - instead): ";
            cin >> line;
            obj.insertAtTail(line);
            // cout << "Press any key to continue!" << endl;
            // getch();
        }
        else if (ch == 2)
        {
            cin >> del;
            dLine = obj.peekPos(del);
            obj.deleteValue(dLine);
            // cout << "Press any key to continue!" << endl;
            // getch();
        }
        else if (ch == 3)
        {
            obj.display();
            // cout << "Press any key to continue!" << endl;
            // getch();
        }
        else if (ch == 4)
        {
            while (!obj.isEmpty())
                obj.deleteAtTail();
            // cout << "Press any key to continue!" << endl;
            // getch();
        }
        else if (ch == 5)
        {
            if (obj.isEmpty())
                cout << "File is empty" << endl;
            else
                cout << "File is not empty" << endl;
            // cout << "Press any key to continue!" << endl;
            // getch();
        }
        else
        {
            cout << "Invalid Operation!" << endl;
            break;
        }
    }
    return 0;
}
