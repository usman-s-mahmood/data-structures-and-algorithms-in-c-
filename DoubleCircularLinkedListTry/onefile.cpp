#include <iostream>
#include <string>
#include <cmath>

using namespace std;

template <class T>
struct Node
{
    struct Node<T> *prev;
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
        // virtual T deleteFromHead() = 0;
        // virtual T deleteFromTail() = 0;
        ~LinkedList(){}

};

template <class T>
LinkedList<T>::LinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
}


template <class T>
class DoubleCircularLinkedList: public LinkedList<T>
{
    public:
        DoubleCircularLinkedList();
        void insertAtHead(T);
        void insertAtTail(T);
        // T deleteFromHead();
        // T deleteFromTail();
        bool isEmpty();
        void display();
        ~DoubleCircularLinkedList()
        {
            // while (!isEmpty())
                // deleteFromHead();
        }
};

template <class T>
DoubleCircularLinkedList<T>::DoubleCircularLinkedList():
    LinkedList<T>::LinkedList()
{}

template <class T>
bool DoubleCircularLinkedList<T>::isEmpty()
{
    return (this->head == nullptr);
}

template <class T>
void DoubleCircularLinkedList<T>::insertAtHead(T value)
{
    struct Node<T> *node = new struct Node<T>;
    node->prev = nullptr;
    node->data = value;
    node->next = nullptr;
    if (isEmpty())
    {
        this->head = node;
        node->prev = this->head;
        node->next = this->head;
        return ;
    }
    node->next = this->head;
    node->prev = this->head->prev;
    this->head->prev->next = node;
    this->head = node;
}

template <class T>
void DoubleCircularLinkedList<T>::insertAtTail(T value)
{
    struct Node<T> *node = new struct Node<T>;
    node->prev = nullptr;
    node->data = value;
    node->next = nullptr;
    if (isEmpty())
    {
        this->head = node;
        node->next = this->head;
        node->prev = this->head;
        return ;
    }
    struct Node<T> *tail = this->head->prev;
    tail->next = node;
    node->next = this->head;
    this->head->prev = node;
}

template <class T>
void DoubleCircularLinkedList<T>::display()
{
    if (isEmpty())
    {
        cout << "Linked List is Empty!" << endl;
        return ;
    }
    struct Node<T> *headPtr = this->head;
    struct Node<T> *tailPtr = this->head->prev;
    do {
        cout << headPtr->data << ' ';
        headPtr = headPtr->next;
    } while(headPtr != this->head);
    cout << endl;
    do {
        cout << tailPtr->data << ' ';
        tailPtr = tailPtr->prev;
    } while (tailPtr != this->head);
    cout << endl;
}



int main()
{
    DoubleCircularLinkedList<int> obj;
    obj.insertAtHead(1);
    obj.insertAtTail(10);
    obj.insertAtHead(100);
    obj.display();
    return 0;
}