#include "LinkedList.h"

template <class T>
class MyLinkedList: public LinkedList<T>
{
    public:
        MyLinkedList();
        void insertAtTail(T value);
        void insertAtHead(T value);
        void insertAtValue(T target, T value);
        void insertAfterValue(T target, T value);
        void insertBeforeValue(T target, T value);
        T deleteAtHead();
        T deleteAtTail();
        T deleteValue(T value);
        void display();
        bool isEmpty();
        void search(T value);
        int size();
        T mid();
        T peekPos(int);
        void isPalindrome();
        void removeDuplicates();
        Node<T>* reverseList(Node<T>* node);
        void reverse();
        int length(Node<T>* node);
        int getLength();
        ~MyLinkedList(){}
};

template <class T>
MyLinkedList<T>::MyLinkedList():
    LinkedList<T>::LinkedList()
{}

template <class T>
bool MyLinkedList<T>::isEmpty()
{
    return (this->head == nullptr && this->tail == nullptr);
}

template <class T>
void MyLinkedList<T>::insertAtTail(T value)
{
    struct Node<T> *ptr = new struct Node<T>;
    ptr->data = value;
    ptr->next = nullptr;
    if (isEmpty())
        this->head = this->tail = ptr;
    else
    {
        this->tail->next = ptr;
        this->tail = ptr;
    }
}

template <class T>
void MyLinkedList<T>::insertAtHead(T value)
{
    struct Node<T> *ptr = new struct Node<T>;
    ptr->data = value;
    ptr->next = nullptr;
    if (isEmpty())
        this->head = this->tail = ptr;
    else
    {
        ptr->next = this->head;
        this->head = ptr;
    }
}

template <class T>
void MyLinkedList<T>::display()
{
    if(isEmpty())
    {
        cout<<"Linked list is empty!"<<endl;
        return ;
    }
    struct Node<T> *temp = this->head;
    while (temp != nullptr)
    {
        cout<<temp->data<<endl;
        temp = temp->next;
    }
    cout<<endl;
}

template <class T>
T MyLinkedList<T>::deleteAtHead()
{
    if (isEmpty())
    {
        cout<<"Empty linked list has not values for deletion!"<<endl;
        return T();
    }
    T value = this->head->data;
    struct Node<T> *ptr = this->head;
    this->head = ptr->next;
    delete ptr;
    return value;
}

template <class T>
T MyLinkedList<T>::deleteAtTail()
{
    if (isEmpty())
    {
        cout<<"Empty linked list has not values for deletion!"<<endl;
        return T();
    }
    if (this->head->next == nullptr && this->tail->next == nullptr)
    {
        T value = this->head->data;
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
        return value;
    }
    struct Node<T> *ptr = this->head;
    while (ptr->next != this->tail)
        ptr = ptr->next;
    T value = this->tail->data;
    struct Node<T> *temp = ptr->next;
    delete temp;
    ptr->next = nullptr;
    this->tail = ptr;
    return value;
    
}

template <class T>
void MyLinkedList<T>::search(T value)
{
    if (isEmpty())
    {
        cout<<"Empty linked list has no values for searching"<<endl;
        return;
    }
    else if(this->head->data == value)
        cout<<"Value found at head: "<<this->head->data<<endl;
    else if(this->tail->data == value)
        cout<<"Value found at tail: "<<this->tail->data<<endl;
    else
    {
        struct Node<T> *ptr = this->head;
        while(ptr != nullptr)
        {
            if(ptr->data == value)
            {
                cout<<"Value found in the linked list: "<<ptr->data<<endl;
                return ;
            }
            ptr = ptr->next;
        }
        cout<<"Value is not in the linked list!"<<endl;
    }
}

template <class T>
T MyLinkedList<T>::deleteValue(T value)
{
    
    if (isEmpty())
    {
        cout<<"List is empty!"<<endl;
        return T();
    }
    else if (this->head->data == value)
        deleteAtHead();
    else if (this->tail->data == value)
        deleteAtTail();
    else
    {
        struct Node<T> *ptr1 = this->head;
        struct Node<T> *ptr2 = ptr1->next;
        while(ptr2->data != value)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        if (ptr2 != nullptr)
        {
            T value = ptr2->data;
            ptr1->next = ptr2->next;
            delete ptr2;
            return value;
        }
        else
        {
            cout<<"Value not found in the list!"<<endl;
            return T();
        }
    }
    return T();
}

template <class T>
void MyLinkedList<T>::insertAtValue(T target, T value)
{
    if (isEmpty())
    {
        cout<<"Empty list does not contain target value"<<endl;
        return ;
    }
    else if (this->head->data == target)
        insertAtHead(value);
    else if (this->tail->data == target)
        insertAtTail(value);
    else
    {
        struct Node<T> *ptr1 = this->head;
        struct Node<T> *ptr2 = this->head->next;
        while (ptr2->data != target)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            if (ptr2 == nullptr)
            {
                cout<<"target not present in the list"<<endl;
                return ;
            }
        }
        if (ptr2 != nullptr)
        {
            struct Node<T> *node = new struct Node<T>;
            node->data = value;
            ptr1->next = node;
            node->next = ptr2;
            cout<<"Value inserted successfully!"<<endl;
        }
    }
}

