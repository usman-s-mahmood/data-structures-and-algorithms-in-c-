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
    node->data = value;
    if (isEmpty())
    {
        this->head = node;
        node->prev = node->next = this->head;
        return ;
    }
    node->next = this->head;
    this->head->prev->next = node;
    node->prev = this->head->prev;
    this->head->prev = node;
    this->head = node;
}

template <class T>
void DoubleCircularLinkedList<T>::insertAtTail(T value)
{
    struct Node<T> *node = new struct Node<T>;
    node->data = value;
    if (isEmpty())
    {
        this->head = node;
        node->prev = node->next = this->head;
        return ;
    }
    node->next = this->head;
    this->head->prev->next = node;
    node->prev = this->head->prev;
    this->head->prev = node;
    // this->head = node;
}

template <class T>
T DoubleCircularLinkedList<T>::deleteFromHead()
{
    if (isEmpty())
    {
        cout << "Invalid Operation!" << endl;
        return -1;
    }
    else if (this->head->next == this->head && this->head->prev == this->head)
    {
        struct Node<T> *temp = this->head;
        T value = temp->data;
        delete temp;
        temp = nullptr;
        this->head = nullptr;
        return value;
    }
    T value = this->head->data;
    struct Node<T> *temp = this->head;
    this->head->prev->next = this->head->next;
    this->head->next->prev = this->head->prev;
    this->head = this->head->next;
    delete temp;
    temp = nullptr;
    return value;
}

template <class T>
T DoubleCircularLinkedList<T>::deleteFromTail()
{
    if (isEmpty())
    {
        cout << "Invalid Operation!" << endl;
        return -1;
    }
    else if (this->head->next == this->head && this->head->prev == this->head)
    {
        struct Node<T> *temp = this->head;
        T value = temp->data;
        delete temp;
        temp = nullptr;
        this->head = nullptr;
        return value;
    }
    struct Node<T> *temp = this->head->prev;
    T value = this->head->prev->data;
    this->head->prev = temp->prev;
    temp->prev->next = this->head;
    delete temp;
    temp = nullptr;
    return value;
}

template <class T>
void DoubleCircularLinkedList<T>::display()
{
    if (isEmpty())
    {
        cout << "Empty Linked List has no values to display!" << endl;
        return ;
    }
    struct Node<T> *temp = this->head;
    do {
        cout << temp->data << ' ';
        temp = temp->next;
    } while (temp != this->head);
    cout << endl;
    temp = this->head->prev;
    do {
        cout << temp->data << ' ';
        temp = temp->prev;
    } while (temp != this->head->prev);
    cout << endl;
}

template <class T>
void DoubleCircularLinkedList<T>::insertSorted(T value)
{
    if (isEmpty())
        insertAtHead(value);
    else
    {
        if (value <= this->head->data)
            insertAtHead(value);
        else if (value >= this->head->prev->data)
            insertAtTail(value);
        else
        {
            struct Node<T> *ptr1 = this->head;
            struct Node<T> *ptr2 = ptr1->next;
            struct Node<T> *node = new struct Node<T>;
            node->data = value;
            do {
                if (value >= ptr1->data && value <= ptr2->data)
                {
                    node->next = ptr2;
                    ptr2->prev = node;
                    node->prev = ptr1;
                    ptr1->next = node;
                    break;
                }
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            } while (ptr2 != this->head->next);

        }
    }
}