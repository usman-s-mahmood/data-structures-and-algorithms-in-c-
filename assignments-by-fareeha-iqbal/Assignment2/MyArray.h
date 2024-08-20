#include "ArrayADT.h"

template <class T>
class MyArray: public ArrayADT<T>
{
    protected:
        
    public:
        MyArray();
        MyArray(int);
        void append(T);
        void display();
        T search();
        void deleteItem();
        void deleteLastItem();
        bool isEmpty();
        bool isFull();
        ~MyArray();
};

template <class T>
MyArray<T>::MyArray():
    ArrayADT<T>::ArrayADT()
{}

template <class T>
MyArray<T>::MyArray(int size):
    ArrayADT<T>::ArrayADT(size)
{}

template <class T>
bool MyArray<T>::isEmpty()
{
    return (this->size == 0);
}

template <class T>
bool MyArray<T>::isFull()
{
    return (this->size == this->capacity);
}

template <class T>
void MyArray<T>::append(T data)
{
    if (!isFull())
    {
        this->array[this->size] = data;
        this->size += 1;
        return ;
    }
    cout << "Invalid Operation! ADT is full" << endl;
}

template <class T>
T MyArray<T>::search()
{
    if (!isEmpty())
    {
        cout << "Enter the item number: ";
        int num = int();
        cin >> num;
        for (int i = 0; i < this->size; i++)
            if (this->array[i].getItemId() == num)
            {
                cout << "Item found at index: " << i << endl;
                return this->array[i];
            }
        cout << "Invalid Item Number! No object with this ID exists" << endl;
        return T();
    }
    cout << "Invalid Operation! ADT is empty" << endl;
    return T();
}

template <class T>
void MyArray<T>::display()
{
    if (!isEmpty())
    {
        for (int i = 0; i < this->size; i++)
            this->array[i].getAttrs();
        cout << endl;
        return ;
    }
    cout << "Invalid Operation! ADT is empty" << endl;
}

template <class T>
void MyArray<T>::deleteItem()
{
    if (!isEmpty())
    {
        cout << "Enter the item ID that you want to delete: ";
        int itemNumber = int();
        cin >> itemNumber;
        for (int i = 0; i < this->size; i++)
            if (this->array[i].getItemId() == itemNumber)
            {
                for (int j = i; j < this->size; j++)
                    this->array[j] = this->array[j+1];
                cout << "Item has been deleted! " << endl;
                this->size--;
                return ;
            }
        cout << "Invalid Operation! Item does not exist" << endl;
        return ;
    }
    cout << "Invalid Operation! ADT is empty" << endl;
}

template <class T>
void MyArray<T>::deleteLastItem()
{
    if (!isEmpty())
    {
        this->size--;
        return ;
    }
    cout << "Invalid Operation! List is empty" << endl;

}

template <class T>
MyArray<T>::~MyArray()
{
    ArrayADT<T>::~ArrayADT();
}