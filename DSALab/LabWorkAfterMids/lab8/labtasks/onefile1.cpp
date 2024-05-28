#include <conio.h>
#include <iostream>
#include <string>
using namespace std;

template <class T>
struct Node
{
    T data;
    struct Node *next;
};

template <class T>
class LinkedList
{
    protected:
        struct Node<T> *head;
        struct Node<T> *tail;
    public:
        LinkedList();
        virtual void insertAtTail(T value) = 0;
        virtual void insertAtHead(T value) = 0;
        virtual T deleteAtHead() = 0;
        virtual T deleteAtTail() = 0;
        virtual int countAllNodes() = 0;
        ~LinkedList()
        {
            delete head;
            delete tail;
        }
};

template <class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}

template <class T>
class MyLinkedList: public LinkedList<T>
{
    public:
        MyLinkedList();
        void insertAtTail(T value);
        void insertAtHead(T value);
        T deleteAtHead();
        T deleteAtTail();
        void display();
        bool isEmpty();
        void search(T value);
        int countAllNodes();
        ~MyLinkedList(){}
};

template <class T>
MyLinkedList<T>::MyLinkedList():
    LinkedList<T>::LinkedList()
{}

template <class T>
bool MyLinkedList<T>::isEmpty()
{
    return (this->head == nullptr && this->tail == nullptr);
}

template <class T>
void MyLinkedList<T>::insertAtTail(T value)
{
    struct Node<T> *ptr = new struct Node<T>;
    ptr->data = value;
    ptr->next = nullptr;
    if (isEmpty())
        this->head = this->tail = ptr;
    else
    {
        this->tail->next = ptr;
        this->tail = ptr;
    }
}

template <class T>
void MyLinkedList<T>::insertAtHead(T value)
{
    struct Node<T> *ptr = new struct Node<T>;
    ptr->data = value;
    ptr->next = nullptr;
    if (isEmpty())
        this->head = this->tail = ptr;
    else
    {
        ptr->next = this->head;
        this->head = ptr;
    }
}

template <class T>
void MyLinkedList<T>::display()
{
    if(isEmpty())
    {
        cout<<"Linked list is empty!"<<endl;
        return ;
    }
    struct Node<T> *temp = this->head;
    while (temp != nullptr)
    {
        cout<<temp->data<<' ';
        temp = temp->next;
    }
    cout<<endl;
}

template <class T>
T MyLinkedList<T>::deleteAtHead()
{
    if (isEmpty())
    {
        cout<<"Empty linked list has not values for deletion!"<<endl;
        return -1;
    }
    T value = this->head->data;
    struct Node<T> *ptr = this->head;
    this->head = ptr->next;
    delete ptr;
    return value;
}

template <class T>
T MyLinkedList<T>::deleteAtTail()
{
    if (isEmpty())
    {
        cout<<"Empty linked list has not values for deletion!"<<endl;
        return -1;
    }
    struct Node<T> *ptr = this->head;
    while (ptr->next != this->tail)
        ptr = ptr->next;
    T value = this->tail->data;
    struct Node<T> *temp = ptr->next;
    delete temp;
    ptr->next = nullptr;
    this->tail = ptr;
    return value;
    
}

template <class T>
void MyLinkedList<T>::search(T value)
{
    if (isEmpty())
    {
        cout<<"Empty linked list has no values for searching"<<endl;
        return;
    }
    else if(this->head->data == value)
        cout<<"Value found at head: "<<this->head->data<<endl;
    else if(this->tail->data == value)
        cout<<"Value found at tail: "<<this->tail->data<<endl;
    else
    {
        struct Node<T> *ptr = this->head;
        while(ptr != nullptr)
        {
            if(ptr->data == value)
            {
                cout<<"Value found in the linked list: "<<ptr->data<<endl;
                return ;
            }
            ptr = ptr->next;
        }
        cout<<"Value is not in the linked list!"<<endl;
    }
}

template <class T>
int MyLinkedList<T>::countAllNodes()
{
    if (isEmpty())
        return 0;
    int count = 0;
    struct Node<T> *temp = this->head;
    while (temp != nullptr)
    {
        count += 1;
        temp = temp->next;
    }
    return count;
}

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
            << "6. Exit the program" << endl
        << "Your choice: " ;
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            cout << "Enter a value: ";
            int value;
            cin >> value;
            obj.insertAtTail(value);
        }
        else if (ch == 2)
        {
            int value = obj.deleteAtTail();
            cout << "Deleted Value is: " << value << endl;
        }
        else if (ch == 3)
        {
            cout << "Enter a value: ";
            int value;
            cin >> value;
            obj.insertAtHead(value);
        }
        else if (ch == 4)
        {
            int value = obj.deleteAtHead();
            cout << "Deleted Value is: " << value << endl;
        }
        else if (ch == 5)
        {
            obj.display();
            int size = obj.countAllNodes();
            cout << "Nodes in linked list are: " << size << endl;
        }
        else if (ch == 6)
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