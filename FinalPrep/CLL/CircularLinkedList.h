#include "LinkedList.h"

template <class T>
class CircularLinkedList: public LinkedList<T>
{
    protected:

    public:
        CircularLinkedList();
        void insertAtHead(T);
        void insertAtTail(T);
        T deleteFromHead();
        T deleteFromTail();
        void display();
        bool isEmpty();
        bool search(T);
        ~CircularLinkedList();
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
        this->tail->next = this->tail;
        return ;
    }
    struct Node<T> *prev_head = this->tail->next;
    node->next = prev_head;
    this->tail->next = node;
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
        this->tail->next = this->tail;
        return ;
    }
    node->next = this->tail->next;
    this->tail->next = node;
    this->tail = node;
}

template <class T>
T CircularLinkedList<T>::deleteFromHead()
{
    if (!isEmpty())
    {
        if (this->tail->next == this->tail)
        {
            T value = this->tail->data;
            delete this->tail;
            this->tail = nullptr;
            return value;
        }
        struct Node<T> *headPtr = this->tail->next;
        T value = headPtr->data;
        this->tail->next = this->tail->next->next;
        delete headPtr;
        headPtr = nullptr;
        return value;
    }
    cout << "Invalid Operation! Linked List is empty" << endl;
    return T();
}

template <class T>
T CircularLinkedList<T>::deleteFromTail()
{
    if (!isEmpty())
    {
        if (this->tail->next == this->tail)
        {
            T value = this->tail->data;
            delete this->tail;
            this->tail = nullptr;
            return value;
        }
        T value = this->tail->data;
        struct Node<T> *headPtr = this->tail->next;
        while (headPtr->next != this->tail)
            headPtr = headPtr->next;
        struct Node<T> *delPtr = this->tail;
        headPtr->next = this->tail->next;
        this->tail = headPtr;
        delete delPtr;
        delPtr = nullptr;
        return value;
    }
    cout << "Invalid Operation! Linked List is empty" << endl;
    return T();
}

template <class T>
bool CircularLinkedList<T>::search(T value)
{
    if (!isEmpty())
    {
        struct Node<T> *headPtr = this->tail->next;
        do {
            if (headPtr->data == value)
            {
                cout << "Value found in the Linked List" << endl;
                return true;
            }
            headPtr = headPtr->next;
        } while (headPtr != this->tail->next);
        cout << "Value is not present in the Linked List" << endl;
        return false;
    }
    cout << "Invalid Operation! Linked List is empty" << endl;
    return false;
}

template <class T>
void CircularLinkedList<T>::display()
{
    if (!isEmpty())
    {
        struct Node<T> *headPtr = this->tail->next;
        do {
            cout << headPtr->data << ' ';
            headPtr = headPtr->next;
        } while (headPtr != this->tail->next);
        cout << endl;
        return ;
    }
    cout << "Invalid Operation! Linked List is empty" << endl;
}

template <class T>
CircularLinkedList<T>::~CircularLinkedList()
{
    while (!isEmpty())
        deleteFromTail();
    LinkedList<T>::~LinkedList();
}