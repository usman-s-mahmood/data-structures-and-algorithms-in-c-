#include "Node.h"

template <class T>
class LinkedList
{
    protected:
        struct Node<T> *head;
        struct Node<T> *tail;
    public:
        LinkedList();
        virtual void insertAtHead(T data) = 0;
        virtual T deleteFromHead() = 0;
        virtual void insertAtTail(T data) = 0;
        virtual T deleteFromTail() = 0;
        virtual bool isEmpty() = 0;
        virtual void display() = 0;
        ~LinkedList()
        {
            delete head;
            delete tail;
        }
};

