#include "Node.h"

template <class T>
class LinkedList
{
    protected:
        struct Node<T> *head;
    public:
        LinkedList();
        virtual void insertAtHead(T value) = 0;
        virtual void display() = 0;
        virtual T deleteFromHead() = 0;
        virtual void insertAtTail(T value) = 0;
        virtual T deleteFromTail() = 0;
        virtual void deleteValue(T value) = 0;
        virtual void search(T value) = 0;
        virtual void insertSorted(T value) = 0;
        ~LinkedList(){}
};

template <class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
}