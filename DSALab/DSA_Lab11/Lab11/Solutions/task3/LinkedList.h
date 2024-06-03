#include <iostream>
#include <string>
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
        struct Node<T> *head;
        struct Node<T> *tail;
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