#include "InventoryItem.h"
#include "MyArray.h"

class Inventory
{
    protected:
        MyArray<InventoryItem> *list;
        static int listSize;
    public:
        Inventory();
        Inventory(int);
        void addItem();
        void removeItem();
        void removeLastItem();
        void searchInventory();
        void displayItems();
        ~Inventory();
};

int Inventory::listSize = 0;

Inventory::Inventory(int size)
{
    list = new MyArray<InventoryItem> (size);
    cout << "Empty Inventory list created with size: " << size << endl;
}

Inventory::Inventory()
{
    list = new MyArray<InventoryItem> (150);
    InventoryItem obj1(
        this->listSize++,
        "Oranges",
        30,
        100
    );
    InventoryItem obj2(
        this->listSize++,
        "Apples",
        10,
        150
    );
    InventoryItem obj3(
        this->listSize++,
        "Mango",
        50,
        200
    );
    InventoryItem obj4(
        this->listSize++,
        "Kiwi",
        20,
        100
    );
    InventoryItem obj5(
        this->listSize++,
        "Pineaple",
        10,
        300
    );
    cout << "Current size of inventory: " << this->listSize << endl;
    this->list->display();
    this->list->append(obj1);
    this->list->append(obj2);
    this->list->append(obj3);
    this->list->append(obj4);
    this->list->append(obj5);
    this->list->display();
}

void Inventory::addItem()
{
    if (!this->list->isFull())
    {
        cout << "Enter the name of item, without spaces. Use - instead: ";
        string itemName = string();
        cin >> itemName;
        cout << "Enter the quantity of item: ";
        int quantity = int();
        cin >> quantity;
        cout << "Enter price of item: ";
        double price = double();
        cin >> price;
        InventoryItem obj(
            this->listSize++,
            itemName,
            quantity,
            price
        );
        this->list->append(obj);
        return ;
    }
    cout << "Inventory List is Full! No more items can be inserted" << endl;
}

void Inventory::removeLastItem()
{
    if (!this->list->isEmpty())
    {
        this->list->deleteLastItem();
        return ;
    }
    cout << "Invalid Opertion! List is empty" << endl;
}

void Inventory::displayItems()
{
    if (!this->list->isEmpty())
    {
        this->list->display();
        return ;
    }
    cout << "Invalid Operation! Inventory is empty" << endl;
}

void Inventory::removeItem()
{
    if (!this->list->isEmpty())
    {
        this->list->deleteItem();
        return ;
    }
    cout << "Invalid Operation! List is empty" << endl;
}

void Inventory::searchInventory()
{
    if (!this->list->isEmpty())
    {
        this->list->search();
        return ;
    }
    cout << "Invalid Operation! List is empty" << endl;
}

Inventory::~Inventory()
{
    delete this->list;
}