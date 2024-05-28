#include "DoubleLinkedList.h"

template <class T>
class MyDoubleLinkedList : public DoubleLinkedList<T>
{
public:
    MyDoubleLinkedList(): DoubleLinkedList<T>::DoubleLinkedList() {}
    void insertAtHead(T);
    void insertAtTail(T);
    T deleteFromHead();
    T deleteFromTail();
    bool isEmpty();
    bool search(T);
    void display();
    void insertSortedASC(T);
    void insertSortedDSC(T);
    ~MyDoubleLinkedList()
    {
        while (!isEmpty())
            deleteFromHead();
        delete this->head;
        delete this->tail;
    }
};

template <class T>
void MyDoubleLinkedList<T>::insertAtHead(T value)
{
    struct Node<T> *node = new struct Node<T>;
    node->prev = nullptr;
    node->data = value;
    node->next = nullptr;
    if (isEmpty())
        this->head = this->tail = node;
    else
    {
        node->next = this->head;
        this->head->prev = node;
        this->head = node;
    }
}

template <class T>
void MyDoubleLinkedList<T>::insertAtTail(T value)
{
    struct Node<T> *node = new struct Node<T>;
    node->prev = nullptr;
    node->data = value;
    node->next = nullptr;
    if (isEmpty())
        this->head = this->tail = node;
    else
    {
        this->tail->next = node;
        node->prev = this->tail;
        node->next = nullptr;
        this->tail = node;
    }
}

template <class T>
T MyDoubleLinkedList<T>::deleteFromHead()
{
    if (isEmpty())
        throw runtime_error("No value to return");
    T value = this->head->data;
    struct Node<T> *del = this->head;
    if (this->head == this->tail)
        this->head = this->tail = nullptr;
    else
    {
        this->head = this->head->next;
        if (this->head != nullptr)
            this->head->prev = nullptr;
    }
    delete del;
    return value;
}

template <class T>
T MyDoubleLinkedList<T>::deleteFromTail()
{
    if (isEmpty())
        throw runtime_error("No value for deletion!");
    T value = this->tail->data;
    struct Node<T> *del = this->tail;
    if (this->head == this->tail)
        this->head = this->tail = nullptr;
    else
    {
        this->tail = this->tail->prev;
        if (this->tail != nullptr)
            this->tail->next = nullptr;
    }
    delete del;
    return value;
}

template <class T>
bool MyDoubleLinkedList<T>::search(T value)
{
    if (isEmpty())
        return false;
    struct Node<T> *temp = this->head;
    while (temp != nullptr)
    {
        if (temp->data == value)
            return true;
        temp = temp->next;
    }
    return false;
}

template <class T>
bool MyDoubleLinkedList<T>::isEmpty()
{
    return (this->head == nullptr && this->tail == nullptr);
}

template <class T>
void MyDoubleLinkedList<T>::display()
{
    if (isEmpty())
    {
        cout << "Empty Linked List has no values to display" << endl;
        return;
    }
    struct Node<T> *temp = this->head;
    while (temp != nullptr)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << endl;
    cout << "Reversed Linked List: " << endl;
    struct Node<T> *tempTail = this->tail;
    while (tempTail != nullptr)
    {
        cout << tempTail->data << ' ';
        tempTail = tempTail->prev;
    }
    cout << endl;
}

template <class T>
void MyDoubleLinkedList<T>::insertSortedASC(T value)
{
    struct Node<T> *node = new struct Node<T>;
    node->next = nullptr;
    node->data = value;
    node->prev = nullptr;
    if (isEmpty())
        this->head = this->tail = node;
    else
    {
        if (value <= this->head->data)
            insertAtHead(value);
        else if (value >= this->tail->data)
            insertAtTail(value);
        else
        {
            struct Node<T> *ptr1 = this->head;
            struct Node<T> *ptr2 = this->head->next;
            while (true)
            {
                if (ptr1->data <= value && ptr2->data >= value)
                    break;
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            node->next = ptr2;
            ptr2->prev = node;
            node->prev = ptr1;
            ptr1->next = node;
        }
    }
}

template <class T>
void MyDoubleLinkedList<T>::insertSortedDSC(T value)
{
    struct Node<T> *node = new struct Node<T>;
    node->prev = nullptr;
    node->data = value;
    node->next = nullptr;
    if (isEmpty())
        this->head = this->tail = node;
    else
    {
        if (value >= this->head->data)
            insertAtHead(value);
        else if (value <= this->tail->data)
            insertAtTail(value);
        else
        {
            struct Node<T> *ptr1 = this->head;
            struct Node<T> *ptr2 = this->head->next;
            while (true)
            {
                if (ptr1->data >= value && ptr2->data <= value)
                    break;
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            node->next = ptr2;
            ptr2->prev = node;
            node->prev = ptr1;
            ptr1->next = node;
        }
    }
}