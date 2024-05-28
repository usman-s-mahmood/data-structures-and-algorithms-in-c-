#include <iostream>
#include <string>
#include <cmath>

using namespace std;

template <class T>
struct Node
{
    struct Node<T> *prev;
    T data;
    struct Node<T> *next;
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
        virtual void deleteDuplicateNodes()=0; 
        virtual void swapNodes()=0; // swap head node with tail node
        ~DoubleLinkedList(){}
};

template <class T>
DoubleLinkedList<T>::DoubleLinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
}