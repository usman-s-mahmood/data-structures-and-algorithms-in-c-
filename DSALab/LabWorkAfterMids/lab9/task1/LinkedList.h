#include <iostream>
#include <string>
#include <cmath>

using namespace std;

template <class T>
struct Node
{
    T data;
    struct Node<T> *next;
};

template <class T>
class LinkedList
{
    protected:
        struct Node<T> *head;
        struct Node<T> *tail;
    public:
        LinkedList();
        virtual void insertAtHead(T) = 0;
        virtual void insertAtTail(T) = 0;
        virtual T deleteFromHead() = 0;
        virtual T deleteFromTail() = 0;
        virtual void convertList()=0; // convert singly linked list into circular linked list
        virtual T printNthFromLast(int n)=0; // return value at the nth node from the end of the linkedlist
        virtual void sortList()=0; // sort a linkedlist of 0s, 1s and 2s 
        ~LinkedList(){}

};

template <class T>
LinkedList<T>::LinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
}