template <class T>
void MyLinkedList<T>::insertAfterValue(T target, T value)
{
    if (isEmpty())
        cout<<"Linked list is empty!"<<endl;
    else if (this->head->data == target)
    {
        cout<<true<<endl;
        struct Node<T> *node = new struct Node<T>;
        node->data = value;
        node->next = this->head->next;
        this->head->next = node;
    }
    else if(this->tail->data == target)
    {
        struct Node<T> *node = new struct Node<T>;
        node->data = value;
        this->tail->next = node;
        node->next = nullptr;
        this->tail = node;
    }
    else
    {
        struct Node<T> *ptr1 = this->head;
        struct Node<T> *ptr2 = this->head->next;
        while (ptr1->data != target)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            if (ptr2 == nullptr)
            {
                cout<<"Target node is not present in the list!"<<endl;
                return ;
            }
        }
        if (ptr1->data == target)
        {
            struct Node<T> *node = new struct Node<T>;
            node->data = value;
            ptr1->next = node;
            node->next = ptr2;
        }
    }
}

template <class T>
void MyLinkedList<T>::insertBeforeValue(T target, T value)
{
    if (this->head->data == target)
    {
        struct Node<T> *node = new struct Node<T>;
        node->data = value;
        node->next = this->head;
        this->head = node;
    }
    else if (this->tail->data == target)
    {
        struct Node<T> *node = new struct Node<T>;
        node->data = value;
        struct Node<T> *ptr1 = this->head;
        struct Node<T> *ptr2 = this->head->next;
        while (ptr2->next != nullptr)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        ptr1->next = node;
        node->next = ptr2;
    }
    else
    {
        struct Node<T> *ptr1 = this->head;
        struct Node<T> *ptr2 = this->head->next;
        while (ptr2->data != target)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            if (ptr2 == nullptr)
            {
                cout<<"Target value does not exist in the linked list!"<<endl;
                return ;
            }
        }
        if (ptr2->data == target)
        {
            struct Node<T> *node = new struct Node<T>;
            node->data = value;
            ptr1->next = node;
            node->next = ptr2;
            cout<<"Insertion successful!"<<endl;
        }
    }
}

template <class T>
int MyLinkedList<T>::size()
{
    if (isEmpty())
        return 0;
    int sz = 0; 
    struct Node<T> *temp = this->head;
    for (sz; temp != nullptr; sz++)
        temp = temp->next;
    return sz;
}

template <class T>
T MyLinkedList<T>::mid()
{
    if (isEmpty())
    {
        cout << "Invalid Operation!" << endl;
        return 0;
    }
    int sz = size();
    struct Node<T> *temp = this->head;
    for (int i = 0; i < sz/2; i++)
        temp = temp->next;
    T value = temp->data;
    return value;
}

template <class T>
T MyLinkedList<T>::peekPos(int pos)
{
    int sz = size();
    
    if (isEmpty() || pos < 0 || pos >= sz)
    {
        cout << "Invalid Operation!" << endl;
        return 0;  
    }
    
    if (pos == 0)
        return this->head->data;
    
    if (pos == sz-1)
        return this->tail->data;
    
    struct Node<T> *temp = this->head;
    for (int i = 0; i < pos; i++)
        temp = temp->next;
    
    return temp->data;
}


template <class T>
void MyLinkedList<T>::isPalindrome()
{
    if (isEmpty())
    {
        cout << "Invalid Operation!" << endl;
        return;
    }

    bool flag = true;
    int i = 0, j = size() - 1;

    while (i < j)
    {
        T v1 = peekPos(i), v2 = peekPos(j);
        if (v1 != v2)
        {
            flag = false;
            break;
        }
        i++;
        j--;
    }

    if (flag)
        cout << "Word is palindrome!" << endl;
    else
        cout << "This word is not palindrome!" << endl;
}

template <class T>
void MyLinkedList<T>::removeDuplicates()
{
    if (isEmpty())
    {
        cout << "Invalid Operation!" << endl;
        return ;
    }
    int sz = size();
    for (int i = 0; i < sz; i++)
        for (int j = i+1; j < sz; j++)
        {
            T v1 = peekPos(i);
            T v2 = peekPos(j);
            if (v1 == v2)
            {
                deleteValue(v2);
                sz--;
            }
        }
}

template <class T>
Node<T> * MyLinkedList<T>::reverseList(Node<T> *node)
{
    if (!node || !node->next)
        return node;
    Node<T>* newHead = reverseList(node->next);
    node->next->next = node;
    node->next = nullptr;
    return newHead;
}

template <class T>
void MyLinkedList<T>::reverse()
{
    this->head = reverseList(this->head);
}

template <class T>
int MyLinkedList<T>::length(Node<T>* node) 
{
    if (node == nullptr)
        return 0;
    return 1 + length(node->next);
}

template <class T>
int MyLinkedList<T>::getLength() 
{
    return length(this->head);
}