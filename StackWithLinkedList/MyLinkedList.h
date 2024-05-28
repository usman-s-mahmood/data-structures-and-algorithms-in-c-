#include "LinkedList.h"

class MyLinkedList: public LinkedList
{
    public:
        MyLinkedList();
        void insertAtTail(int value);
        void insertAtHead(int value);
        void insertAtValue(int target, int value);
        void insertAfterValue(int target, int value);
        void insertBeforeValue(int target, int value);
        int deleteAtHead();
        int deleteAtTail();
        int deleteValue(int value);
        void display();
        bool isEmpty();
        void search(int value);
        int tailValue();
        ~MyLinkedList(){}
};

MyLinkedList::MyLinkedList():
    LinkedList::LinkedList()
{}

bool MyLinkedList::isEmpty()
{
    return (this->head == nullptr && this->tail == nullptr);
}

void MyLinkedList::insertAtTail(int value)
{
    struct Node *ptr = new struct Node;
    ptr->data = value;
    ptr->next = nullptr;
    if (isEmpty())
        head = tail = ptr;
    else
    {
        tail->next = ptr;
        tail = ptr;
    }
}

void MyLinkedList::insertAtHead(int value)
{
    struct Node *ptr = new struct Node;
    ptr->data = value;
    ptr->next = nullptr;
    if (isEmpty())
        head = tail = ptr;
    else
    {
        ptr->next = head;
        head = ptr;
    }
}

void MyLinkedList::display()
{
    if(isEmpty())
    {
        cout<<"Linked list is empty!"<<endl;
        return ;
    }
    struct Node *temp = head;
    while (temp != nullptr)
    {
        cout<<temp->data<<' ';
        temp = temp->next;
    }
    cout<<endl;
}

int MyLinkedList::deleteAtHead()
{
    if (isEmpty())
    {
        cout<<"Empty linked list has not values for deletion!"<<endl;
        return -1;
    }
    int value = head->data;
    struct Node *ptr = head;
    head = ptr->next;
    delete ptr;
    return value;
}

int MyLinkedList::deleteAtTail()
{
    if (isEmpty())
    {
        cout<<"Empty linked list has not values for deletion!"<<endl;
        return -1;
    }
    struct Node *ptr = head;
    while (ptr->next != tail)
        ptr = ptr->next;
    int value = tail->data;
    struct Node *temp = ptr->next;
    delete temp;
    ptr->next = nullptr;
    tail = ptr;
    return value;
    
}

void MyLinkedList::search(int value)
{
    if (isEmpty())
    {
        cout<<"Empty linked list has no values for searching"<<endl;
        return;
    }
    else if(head->data == value)
        cout<<"Value found at head: "<<head->data<<endl;
    else if(tail->data == value)
        cout<<"Value found at tail: "<<tail->data<<endl;
    else
    {
        struct Node *ptr = head;
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

int MyLinkedList::deleteValue(int value)
{
    // 1. value is not in the list 2. value is at head 3. value is at tail 4. value is somewhere in the middle of list 5. List is empty
    if (isEmpty())
    {
        cout<<"List is empty!"<<endl;
        return -1;
    }
    else if (head->data == value)
        deleteAtHead();
    else if (tail->data == value)
        deleteAtTail();
    else
    {
        struct Node *ptr1 = head;
        struct Node *ptr2 = ptr1->next;
        while(ptr2->data != value)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        if (ptr2 != nullptr)
        {
            int value = ptr2->data;
            ptr1->next = ptr2->next;
            delete ptr2;
            return value;
        }
        else
        {
            cout<<"Value not found in the list!"<<endl;
            return -1;
        }
    }
    return -1;
}

void MyLinkedList::insertAtValue(int target, int value)
{
    // 1. target is at head 2. target is at tail 3. target is not in the list 4. list is empty 5. target is in the middle of list
    if (isEmpty())
    {
        cout<<"Empty list does not contain target value"<<endl;
        return ;
    }
    else if (head->data == target)
        insertAtHead(value);
    else if (tail->data == target)
        insertAtTail(value);
    else
    {
        struct Node *ptr1 = head;
        struct Node *ptr2 = head->next;
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
            struct Node *node = new struct Node;
            node->data = value;
            ptr1->next = node;
            node->next = ptr2;
            cout<<"Value inserted successfully!"<<endl;
        }
    }
}

void MyLinkedList::insertAfterValue(int target, int value)
{
    if (isEmpty())
        cout<<"Linked list is empty!"<<endl;
    else if (head->data == target)
    {
        cout<<true<<endl;
        struct Node *node = new struct Node;
        node->data = value;
        node->next = head->next;
        head->next = node;
    }
    else if(tail->data == target)
    {
        struct Node *node = new struct Node;
        node->data = value;
        tail->next = node;
        node->next = nullptr;
        tail = node;
    }
    else
    {
        struct Node *ptr1 = head;
        struct Node *ptr2 = head->next;
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
            struct Node *node = new struct Node;
            node->data = value;
            ptr1->next = node;
            node->next = ptr2;
        }
    }
}

void MyLinkedList::insertBeforeValue(int target, int value)
{
    if (head->data == target)
    {
        struct Node *node = new struct Node;
        node->data = value;
        node->next = head;
        head = node;
    }
    else if (tail->data == target)
    {
        struct Node *node = new struct Node;
        node->data = value;
        struct Node *ptr1 = head;
        struct Node *ptr2 = head->next;
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
        struct Node *ptr1 = head;
        struct Node *ptr2 = head->next;
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
            struct Node *node = new struct Node;
            node->data = value;
            ptr1->next = node;
            node->next = ptr2;
            cout<<"Insertion successful!"<<endl;
        }
    }
}

int MyLinkedList::tailValue()
{
    if (isEmpty())
    {
        cout<<"No values are in the linked list!"<<endl;
        return -1;
    }
    int value = this->tail->data;
    return value;
}