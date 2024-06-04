#include <iostream>
#include <string>
#include <cmath>
#include <conio.h>
using namespace std;

template <class T>
struct Node
{
    T data;
    struct Node *next;
};

template <class T>
class LinkedList
{
    protected:
        struct Node<T> *head = new struct Node<T>;
        struct Node<T> *tail = new struct Node<T>;
    public:
        LinkedList();
        virtual void insertAtTail(T value) = 0;
        virtual void insertAtHead(T value) = 0;
        ~LinkedList()
        {
            delete head;
            delete tail;
        }
};

template <class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}