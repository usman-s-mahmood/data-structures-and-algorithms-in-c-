#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

class LinkedList
{
    protected:
        struct Node *head = new struct Node;
        struct Node *tail = new struct Node;
    public:
        LinkedList();
        virtual void insertAtTail(int value) = 0;
        virtual void insertAtHead(int value) = 0;
        ~LinkedList()
        {
            delete head;
            delete tail;
        }
};

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}