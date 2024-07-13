#include "DoubleLinkedList.h"

template <class T>
class DoubleCircularLinkedList: public DoubleLinkedList<T>
{
    public:
        DoubleCircularLinkedList();
        void insertAtHead(T);
        void insertAtTail(T);
        T deleteFromHead();
        T deleteFromTail();
        T deleteValue(T);
        void display();
        bool isEmpty();
        bool search(T);
        int size();
        ~DoubleCircularLinkedList();
};

template <class T>
DoubleCircularLinkedList<T>::DoubleCircularLinkedList():
    DoubleLinkedList<T>::DoubleLinkedList()
{}

template <class T>
bool DoubleCircularLinkedList<T>::isEmpty()
{
    return (this->tail == nullptr);
}

template <class T>
bool DoubleCircularLinkedList<T>::search(T value)
{
    if (!isEmpty())
    {
        struct Node<T> *temp = this->tail;
        do {
            if (temp->data == value)
            {
                cout << "Value found in the linked list!" << endl;
                return true;
            }
            temp = temp->next;
        } while (temp != this->tail);
        cout << "Value is not present in the linked list" << endl;
        return false;
    }
    cout << "Invalid Operation! Linked List is empty" << endl;
    return false;
}

template <class T>
int DoubleCircularLinkedList<T>::size()
{
    if (!isEmpty())
    {
        int size = 0;
        struct Node<T> *temp = this->tail;
        do {
            size++;
            temp = temp->next;
        } while(temp != this->tail);
        return size;
    }
    cout << "Invalid Operation! Linked List is empty" << endl;
    return 0;
}

template <class T>
void DoubleCircularLinkedList<T>::insertAtHead(T value)
{
    struct Node<T> *node = new struct Node<T>;
    node->data = value;
    node->next = node->prev = nullptr;
    if (isEmpty())
    {
        this->tail = node;
        this->tail->next = this->tail;
        this->tail->prev = this->tail;
        return ;
    }
    struct Node<T> *temp = this->tail->next; // headPtr;
    node->next = temp;
    temp->prev = node;
    this->tail->next = node;
    node->prev = this->tail;
    return ;
}

template <class T>
void DoubleCircularLinkedList<T>::insertAtTail(T value)
{
    struct Node<T> *node = new struct Node<T>;
    node->data = value;
    node->next = node->prev = nullptr;
    if (isEmpty())
    {
        this->tail = node;
        this->tail->next = this->tail;
        this->tail->prev = this->tail;
        return ;
    }
    struct Node<T> *temp = this->tail->next; // headPtr;
    node->next = temp;
    temp->prev = node;
    this->tail->next = node;
    node->prev = this->tail;
    this->tail = node;
    return ;
}

template <class T>
T DoubleCircularLinkedList<T>::deleteFromHead()
{
    if (!isEmpty())
    {
        if (this->tail->next == this->tail && this->tail->prev == this->tail)
        {
            T value = T();
            value = this->tail->data;
            delete this->tail;
            this->tail = nullptr;
            return value;
        }
        T value = T();
        value = this->tail->next->data;
        struct Node<T> *delPtr = this->tail->next;
        struct Node<T> *newHead = this->tail->next->next;
        newHead->prev = this->tail;
        this->tail->next = newHead;
        delete delPtr;
        delPtr = nullptr;
        return value;
    }
    cout << "Invalid Operation! Linked List is empty" << endl;
    return T();
}

template <class T>
T DoubleCircularLinkedList<T>::deleteFromTail()
{
    if (!isEmpty())
    {
        if (this->tail->next == this->tail && this->tail->prev == this->tail)
        {
            T value = T();
            value = this->tail->data;
            delete this->tail;
            this->tail = nullptr;
            return value;
        }
        struct Node<T> *newTail = this->tail->prev;
        struct Node<T> *headPtr = this->tail->next;
        T value = T();
        value = this->tail->data;
        struct Node<T> *delPtr = this->tail;
        this->tail = newTail;
        this->tail->next = headPtr;
        headPtr->prev = this->tail;
        delete delPtr;
        delPtr = nullptr;
        return value;
    }
    cout << "Invalid Operation! Linked List is empty" << endl;
    return T();
}

template <class T>
T DoubleCircularLinkedList<T>::deleteValue(T value)
{
    if (!isEmpty())
    {
        if (search(value))
        {
            if (this->tail->data == value)
            {
                deleteFromTail();
                return value;
            }
            else if (this->tail->next->data == value)
            {
                deleteFromHead();
                return value;
            }
            struct Node<T> *ptr1 = this->tail;
            struct Node<T> *ptr2 = this->tail->next;
            do {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            } while(ptr2->data != value);
            ptr1->next = ptr2->next;
            ptr2->next->prev = ptr1;
            return value;
        }
        return T();
    }
    cout << "Invalid Operation! Linked List is empty" << endl;
    return T();
}

template <class T>
void DoubleCircularLinkedList<T>::display()
{
    if (!isEmpty())
    {
        cout << "Ascending Printing of Linked List: " ;
        struct Node<T> *headPtr = this->tail->next;
        do {
            cout << headPtr->data << ' ';
            headPtr = headPtr->next;
        } while(headPtr != this->tail->next);
        cout << endl;
        cout << "Descending Printing of Linked List: " ;
        struct Node<T> *temp = this->tail;
        do {
            cout << temp->data << ' ';
            temp = temp->prev;
        } while(temp != this->tail);
        cout << endl;
        return ;
    }
    cout << "Invalid Operation! Linked List is Empty" << endl;
    return ;
}

template <class T>
DoubleCircularLinkedList<T>::~DoubleCircularLinkedList()
{
    while (!isEmpty())
        this->deleteFromTail();
    DoubleLinkedList<T>::~DoubleLinkedList();
}


