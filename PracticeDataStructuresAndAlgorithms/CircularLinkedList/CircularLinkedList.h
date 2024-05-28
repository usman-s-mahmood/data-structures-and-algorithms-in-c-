#include "LinkedList.h"

template <class T>
class CircularLinkedList: public LinkedList<T>
{
    public:
        CircularLinkedList();
        void insertAtHead(T);
        void insertAtTail(T);
        T deleteFromHead();
        T deleteFromTail();
        bool isEmpty();
        void display();
        void insertSorted(T);
        ~CircularLinkedList(){}
};