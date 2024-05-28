#include "LinkedList.h"

template <class T>
class MyLinkedList: public LinkedList<T>
{
    public:
        void insertAtHead(T value);
        void display();
        T deleteFromHead();
        void insertAtTail(T value);
        T deleteFromTail();
        void deleteValue(T value);
        void search(T value);
        void insertSorted(T value);
};

template <class T>
void MyLinkedList<T>::insertAtHead(T value)
{
    struct Node<T> *node = new struct Node<T>;
    node->data = value;
    node->next = nullptr;
    if (this->head == nullptr)
        this->head = node;
    else
    {
        node->next = this->head;
        this->head = node;
    }    
}

template <class T>
void MyLinkedList<T>::display()
{
    if (this->head == nullptr)
    {
        cout << "Empty Linked List has no values to show!"<<endl;
        return ;
    }
    struct Node<T> *temp = this->head;
    while (temp != nullptr)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout<<endl;
}

template <class T>
T MyLinkedList<T>::deleteFromHead()
{
    if (this->head == nullptr)
    {
        cout << "Empty linked list can't be used for this operation!"<<endl;
        return T(1);
    }
    else if (this->head->next == nullptr)
    {
        T value = this->head->data;
        delete this->head;
        this->head = nullptr;
        return value;
    }
    else
    {
        T value = this->head->data;
        struct Node<T> *temp = this->head;
        this->head = this->head->next;
        delete temp;
        return value;
    }
}

template <class T>
void MyLinkedList<T>::insertAtTail(T value)
{
    struct Node<T> *node = new struct Node<T>;
    node->data = value;
    node->next = nullptr;
    if (this->head == nullptr)
        this->head = node;
    else
    {
        struct Node<T> *ptr1 = this->head;
        while (ptr1->next != nullptr)
            ptr1 = ptr1->next;
        ptr1->next = node;
    }
}

template <class T>
T MyLinkedList<T>::deleteFromTail()
{
    if (this->head == nullptr)
    {
        cout << "Deletion not possible!" << endl;
        return T(1);
    }
    else if (this->head->next == nullptr)
    {
        T value = deleteFromHead();
        return value;
    }
    else
    {
        struct Node<T> *ptr1 = this->head;
        struct Node<T> *ptr2 = ptr1->next;
        while (ptr2->next != nullptr)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        T value = ptr2->data;
        ptr1->next = nullptr;
        delete ptr2;
        ptr2 = nullptr;
        return value;
    }
}

template <class T>
void MyLinkedList<T>::deleteValue(T value)
{
    if (this->head == nullptr)
    {
        cout << "Empty linked list can't be used for this purpose" << endl;
        return ;
    }
    else if (this->head->data == value)
    {
        deleteFromHead();
        cout << "Value has been deleted!" << endl;
    }
    else
    {
        struct Node<T> *ptr1 = this->head;
        struct Node<T> *ptr2 = ptr1->next;
        while (ptr2 != nullptr)
        {
            if (ptr2->data == value)
            {
                ptr1->next = ptr2->next;
                delete ptr2;
                ptr2 = nullptr;
                cout << "Value has now been deleted!" << endl;
                return ;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        cout << "Value not found in the linked list" << endl;
    }
}

template <class T>
void MyLinkedList<T>::search(T value)
{
    if (this->head == nullptr)
    {
        cout << "Empty linked list can't be used for this purpose" << endl;
        return ;
    }
    else if (this->head->data == value)
        cout << "Value is present in the linked list!" << endl;
    else 
    {
        struct Node<T> *ptr = this->head;
        while (ptr != nullptr)
        {
            if (ptr->data == value)
            {
                cout << "Value found in the linked list!" << endl;
                return ;
            }
            ptr = ptr->next;
        }
        cout << "Value not present in the linked list!" << endl;
    }
}

template <class T>
void MyLinkedList<T>::insertSorted(T value)
{
    if (this->head == nullptr)
        insertAtHead(value);
    else if (this->head->data >= value)
        insertAtHead(value);
    else
    {
        struct Node<T> *node = new struct Node<T>;
        node->data = value;
        node->next = nullptr;
        if (this->head->data < value)
        {
            struct Node<T> *node = new struct Node<T>;
            node->data = value;
            node->next = nullptr;
            struct Node<T> *ptr1 = this->head;
            struct Node<T> *ptr2 = ptr1->next;
            while (ptr2 != nullptr)
            {
                if (ptr1->data <= value && ptr2->data >= value)
                {
                    node->next = ptr2;
                    ptr1->next = node;
                    break;
                }
                else if (ptr2->next == nullptr)
                {
                    ptr2->next = node;
                    break;
                }
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
        }

    }
}