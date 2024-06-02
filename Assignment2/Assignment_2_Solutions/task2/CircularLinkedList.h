#include "LinkedList.h"

template <class T>
class CircularLinkedList: public LinkedList<T>
{
    public:
        CircularLinkedList();
        void insertAtHead(T);
        void insertAtTail(T);
        void insertAtPosition(T, int);
        int size();
        T deleteFromHead();
        T deleteFromTail();
        T deleteFromPosition(int);
        void display();
        bool isEmpty();
        void insertSorted(T);
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
    else if (this->tail->next == this->tail)
    {
        T value = this->tail->data;
        delete this->tail;
        this->tail = nullptr;
        return value;
    }
    T value = this->tail->next->data;
    struct Node<T> *headPtr = this->tail->next;
    this->tail->next = headPtr->next;
    delete headPtr;
    headPtr = nullptr;
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
    else if (this->tail->next == this->tail)
    {
        T value = this->tail->data;
        delete this->tail;
        this->tail = nullptr;
        return value;
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
    ptr2 = nullptr;
    return value;
}
template <class T>
void CircularLinkedList<T>::display()
{
    if (isEmpty())
    {
        cout << "Linked List is Empty!" << endl;
        return;
    }
    // struct Node<T> *tailPtr = this->tail->next;
    // while (true)
    // {
    //     cout << tailPtr->data << ' ';
    //     tailPtr = tailPtr->next;
    //     if (tailPtr == this->tail)
    //         break;
    // }
    // cout << this->tail->data << endl;
    struct Node<T> *headPtr = this->tail->next;
    // struct Node<T> *tailPtr = this->tail;
    do {
        cout << headPtr->data << ' ';
        headPtr = headPtr->next;
    } while (headPtr != this->tail->next);
    cout << endl;
    // do {
    //     cout << tailPtr->data << ' ';
    //     tailPtr = tailPtr->next;
    // } while (tailPtr != this->tail);
    // cout << endl;
    return ;
}

template <class T>
void CircularLinkedList<T>::insertSorted(T value)
{
    // struct Node<T> *headPtr = this->tail->next;
    // struct Node<T> *tailPtr = this->tail;
    if (isEmpty())
        insertAtHead(value);
    else if (value > this->tail->data)
        insertAtTail(value);
    else 
    {
        if (value < this->tail->next->data)
            insertAtHead(value);
        else
        {
            struct Node<T> *node = new struct Node<T>;
            node->data = value;
            node->next = nullptr;
            struct Node<T> *ptr1 = this->tail->next;
            struct Node<T> *ptr2 = ptr1->next;
            do {
                if (ptr1->data <= value && ptr2->data >= value)
                {
                    node->next = ptr2;
                    ptr1->next = node;
                    break ;
                }
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            } while (ptr2 != this->tail->next);
        }    
    }
}

template <class T>
int CircularLinkedList<T>::size()
{
    if (isEmpty())
        return 0;
    struct Node<T> *temp = this->tail->next;
    int sz = 1;
    while (temp != this->tail)
    {
        sz++;
        temp = temp->next;
    }
    return sz;
}

template <class T>
void CircularLinkedList<T>::insertAtPosition(T value, int pos) {
    int sz = size();
    if (isEmpty())
    {
        cout << "Invalid Operation!" << endl;
        return ;
    }
    if (pos < 0 || pos > sz) 
    {
        cout << "Invalid Position!" << endl;
        return;    
    }
    if (pos == 0)
        insertAtHead(value);
    else if (pos == sz) 
        insertAtTail(value);
    else 
    {
        struct Node<T>* current = this->tail->next; 
        for (int itr = 0; itr < pos - 1; itr++) 
            current = current->next;        
        struct Node<T>* node = new Node<T>;
        node->data = value;
        node->next = current->next;
        current->next = node;
    }
}

template <class T>
T CircularLinkedList<T>::deleteFromPosition(int pos)
{
    int sz = size();
    if (isEmpty())
    {
        cout << "Invalid Operation!" << endl;
        return 0;
    }
    else if (pos < 0)
    {
        cout << "Invalid Position!" << endl;
        return 0;
    }
    else if (pos >= sz)
    {
        cout << "Invalid Position!" << endl;
        return 0;
    }
    else if (pos == 0)
    {
        T value = deleteFromHead();
        return value;
    }
    else if (pos == sz-1)
    {
        T value = deleteFromTail();
        return value;
    }
    else
    {
        struct Node<T> *ptr1 = this->tail->next;
        struct Node<T> *ptr2 = ptr1->next;
        for (int i = 0; i < pos-1; i++)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        T value = ptr2->data;
        ptr1->next = ptr2->next;
        delete ptr2;
        ptr2 = nullptr;
        return value;
    }
}