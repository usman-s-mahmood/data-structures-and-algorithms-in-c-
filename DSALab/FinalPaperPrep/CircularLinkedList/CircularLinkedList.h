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
        void display();
        T deleteValue(T);
        bool search(T);
        bool isEmpty();
        int size();
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
bool CircularLinkedList<T>::search(T value)
{
    if (!isEmpty())
    {
        struct Node<T> *temp = this->tail;
        do {
            if (temp->data == value)
            {
                cout << "Value is found in the Linked List" << endl;
                return true;
            }
            temp = temp->next;
        } while (temp != this->tail);
        cout << "Value does not exist in the Linked List" << endl;
        return false;
    }
    cout << "Invalid Operation! Linked List is empty" << endl;
    return false;
}

template <class T>
int CircularLinkedList<T>::size()
{
    if (!isEmpty())
    {
        struct Node<T> *temp = this->tail;
        int size = 0;
        do {
            size++;
            temp = temp->next;
        } while (temp != this->tail);
        cout << "size of linked list is: " << size << endl;
        return size;
    }
    cout << "Invalid Operation! Linked List is empty" << endl;
    return 0;
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
        } while(headPtr != this->tail->next);
        cout << endl;
        return ;
    }
    cout << "Invalid Operation! Linked List is empty" << endl;
    return ;
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
    node->next = this->tail->next;
    this->tail->next = node;
    return ;
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
    return ;
}

template <class T>
T CircularLinkedList<T>::deleteFromHead()
{
    if (!isEmpty())
    {
        if (this->tail->next == this->tail)
        {
            T value = T();
            value = this->tail->data;
            delete this->tail;
            this->tail = nullptr;
            return value;
        }
        struct Node<T> *headPtr = this->tail->next;
        T value = headPtr->data;
        this->tail->next = headPtr->next;
        delete headPtr;
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
            T value = T();
            value = this->tail->data;
            delete this->tail;
            this->tail = nullptr;
            return value;
        }
        T value = this->tail->data;
        struct Node<T> *headPtr = this->tail->next;
        struct Node<T> *temp = headPtr;
        while (temp->next != this->tail)
            temp = temp->next;
        struct Node<T> *delPtr = temp->next;
        temp->next = headPtr;
        this->tail = temp;
        delete delPtr;
        return value;
    }
    cout << "Invalid Operation! Linked List is empty" << endl;
    return T();
}

template <class T>
T CircularLinkedList<T>::deleteValue(T value)
{
    if (!isEmpty())
    {
        if (search(value))
        {
            if (this->tail->data == value)
            {
                value = deleteFromTail();
                return value;
            }
            else if (this->tail->next->data == value)
            {
                deleteFromHead();
                return value;
            }
            struct Node<T> *ptr1 = this->tail->next;
            struct Node<T> *ptr2 = ptr1->next;
            while (ptr2->data != value)
            {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            ptr1->next = ptr2->next;
            delete ptr2;
            return value;
        }
        return T();
    }
    cout << "Invalid Operation! Linked List is Empty" << endl;
    return T();
}

template <class T>
CircularLinkedList<T>::~CircularLinkedList()
{
    while(!isEmpty())
        this->deleteFromTail();
    LinkedList<T>::~LinkedList();
}