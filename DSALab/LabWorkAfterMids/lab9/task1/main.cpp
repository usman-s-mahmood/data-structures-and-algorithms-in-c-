#include "CircularLinkedList.h"
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
    CircularLinkedList<int> obj;
    int choice, data, n;

    do {
        cout << "\nMenu:\n"
             << "1. Insert data at end\n"
             << "2. Delete data from end\n"
             << "3. Insert data at head\n"
             << "4. Delete data from head\n"
             << "5. Convert singly Linked List into Circular Linked List\n"
             << "6. Print nth node from last\n"
             << "7. Sort a linked list of 0s, 1s and 2s\n"
             << "8. Display list\n"
             << "9. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert at end: ";
                cin >> data;
                obj.insertAtTail(data);
                cout << "Press any key to continue!" << endl;
                getch();
                break;
            case 2:
                if (!obj.isEmpty())
                    cout << "Deleted data from end: " << obj.deleteFromTail() << endl;
                cout << "Press any key to continue!" << endl;
                getch();
                break;
            case 3:
                cout << "Enter data to insert at head: ";
                cin >> data;
                obj.insertAtHead(data);
                cout << "Press any key to continue!" << endl;
                getch();
                break;
            case 4:
                if (!obj.isEmpty())
                    cout << "Deleted data from head: " << obj.deleteFromHead() << endl;
                cout << "Press any key to continue!" << endl;
                getch();
                break;
            case 5:
                obj.convertList();
                cout << "Press any key to continue!" << endl;
                getch();
                break;
            case 6:
                cout << "Enter the position from last: ";
                cin >> n;
                obj.printNthFromLast(n);
                cout << "Press any key to continue!" << endl;
                getch();
                break;
            case 7:
                obj.sortList();
                cout << "Press any key to continue!" << endl;
                getch();
                break;
            case 8:
                obj.display();
                cout << "Press any key to continue!" << endl;
                getch();
                break;
            case 9:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    } while (choice != 9);

    return 0;
}
