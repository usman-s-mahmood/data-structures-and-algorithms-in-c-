#include "MyDoubleLinkedList.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    MyDoubleLinkedList<int> obj;

    while (true) {
        cout << "\nMenu:\n"
             << "1. Insert data at end\n"
             << "2. Delete data from end\n"
             << "3. Insert data at head\n"
             << "4. Delete data from head\n"
             << "5. Delete duplicate nodes\n"
             << "6. Swap Head Node with Tail Node\n"
             << "7. Exit\n"
             << "Enter your choice: ";
        
        int choice;
        cin >> choice;

        try {
            switch (choice) {
                case 1: {
                    int data;
                    cout << "Enter data to insert at end: ";
                    cin >> data;
                    obj.insertAtTail(data);
                    break;
                }
                case 2: {
                    if (!obj.isEmpty())
                        cout << "Deleted data from end: " << obj.deleteFromTail() << endl;
                    else
                        cout << "List is empty!" << endl;
                    break;
                }
                case 3: {
                    int data;
                    cout << "Enter data to insert at head: ";
                    cin >> data;
                    obj.insertAtHead(data);
                    break;
                }
                case 4: {
                    if (!obj.isEmpty())
                        cout << "Deleted data from head: " << obj.deleteFromHead() << endl;
                    else
                        cout << "List is empty!" << endl;
                    break;
                }
                case 5: {
                    obj.deleteDuplicateNodes();
                    cout << "Duplicate nodes deleted." << endl;
                    break;
                }
                case 6: {
                    obj.swapNodes();
                    break;
                }
                case 7: {
                    cout << "Exiting..." << endl;
                    return 0;
                }
                default: {
                    cout << "Invalid choice! Please try again." << endl;
                    break;
                }
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}
