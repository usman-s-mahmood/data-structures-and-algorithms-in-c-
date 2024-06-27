#include <iostream>
#include <string>
#include <cmath>

using namespace std;

template <class T>
struct LN_Node
{
    struct LN_Node<T> *prev;
    T data;
    struct LN_Node<T> *next;
};

template <class T>
class DoubleLinkedList
{
    protected:
        struct LN_Node<T> *head;
        struct LN_Node<T> *tail;
    public:
        DoubleLinkedList();
        virtual void insertAtHead(T) = 0;
        virtual void insertAtTail(T) = 0;
        virtual T deleteFromHead() = 0;
        virtual T deleteFromTail() = 0;
        ~DoubleLinkedList(){}
};

template <class T>
DoubleLinkedList<T>::DoubleLinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
}