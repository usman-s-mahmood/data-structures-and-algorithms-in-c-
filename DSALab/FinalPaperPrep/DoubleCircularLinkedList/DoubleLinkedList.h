#include <iostream>
#include <string>
#include <cmath>

using namespace std;

template <class T>
struct Node
{
    T data;
    struct Node<T> *prev, *next;
};

template <class T>
class DoubleLinkedList
{
    protected:
        struct Node<T> *head;
        struct Node<T> *tail;
    public:
        DoubleLinkedList();
        virtual void insertAtHead(T) = 0;
        virtual void insertAtTail(T) = 0;
        virtual T deleteFromHead() = 0;
        virtual T deleteFromTail() = 0;
        virtual void display() = 0;
        ~DoubleLinkedList();
};

template <class T>
DoubleLinkedList<T>::DoubleLinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
}

template <class T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
    delete this->head;
    delete this->tail;
}