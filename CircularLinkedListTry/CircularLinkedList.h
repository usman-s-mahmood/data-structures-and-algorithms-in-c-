#include "LinkedList.h"

template <class T>
class CircularLinkedList: public LinkedList<T>
{
    public:
        CircularLinkedList();
        void insertAtHead(T);
        void insertAtTail(T);
        T deleteFromHead();
        T deleteFromTail();
        bool isEmpty();
        bool search(T);
        void display();
        void insertSortedASC(T);
        void insertSortedDSC(T);
        ~CircularLinkedList(){}
};

template <class T>
CircularLinkedList<T>::CircularLinkedList():
    LinkedList<T>::LinkedList()
{}

template <class T>
void CircularLinkedList<T>::insertAtHead(T value)
{
    struct Node<T> *node = new struct Node<T>;
    node->data = value;
    node->next = nullptr;
    if (isEmpty())
    {
        this->head = this->tail = node;
        node->next = this->head;
    }
    else
    {
        node->next = this->head;
        this->tail->next = node;
        this->head = node;
    }
    
}

template <class T>
void CircularLinkedList<T>::insertAtTail(T value)
{
    struct Node<T> *node = new Node<T>;
    node->data = value;
    node->next = nullptr;
    if (isEmpty())
    {
        this->head = this->tail = node;
        node->next = this->head;
    }
    else
    {
        this->tail->next = node;
        node->next = this->tail;
        this->tail = node;
        node->next = this->head;
    }
}

template <class T>
T CircularLinkedList<T>::deleteFromHead()
{
    if (isEmpty())
    {
        cout << "Empty Linked List has no values for deletion!" << endl;
        return -1;
    }
    T value = this->head->data;
    struct Node<T> *ptr = this->head;
    struct Node<T> *newHead = this->head->next;
    this->head = newHead;
    this->tail->next = this->head;
    delete ptr;
    ptr = nullptr;
    return value;
}

template <class T>
T CircularLinkedList<T>::deleteFromTail()
{
    if (isEmpty())
    {
        cout << "Empty Linked List has no values for deletion!" << endl;
        return -1;
    }
    T value = this->tail->data;
    struct Node<T> *ptr = this->head;
    while (ptr->next != this->tail)
        ptr = ptr->next;
    struct Node<T> *del = this->tail;
    ptr->next = this->head;
    this->tail = ptr;
    delete del;
    del = nullptr;
    return value;
} 

template <class T>
bool CircularLinkedList<T>::isEmpty()
{
    return (this->head == nullptr && this->tail == nullptr);
} 

template <class T>
bool CircularLinkedList<T>::search(T value)
{
    if (isEmpty())
        return false;
    struct Node<T> *ptr = this->head;
    do {
        if (ptr->data == value)
            return true;
        ptr = ptr->next;
    } while(ptr != this->head);
    return false;
}

template <class T>
void CircularLinkedList<T>::display()
{
    struct Node<T> *temp = this->head;
    do {
        cout << temp->data << ' ';
        temp = temp->next;
    } while(temp != this->head);
    cout << endl;
}

template <class T>
void CircularLinkedList<T>::insertSortedASC(T value)
{
    if (isEmpty())
        insertAtHead(value);
    else
    {
        if (value <= this->head->data)
            insertAtHead(value);
        else if (value >= this->tail->data)
            insertAtTail(value);
        else
        {
            struct Node<T> *node = new struct Node<T>;
            node->data = value;
            node->next = nullptr;
            struct Node<T> *ptr1 = this->head;
            struct Node<T> *ptr2 = this->head->next;
            do {
                if (value >= ptr1->data && ptr2->data >= value)
                    break;
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            } while (ptr2 != this->head);
            node->next = ptr2;
            ptr1->next = node;
        }
    }
}

template <class T>
void CircularLinkedList<T>::insertSortedDSC(T value)
{
    if (isEmpty())
        insertAtHead(value);
    else
    {
        if (value >= this->head->data)
            insertAtHead(value);
        else if (value <= this->tail->data)
            insertAtTail(value);
        else
        {
            struct Node<T> *node = new struct Node<T>;
            node->data = value;
            node->next = nullptr;
            struct Node<T> *ptr1 = this->head;
            struct Node<T> *ptr2 = this->head->next;
            do {
                if (value >= ptr2->data && value <= ptr1->data)
                    break;
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            } while (ptr2 != this->head);
            node->next = ptr2;
            ptr1->next = node;
        }
    }
}