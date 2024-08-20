#include "Inventory.h"

int main()
{
    // InventoryItem obj1(
    //     1, "Oranges",
    //     20, 100
    // );
    // obj1.getAttrs();
    // Inventory obj;
    // obj.displayItems();
    cout << "Welcome to inventory management system! An application of array Data Structure" << endl;
    cout << "Press 1 for using default inventory with size 250 and 5 default items\nPress 2 for using a custom sized empty inventory list: ";
    int choice = int();
    cin >> choice;
    Inventory *obj;
    if (choice == 1)
        obj = new Inventory();
    else if (choice == 2)
    {
        cout << "Enter a size for your inventory list: ";
        int listSize = int();
        cin >> listSize;
        if (listSize > 0)
            obj = new Inventory(listSize);
        else
        {
            cout << "Invalid Operation! Negative indexes not accepted, try again" << endl;
            return 0;
        }
    }
    int menuChoice = int();
    while (true)
    {
        cout << "Press 1 to add item" << endl
            << "Press 2 to remove last item" << endl
            << "Press 3 to remove any item" << endl
            << "Press 4 to search item" << endl
            << "Press 5 to display all items" << endl
            << "Press 6 to exit" << endl
        << "Enter your choice: ";
        cin >> menuChoice;
        if (menuChoice == 1)
        {
            obj->addItem();
            system("pause");
        }
        else if (menuChoice == 2)
        {
            obj->removeItem();
            system("pause");
        }
        else if (menuChoice == 3)
        {
            obj->removeItem();
            system("pause");
        }
        else if (menuChoice == 4)
        {
            obj->removeLastItem();
            system("pause");
        }
        else if (menuChoice == 5)
        {
            obj->displayItems();
            system("pause");
        }
        else if (menuChoice == 6)
            break;
        else
            break;
    }
    return 0;
}