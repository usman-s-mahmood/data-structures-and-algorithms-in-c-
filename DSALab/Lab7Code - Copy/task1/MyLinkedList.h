#include "LinkedList.cpp"

template <class T>
class MyLinkedList: public LinkedList<T>
{
    public:
        MyLinkedList();
        void insertAtHead(T data);
        T deleteFromHead();
        void insertAtTail(T data);
        T deleteFromTail();
        bool isEmpty();
        void display();
        ~MyLinkedList(){}
};