#include "DoubleLinkedList.h"

template <class T>
class MyDoubleLinkedList : public DoubleLinkedList<T>
{
public:
    MyDoubleLinkedList(): DoubleLinkedList<T>::DoubleLinkedList() {}
    MyDoubleLinkedList(MyDoubleLinkedList<T> &copy)
    {
        this->head = copy.head;
        this->tail = copy.tail;
    }
    void insertAtHead(T);
    void insertAtTail(T);
    void insertAtPosition(T value, int pos);
    T deleteFromHead();
    T deleteFromTail();
    T deleteFromPosition(int);
    int size();
    bool isEmpty();
    bool search(T);
    void display();
    void displayASC();
    void displayDSC();
    void reverseList();
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

template <class T>
int MyDoubleLinkedList<T>::size()
{
    if (isEmpty())
        return 0;
    struct Node<T> *headPtr = this->head;
    int sz = 0;
    while(headPtr != nullptr)
    {
        sz++;
        headPtr = headPtr->next;
    }
    return sz;
}

template <class T>
void MyDoubleLinkedList<T>::insertAtPosition(T value, int pos) 
{
    if (pos < 0) 
    {
        cout << "Invalid Operation! Position < 0" << endl;
        return;
    }
    if (isEmpty() && pos == 0) 
    {
        insertAtHead(value);
        return;
    }
    int sz = size();
    if (pos > sz) 
    {
        cout << "Invalid Operation! Position > size" << endl;
        return;
    }
    else if (pos == 0) 
        insertAtHead(value);
    else if (pos == sz) 
        insertAtTail(value);
    else 
    {
        struct Node<T> *node = new struct Node<T>;
        node->data = value;
        node->next = nullptr;  
        node->prev = nullptr; 
        struct Node<T> *headPtr = this->head;
        for (int itr = 0; itr < pos - 1; itr++)
            headPtr = headPtr->next;
        node->next = headPtr->next;
        node->prev = headPtr;
        headPtr->next->prev = node;
        headPtr->next = node;
    }
}


template <class T>
T MyDoubleLinkedList<T>::deleteFromPosition(int pos) 
{
    int sz = size();
    if (isEmpty()) 
    {
        cout << "Invalid Operation! List is empty." << endl;
        return 0;  
    }
    if (pos < 0 || pos >= sz) 
    {
        cout << "Invalid Position!" << endl;
        return 0;  
    }
    if (pos == 0) 
    {
        T value = deleteFromHead();
        return value;
    } 
    else if (pos == sz - 1) 
    {
        T value = deleteFromTail();
        return value;
    } 
    else 
    {
        struct Node<T> *current = this->head;
        for (int itr = 0; itr < pos; ++itr) 
            current = current->next;
        T value = current->data;
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        return value;
    }
}


template <class T>
void MyDoubleLinkedList<T>::displayASC()
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
}

template <class T>
void MyDoubleLinkedList<T>::displayDSC()
{
    if (isEmpty())
    {
        cout << "Empty Linked List has no values to display" << endl;
        return;
    }
    struct Node<T> *tempTail = this->tail;
    while (tempTail != nullptr)
    {
        cout << tempTail->data << ' ';
        tempTail = tempTail->prev;
    }
    cout << endl;
}

template <class T>
void MyDoubleLinkedList<T>::reverseList()
{
    if (isEmpty())
    {
        cout << "Invalid Operation!" << endl;
        return ;
    }
    const int sz = size();
    T arr[sz];
    struct Node<T> *temp = this->head;
    for (int i = 0; i < sz; i++)
    {
        arr[i] = temp->data;
        temp = temp->next;
    }
    // for (int i = 0; i < sz; i++)
    //     cout << arr[i] << " . ";
    // cout << endl;
    struct Node<T> *headPtr = this->head;
    for (int i = sz-1; i >= 0; i--)
    {
        headPtr->data = arr[i];
        headPtr = headPtr->next;
    }

}