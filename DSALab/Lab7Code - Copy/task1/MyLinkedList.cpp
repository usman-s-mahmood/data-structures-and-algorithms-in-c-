#include "MyLinkedList.h"

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
void MyLinkedList<T>::insertAtHead(T data)
{
    Node<T> *node = new Node<T>;
    node->data = data;
    if (isEmpty())
        this->head = this->tail = node;
    else
    {
        if (this->head == this->tail)
        {
            node->next = this->head;
            this->head = node;
        }
        else
        {
            node->next = this->head;
            this->head = node;
        }
    }
}

template <class T>
T MyLinkedList<T>::deleteFromHead()
{
    if(isEmpty())
    {
        cout<<"Deletion Not possible!"<<endl;
        return -1;
    }
    else
    {
        if (this->head == this->tail)
        {
            T value = this->head->data;
            delete this->head;
            this->head = this->tail = nullptr;
            return value;
        }
        else
        {
            T value = this->head->data;
            Node<T> *ptr = this->head;
            this->head = this->head->next;
            delete ptr;
            return value;
        }
    }
}

template <class T>
void MyLinkedList<T>::insertAtTail(T data)
{
    Node<T> *node = new Node<T>;
    node->data = data;
    if(isEmpty())
        this->head = this->tail = node;
    else
    {
        if (this->head == this->tail)
        {
            this->tail->next = node;
            node->next = nullptr;
            this->tail = node;
        }
        else
        {
            this->tail->next = node;
            node->next = nullptr;
            this->tail = node;
        }
    }
}

template <class T>
T MyLinkedList<T>::deleteFromTail()
{
    if (isEmpty())
    {
        cout<<"Deletion not possible"<<endl;
        return -1;
    }
    else
    {
        if (this->head == this->tail)
        {
            T value = this->tail->data;
            delete this->tail;
            this->head = this->tail = nullptr;
            return value;
        }
        else
        {
            T value = this->tail->data;
            Node<T> *ptr = this->head;
            while (true)
            {
                if (ptr->next == this->tail)
                    break;
                ptr = ptr->next;
            }
            ptr->next = nullptr;
            delete this->tail;
            this->tail = ptr;
            return value;
        }
    }
}

template <class T>
void MyLinkedList<T>::display()
{
    if (isEmpty())
    {
        cout<<"No values to display!"<<endl;
        return ;
    }
    else
    {
        Node<T> *ptr = this->head;
        while(ptr != nullptr)
        {
            cout<<ptr->data<<' ';
            ptr = ptr->next;
        }
        cout<<endl;
    }
}
