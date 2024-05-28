#include "DoubleCircularLinkedList.h"

int main()
{
    DoubleCircularLinkedList<char> *obj = new DoubleCircularLinkedList<char>;/*
    obj.insertAtTail('r');
    obj.insertAtTail('a');
    obj.insertAtTail('c');
    obj.insertAtTail('e');
    obj.insertAtTail('c');
    obj.insertAtTail('a');
    obj.insertAtTail('r');
    if (obj.checkPalindrome())
        cout << "Content inside the linked list is a palindrome word!" << endl;
    else
        cout << "Content inside the linked list is NOT a palindrome word!" << endl;
    obj.display();
    obj.rotateByNnodes(3);
    obj.display(); */
    while (true) {
        cout << "\nMenu:\n"
             << "1. Insert data at end\n"
             << "2. Delete data from end\n"
             << "3. Insert data at head\n"
             << "4. Delete data from head\n"
             << "5. Check If the linked list is palindrome or not\n"
             << "6. Rotate doubly linked list by N nodes\n"
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
                    obj->insertAtTail(data);
                    break;
                }
                case 2: {
                    if (!obj->isEmpty())
                        cout << "Deleted data from end: " << obj->deleteFromTail() << endl;
                    else
                        cout << "List is empty!" << endl;
                    break;
                }
                case 3: {
                    int data;
                    cout << "Enter data to insert at head: ";
                    cin >> data;
                    obj->insertAtHead(data);
                    break;
                }
                case 4: {
                    if (!obj->isEmpty())
                        cout << "Deleted data from head: " << obj->deleteFromHead() << endl;
                    else
                        cout << "List is empty!" << endl;
                    break;
                }
                case 5: {
                    if (obj->checkPalindrome())
                        cout << "The linked list is a palindrome." << endl;
                    else
                        cout << "The linked list is not a palindrome." << endl;
                    break;
                }
                case 6: {
                    int pos;
                    cout << "Enter the number of positions to rotate by: ";
                    cin >> pos;
                    obj->rotateByNnodes(pos);
                    break;
                }
                case 7: {
                    delete obj;
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
    delete obj;
    obj = nullptr;
    return 0;
}