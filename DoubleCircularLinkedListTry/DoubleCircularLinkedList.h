#include "LinkedList.h"

template <class T>
class DoubleCircularLinkedList: public LinkedList<T>
{
    public:
        DoubleCircularLinkedList();
        void insertAtHead(T);
        void insertAtTail(T);
        T deleteFromHead();
        T deleteFromTail();
        bool isEmpty();
        void display();
        void insertSorted(T);
        ~DoubleCircularLinkedList()
        {
            while (!isEmpty())
                deleteFromHead();
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
    this->head->prev = node;
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
    node->prev = tail;
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
    } while (tailPtr != this->head->prev);
    cout << endl;
}

template <class T>
T DoubleCircularLinkedList<T>::deleteFromHead()
{
    if (isEmpty())
    {
        cout << "Invalid Operation on empty linked List!" << endl;
        return -1;
    } 
    else if (this->head->next == this->head)
    {
        T value = this->head->data;
        delete this->head;
        this->head = nullptr;
        return value;
    } 
    T value = this->head->data;
    struct Node<T> *headPtr = this->head;
    struct Node<T> *tailPtr = this->head->prev;
    struct Node<T> *newHead = this->head->next;
    tailPtr->next = newHead;
    newHead->prev = tailPtr;
    delete headPtr;
    headPtr = nullptr;
    this->head = newHead;
    return value;
}

template <class T>
T DoubleCircularLinkedList<T>::deleteFromTail()
{
    if (isEmpty())
    {
        cout << "Invalid Operation on empty linked list!" << endl;
        return -1;
    } 
    else if (this->head->next == this->head)
    {
        T value = this->head->data;
        delete this->head;
        this->head = nullptr;
        return value;
    } 
    struct Node<T> *tailPtr = this->head->prev;
    T value = tailPtr->data;
    struct Node<T> *newTail = tailPtr->prev;
    newTail->next = this->head;
    this->head->prev = newTail;
    delete tailPtr;
    tailPtr = nullptr;
    return value;
}

template <class T>
void DoubleCircularLinkedList<T>::insertSorted(T value)
{
    if (isEmpty())
        insertAtHead(value);
    else if (this->head->data >= value)
        insertAtHead(value);
    else if (this->head->prev->data <= value)
        insertAtTail(value);
    else
    {
        struct Node<T> *ptr1 = this->head;
        struct Node<T> *ptr2 = ptr1->next;
        struct Node<T> *node = new struct Node<T>;
        node->prev = nullptr;
        node->data = value;
        node->next = nullptr;
        do {
            if (value >= ptr1->data && value <= ptr2->data)
            {
                node->next = ptr2;
                ptr2->prev = node;
                ptr1->next = node;
                node->prev = ptr1;
                break ;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        } while (ptr1 != this->head->next);
    }
}