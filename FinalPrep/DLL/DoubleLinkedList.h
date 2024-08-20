#include "LinkedList.h"

template <class T>
class DoubleLinkedList: public LinkedList<T>
{
    protected:

    public:
        DoubleLinkedList();
        void insertAtHead(T);
        void insertAtTail(T);
        T deleteFromHead();
        T deleteFromTail();
        void display();
        bool isEmpty();
        bool search(T);
        void sumTarget(int);
        ~DoubleLinkedList();
};

template <class T>
DoubleLinkedList<T>::DoubleLinkedList():
    LinkedList<T>::LinkedList()
{}

template <class T>
bool DoubleLinkedList<T>::isEmpty()
{
    return (this->head == nullptr && this->tail == nullptr);
}

template <class T>
void DoubleLinkedList<T>::insertAtHead(T value)
{
    struct Node<T> *node = new struct Node<T>;
    node->data = value;
    node->prev = node->next = nullptr;
    if (isEmpty())
    {
        this->tail = this->head = node;
        return ;
    }
    node->next = this->head;
    this->head->prev = node;
    this->head = node;
}

template <class T>
void DoubleLinkedList<T>::insertAtTail(T value)
{
    struct Node<T> *node = new struct Node<T>;
    node->data = value;
    node->prev = node->next = nullptr;
    if (isEmpty())
    {
        this->tail = this->head = node;
        return ;
    }
    this->tail->next = node;
    node->prev = this->tail;
    this->tail = node;    
}

template <class T>
T DoubleLinkedList<T>::deleteFromHead()
{
    if (!isEmpty())
    {
        if (this->head == this->tail)
        {
            T value = this->head->data;
            delete this->head;
            this->tail = this->head = nullptr;
            return value;
        }
        T value = this->head->data;
        struct Node<T> *delPtr = this->head;
        this->head = this->head->next;
        this->head->prev = nullptr;
        delete delPtr;
        delPtr = nullptr;
        return value;
    }
    cout << "Invalid Operation! Linked List is Empty" << endl;
    return T();
}

template <class T>
T DoubleLinkedList<T>::deleteFromTail()
{
    if (!isEmpty())
    {
        if (this->head == this->tail)
        {
            T value = this->head->data;
            delete this->head;
            this->tail = this->head = nullptr;
            return value;
        }
        T value = this->tail->data;
        struct Node<T> *delPtr = this->tail;
        this->tail = this->tail->prev;
        this->tail->next = nullptr;
        delete delPtr;
        delPtr = nullptr;
        return value;
    }
    cout << "Invalid Operation! Linked List is Empty" << endl;
    return T();
}

template <class T>
void DoubleLinkedList<T>::display()
{
    if (!isEmpty())
    {
        struct Node<T> *temp = this->head;
        while (temp != nullptr)
        {
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << endl;
        return ;
    }
    cout << "Invalid Operation! Linked List is empty" << endl;
}

template <class T>
bool DoubleLinkedList<T>::search(T value)
{
    if (!isEmpty())
    {
        struct Node<T> *temp = this->head;
        while (temp != nullptr)
        {
            if (temp->data == value)
            {
                cout << "Value is present in the linked list" << endl;
                return true;
            }
            temp = temp->next;
        }
        cout << "Value not found in the linked list" << endl;
        return false;
    }
    cout << "Invalid Operation! Linked List is empty" << endl;
    return false;
}

template <class T>
void DoubleLinkedList<T>::sumTarget(int target)
{
    if (!isEmpty())
    {
        struct Node<T> *ptr1 = this->head;
        struct Node<T> *ptr2 = ptr1->next;
        for (int i = 0; ptr1 != nullptr; i++)
        {
            for (int j = i+1; ptr2 != nullptr; j++)
            {
                if (ptr1->data + ptr2->data == target)
                    cout << ptr1->data << ' ' << ptr2->data << endl;
                else if (ptr1->data - ptr2->data == target)
                    cout << ptr1->data << ", " << ptr2->data << endl;
                ptr2 = ptr2->next;
            }
            ptr1 = ptr1->next;
            ptr2 = this->head->next;
        }
        return ;
    }
    cout << "Invalid Operation! Linked List is empty" << endl;
}

template <class T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
    while (!isEmpty())
        deleteFromTail();
    LinkedList<T>::~LinkedList();
}
