#include <iostream>
#include <stdexcept>

using namespace std;

template <class T>
struct Node
{
    T data;
    Node<T> *prev;
    Node<T> *next;
};

template <class T>
class DoubleLinkedList
{
public:
    Node<T> *head;
    Node<T> *tail;
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}
    ~DoubleLinkedList(){}
    virtual void insertAtHead(T value) = 0;
    virtual void insertAtTail(T value) = 0;
    virtual T deleteFromHead() = 0;
    virtual T deleteFromTail() = 0;
    virtual bool isEmpty() = 0;
    virtual bool search(T value) = 0;
    virtual void display() = 0;
};

template <class T>
class MyDoubleLinkedList : public DoubleLinkedList<T>
{
public:
    MyDoubleLinkedList() : DoubleLinkedList<T>() {}
    void insertAtHead(T value) override;
    void insertAtTail(T value) override;
    T deleteFromHead() override;
    T deleteFromTail() override;
    bool isEmpty() override;
    bool search(T value) override;
    void display() override;
    ~MyDoubleLinkedList()
    {
        while(!isEmpty())
            deleteFromHead();
        delete this->head;
        delete this->tail;
    }
};

template <class T>
void MyDoubleLinkedList<T>::insertAtHead(T value)
{
    Node<T> *node = new Node<T>;
    node->data = value;
    node->prev = nullptr;
    node->next = nullptr;
    if (this->isEmpty())
    {
        this->head = node;
        this->tail = node;
    }
    else
    {
        node->next = this->head;
        this->head->prev = node;
        this->head = node;
    }
}

template <class T>
void MyDoubleLinkedList<T>::insertAtTail(T value)
{
    Node<T> *node = new Node<T>;
    node->data = value;
    node->prev = nullptr;
    node->next = nullptr;
    if (this->isEmpty())
    {
        this->head = node;
        this->tail = node;
    }
    else
    {
        this->tail->next = node;
        node->prev = this->tail;
        this->tail = node;
    }
}

template <class T>
T MyDoubleLinkedList<T>::deleteFromHead()
{
    if (this->isEmpty())
    {
        throw runtime_error("No value to return");
    }
    T value = this->head->data;
    Node<T> *del = this->head;
    if (this->head == this->tail)
    {
        this->head = this->tail = nullptr;
    }
    else
    {
        this->head = this->head->next;
        if (this->head)
            this->head->prev = nullptr;
    }
    delete del;
    return value;
}

template <class T>
T MyDoubleLinkedList<T>::deleteFromTail()
{
    if (this->isEmpty())
    {
        throw runtime_error("No value for deletion!");
    }
    T value = this->tail->data;
    Node<T> *del = this->tail;
    if (this->head == this->tail)
    {
        this->head = this->tail = nullptr;
    }
    else
    {
        this->tail = this->tail->prev;
        if (this->tail)
            this->tail->next = nullptr;
    }
    delete del;
    return value;
}

template <class T>
bool MyDoubleLinkedList<T>::search(T value)
{
    Node<T> *temp = this->head;
    while (temp != nullptr)
    {
        if (temp->data == value)
            return true;
        temp = temp->next;
    }
    return false;
}

template <class T>
bool MyDoubleLinkedList<T>::isEmpty()
{
    return (this->head == nullptr && this->tail == nullptr);
}

template <class T>
void MyDoubleLinkedList<T>::display()
{
    if (isEmpty())
    {
        cout << "Empty Linked List has no values to display" << endl;
        return;
    }
    Node<T> *temp = this->head;
    while (temp != nullptr)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << endl;
    cout << "Reversed Linked List: " << endl;
    Node<T> *tempTail = this->tail;
    while (tempTail != nullptr)
    {
        cout << tempTail->data << ' ';
        tempTail = tempTail->prev;
    }
    cout << endl;
}

int main()
{
    MyDoubleLinkedList<int> obj;
    obj.insertAtHead(12);
    obj.insertAtTail(9);
    obj.display();
    return 0;
}
