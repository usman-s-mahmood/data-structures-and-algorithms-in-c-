#include "LinkedList.h"

class MyLinkedList: public LinkedList
{
    public:
        MyLinkedList();
        void insertAtTail(int value);
        void insertAtHead(int value);
        int deleteAtHead();
        int deleteAtTail();
        int deleteValue(int value);
        void display();
        bool isEmpty();
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