#include <iostream>
#include <string>

using namespace std;

struct MyString
{
    string data;
};

class InventoryItem
{
    protected:
        int itemID;
        MyString itemName;
        int quantity;
        double price;
    public:
        InventoryItem();
        InventoryItem(
            int,
            string,
            int,
            double
        );
        void setAttrs(
            int,
            string,
            int,
            double
        );
        void setItemId(int);
        void setItemName(string);
        void setQuantity(int);
        void setPrice(double);
        int getItemId();
        string getItemName();
        int getQuantity();
        int getPrice();
        void getAttrs();
        ~InventoryItem(){}
};

InventoryItem::InventoryItem() 
{
    itemID = 0;
    itemName.data = "";
    quantity = 0;
    price = 0.0;
}

InventoryItem::InventoryItem(int id, string name, int qty, double pr) 
{
    itemID = id;
    itemName.data = name;
    quantity = qty;
    price = pr;
}

void InventoryItem::setAttrs(int id, string name, int qty, double pr) 
{
    itemID = id;
    itemName.data = name;
    quantity = qty;
    price = pr;
}

void InventoryItem::setItemId(int id) 
{
    itemID = id;
}

void InventoryItem::setItemName(string name) 
{
    itemName.data = name;
}

void InventoryItem::setQuantity(int qty) 
{
    quantity = qty;
}

void InventoryItem::setPrice(double pr) 
{
    price = pr;
}

int InventoryItem::getItemId() 
{
    return itemID;
}

string InventoryItem::getItemName() 
{
    return itemName.data;
}

int InventoryItem::getQuantity() 
{
    return quantity;
}

int InventoryItem::getPrice() 
{
    return static_cast<int>(price);
}

void InventoryItem::getAttrs() 
{
    cout << "!*----**----**----**----**----**----**----**----**----**----**----**----**----**----**----**----*!" << endl;
    cout << "Item ID: " << itemID << endl;
    cout << "Item Name: " << itemName.data << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Price: $" << price << endl;
    cout << "!*----**----**----**----**----**----**----**----**----**----**----**----**----**----**----**----*!" << endl;
}
