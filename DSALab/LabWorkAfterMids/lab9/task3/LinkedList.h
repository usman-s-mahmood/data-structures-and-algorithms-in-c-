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
        virtual bool checkPalindrome()=0; // check if the linkedlist is palindrome or not  
        // virtual void rotateByNnodes(int pos)=0; // rotate doubly linked list by N nodes 
        ~LinkedList(){}

};

template <class T>
LinkedList<T>::LinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
}