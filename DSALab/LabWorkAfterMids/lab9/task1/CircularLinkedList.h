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
        bool isEmpty();
        void insertSorted(T);
        void convertList(); // convert singly linked list into circular linked list
        T printNthFromLast(int n); // return value at the nth node from the end of the linkedlist
        void sortList(); // sort a linkedlist of 0s, 1s and 2s 
        ~CircularLinkedList()
        {
            while(!isEmpty())
                deleteFromHead();
        }
};

template <class T>
CircularLinkedList<T>::CircularLinkedList():
    LinkedList<T>::LinkedList()
{}

template <class T>
bool CircularLinkedList<T>::isEmpty()
{
    return (this->head == nullptr);
}

template <class T>
void CircularLinkedList<T>::insertAtHead(T value)
{
    struct Node<T> *node = new struct Node<T>;
    node->data = value;
    node->next = nullptr;
    if (isEmpty())
    {
        this->head = node;
        node->next = this->head;
    }
    else
    {
        node->next = this->head;
        struct Node<T> *tailPtr = this->head;
        do {
            tailPtr = tailPtr->next;
        } while (tailPtr->next != this->head);
        tailPtr->next = node;
        this->head = node;
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
        this->head = node;
        node->next = this->head;
    }
    else
    {
        struct Node<T> *tailPtr = this->head;
        do {
            tailPtr = tailPtr->next;
        } while (tailPtr->next != this->head);
        node->next = this->head;
        tailPtr->next = node;
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
    else if (this->head->next == this->head)
    {
        T value = this->head->data;
        delete this->head;
        this->head = nullptr;
        return value;
    }
    T value = this->head->data;
    struct Node<T> *tailPtr = this->head;
    do {
        tailPtr = tailPtr->next;
    } while (tailPtr->next != this->head);
    tailPtr->next = this->head->next;
    struct Node<T> *headPtr = this->head;
    this->head = this->head->next;
    delete headPtr;
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
    else if (this->head->next == this->head)
    {
        T value = this->head->data;
        delete this->head;
        this->head = nullptr;
        return value;
    }
    struct Node<T> *ptr1 = this->head;
    struct Node<T> *ptr2 = this->head->next;
    do {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    } while (ptr2->next != this->head);
    T value = ptr2->data;
    ptr1->next = this->head;
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
    struct Node<T> *headPtr = this->head;
    // struct Node<T> *tailPtr = this->tail;
    do {
        cout << headPtr->data << ' ';
        headPtr = headPtr->next;
    } while (headPtr != this->head);
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
            struct Node<T> *ptr1 = this->head;
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
            } while (ptr2 != this->head);
        }    
    }
}

template <class T>
T CircularLinkedList<T>::printNthFromLast(int n)
{
    struct Node<T> *head = this->head;
    if (isEmpty())
    {
        cout << "Invalid Operation for empty Linked List!" << endl;
        return -1;
    }
    int pos = 1;
    do {
        if (head->data == n)
        {
            cout << "Value "<<n<<" is found at " << pos << " postion in the linked list" << endl;
            return head->data;
        }
        head = head->next;
        pos++;
    } while (head != this->head);
    cout << "Value " << n << " is not present in the list!" << endl;
    return -1;
}

template <class T>
void CircularLinkedList<T>::sortList()
{
    if (isEmpty())
    {
        cout << "Invalid Operation on empty Linked List!" << endl;
        return ;
    }
    int size = 0;
    struct Node<T> *ptr = this->head;
    do {
        ptr = ptr->next;
        size++;
    } while (ptr != this->head);
    cout << "Size of Linked List: " << size << endl;
    struct Node<T> *ptr1 = this->head;
    struct Node<T> *ptr2 = this->head->next;
    T temp;
    for (int i = 0; i < size; i++)
    {
        ptr2 = ptr1->next;
        for (int j = i + 1; j < size; j++)
        {
            if (ptr1->data > ptr2->data)
            {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    this->display();
}

template <class T>
void CircularLinkedList<T>::convertList()
{
    if (isEmpty())
    {
        cout << "Invalid Operation for empty Linked List!" << endl;
        return ;
    }
    
}