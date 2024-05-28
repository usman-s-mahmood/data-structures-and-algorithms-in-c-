#include "LinkedList.h"

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
        int addnodes(); 
        void updateMiddleNode(T data);
        ~MyLinkedList()
        {
            while (!isEmpty())
                this->deleteAtHead();
        }
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

template <class T>
int MyLinkedList<T>::addnodes()
{
    if (isEmpty())
    {
        cout << "Empty linked list can't be used for such operations! " << endl;
        return 0;
    }
    struct Node<T> *temp = this->head;
    cout << "First 3 nodes of linked list are: " << endl;
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        cout << temp->data << ' ';
        sum += temp->data;
        temp = temp->next;
    }
    cout << endl;
    return sum;
}

template <class T>
void MyLinkedList<T>::updateMiddleNode(T data)
{
    if (isEmpty())
    {
        cout << "Empty linked list has no mid value!" << endl;
        return ;
    }
    int size = countAllNodes(),
        mid = size/2;
    struct Node<T> *temp = this->head;
    for (int i = 0; i < mid; i++)
        temp = temp->next;
    cout << "Previous Value of mid: " << temp->data << endl;
    temp->data = data;
    cout << "New Value of mid: " << temp->data << endl;
}