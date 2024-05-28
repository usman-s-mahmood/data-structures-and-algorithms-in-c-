#include <iostream>
#include <string>
#include <cmath>

using namespace std;

template <class T>
struct Node
{
    T data;
    struct Node<T> *next;
};

template <class T>
class LinkedList
{
    protected:
        struct Node<T> *head;
        struct Node<T> *tail;
    public:
        LinkedList();
        virtual void insertAtHead(T) = 0;
        virtual void insertAtTail(T) = 0;
        virtual T deleteFromHead() = 0;
        virtual T deleteFromTail() = 0;
        ~LinkedList(){}
};

template <class T>
LinkedList<T>::LinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
}


template <class T>
class CircularLinkedList: public LinkedList<T>
{
    public:
        CircularLinkedList();
        void insertAtHead(T);
        void insertAtTail(T);
        T deleteFromHead();
        T deleteFromTail();
        void display();
        bool isEmpty();
        ~CircularLinkedList()
        {
            while(!isEmpty())
                deleteFromTail();
        }
};

template <class T>
CircularLinkedList<T>::CircularLinkedList():
    LinkedList<T>::LinkedList()
{}

template <class T>
bool CircularLinkedList<T>::isEmpty()
{
    return (this->tail == nullptr);
}

template <class T>
void CircularLinkedList<T>::insertAtHead(T value)
{
    struct Node<T> *node = new struct Node<T>;
    node->data = value;
    node->next = nullptr;
    if (isEmpty())
    {
        this->tail = node;
        node->next = this->tail;
    }
    else
    {
        node->next = this->tail->next;
        this->tail->next = node;
    }    
}

template <class T>
void CircularLinkedList<T>::insertAtTail(T value)
{
    struct Node<T> *node = new struct Node<T>;
    node->data = value;
    node->next = nullptr;
    if (isEmpty())
    {
        this->tail = node;
        node->next = this->tail;
    }
    else
    {
        node->next = this->tail->next;
        this->tail->next = node;
        this->tail = node;
    }    
}

template <class T>
T CircularLinkedList<T>::deleteFromHead()
{
    if (isEmpty())
    {
        cout << "Invalid Operation! Linked List is empty" << endl;
        return -1;
    }
    T value = this->tail->next->data;
    struct Node<T> *headPtr = this->tail->next;
    this->tail->next = headPtr->next;
    delete headPtr;
    return value;
}

template <class T>
T CircularLinkedList<T>::deleteFromTail()
{
    if (isEmpty())
    {
        cout << "Empty Linked List can't be used for this!" << endl;
        return -1;
    }
    T value = this->tail->data;
    struct Node<T> *ptr1 = this->tail;
    struct Node<T> *ptr2 = this->tail->next;
    while (ptr2 != this->tail)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    ptr1->next = this->tail->next;
    this->tail = ptr1;
    delete ptr2;
    return value;
}

template <class T>
void CircularLinkedList<T>::display()
{
    if (isEmpty())
    {
        cout << "Linked List is Empty!" << endl;
        return ;
    }
    struct Node<T> *tailPtr = this->tail->next;
    while(true)
    {
        cout << tailPtr->data << ' ';
        tailPtr = tailPtr->next;
        if (tailPtr == this->tail->next)
            break;
    }
    cout << endl;
}


int main()
{
    CircularLinkedList<int> obj;
    obj.insertAtHead(1);
    obj.insertAtTail(12);
    obj.insertAtHead(2);
    obj.display();
    return 0;
}