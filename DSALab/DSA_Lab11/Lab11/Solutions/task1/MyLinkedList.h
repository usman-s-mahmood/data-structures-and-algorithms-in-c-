#include "LinkedList.h"

template <class T>
class MyLinkedList: public LinkedList<T>
{
    public:
        MyLinkedList();
        void insertAtTail(T value);
        void insertAtHead(T value);
        void insertAtValue(T target, T value);
        void insertAfterValue(T target, T value);
        void insertBeforeValue(T target, T value);
        T deleteAtHead();
        T deleteAtTail();
        T deleteValue(T value);
        void display();
        bool isEmpty();
        void search(T value);
        void insertAtTailRecursive(T value);
        ~MyLinkedList(){}
        private:
            void insertAtTailRecursiveHelper(struct Node<T>* node, T value);
};

template <class T>
MyLinkedList<T>::MyLinkedList():
    LinkedList<T>::LinkedList()
{}

template <class T>
bool MyLinkedList<T>::isEmpty()
{
    return (this->head == nullptr && this->tail == nullptr);
}

template <class T>
void MyLinkedList<T>::insertAtTail(T value)
{
    struct Node<T> *ptr = new struct Node<T>;
    ptr->data = value;
    ptr->next = nullptr;
    if (isEmpty())
        this->head = this->tail = ptr;
    else
    {
        this->tail->next = ptr;
        this->tail = ptr;
    }
}

template <class T>
void MyLinkedList<T>::insertAtHead(T value)
{
    struct Node<T> *ptr = new struct Node<T>;
    ptr->data = value;
    ptr->next = nullptr;
    if (isEmpty())
        this->head = this->tail = ptr;
    else
    {
        ptr->next = this->head;
        this->head = ptr;
    }
}

template <class T>
void MyLinkedList<T>::display()
{
    if(isEmpty())
    {
        cout<<"Linked list is empty!"<<endl;
        return ;
    }
    struct Node<T> *temp = this->head;
    while (temp != nullptr)
    {
        cout<<temp->data<<' ';
        temp = temp->next;
    }
    cout<<endl;
}

template <class T>
T MyLinkedList<T>::deleteAtHead()
{
    if (isEmpty())
    {
        cout<<"Empty linked list has not values for deletion!"<<endl;
        return -1;
    }
    T value = this->head->data;
    struct Node<T> *ptr = this->head;
    this->head = ptr->next;
    delete ptr;
    return value;
}

template <class T>
T MyLinkedList<T>::deleteAtTail()
{
    if (isEmpty())
    {
        cout<<"Empty linked list has not values for deletion!"<<endl;
        return -1;
    }
    struct Node<T> *ptr = this->head;
    while (ptr->next != this->tail)
        ptr = ptr->next;
    T value = this->tail->data;
    struct Node<T> *temp = ptr->next;
    delete temp;
    ptr->next = nullptr;
    this->tail = ptr;
    return value;
    
}

template <class T>
void MyLinkedList<T>::search(T value)
{
    if (isEmpty())
    {
        cout<<"Empty linked list has no values for searching"<<endl;
        return;
    }
    else if(this->head->data == value)
        cout<<"Value found at head: "<<this->head->data<<endl;
    else if(this->tail->data == value)
        cout<<"Value found at tail: "<<this->tail->data<<endl;
    else
    {
        struct Node<T> *ptr = this->head;
        while(ptr != nullptr)
        {
            if(ptr->data == value)
            {
                cout<<"Value found in the linked list: "<<ptr->data<<endl;
                return ;
            }
            ptr = ptr->next;
        }
        cout<<"Value is not in the linked list!"<<endl;
    }
}

template <class T>
T MyLinkedList<T>::deleteValue(T value)
{
    // 1. value is not in the list 2. value is at head 3. value is at tail 4. value is somewhere in the middle of list 5. List is empty
    if (isEmpty())
    {
        cout<<"List is empty!"<<endl;
        return -1;
    }
    else if (this->head->data == value)
        deleteAtHead();
    else if (this->tail->data == value)
        deleteAtTail();
    else
    {
        struct Node<T> *ptr1 = this->head;
        struct Node<T> *ptr2 = ptr1->next;
        while(ptr2->data != value)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        if (ptr2 != nullptr)
        {
            T value = ptr2->data;
            ptr1->next = ptr2->next;
            delete ptr2;
            return value;
        }
        else
        {
            cout<<"Value not found in the list!"<<endl;
            return -1;
        }
    }
    return -1;
}

template <class T>
void MyLinkedList<T>::insertAtValue(T target, T value)
{
    // 1. target is at head 2. target is at tail 3. target is not in the list 4. list is empty 5. target is in the middle of list
    if (isEmpty())
    {
        cout<<"Empty list does not contain target value"<<endl;
        return ;
    }
    else if (this->head->data == target)
        insertAtHead(value);
    else if (this->tail->data == target)
        insertAtTail(value);
    else
    {
        struct Node<T> *ptr1 = this->head;
        struct Node<T> *ptr2 = this->head->next;
        while (ptr2->data != target)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            if (ptr2 == nullptr)
            {
                cout<<"target not present in the list"<<endl;
                return ;
            }
        }
        if (ptr2 != nullptr)
        {
            struct Node<T> *node = new struct Node<T>;
            node->data = value;
            ptr1->next = node;
            node->next = ptr2;
            cout<<"Value inserted successfully!"<<endl;
        }
    }
}

template <class T>
void MyLinkedList<T>::insertAfterValue(T target, T value)
{
    if (isEmpty())
        cout<<"Linked list is empty!"<<endl;
    else if (this->head->data == target)
    {
        cout<<true<<endl;
        struct Node<T> *node = new struct Node<T>;
        node->data = value;
        node->next = this->head->next;
        this->head->next = node;
    }
    else if(this->tail->data == target)
    {
        struct Node<T> *node = new struct Node<T>;
        node->data = value;
        this->tail->next = node;
        node->next = nullptr;
        this->tail = node;
    }
    else
    {
        struct Node<T> *ptr1 = this->head;
        struct Node<T> *ptr2 = this->head->next;
        while (ptr1->data != target)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            if (ptr2 == nullptr)
            {
                cout<<"Target node is not present in the list!"<<endl;
                return ;
            }
        }
        if (ptr1->data == target)
        {
            struct Node<T> *node = new struct Node<T>;
            node->data = value;
            ptr1->next = node;
            node->next = ptr2;
        }
    }
}

template <class T>
void MyLinkedList<T>::insertBeforeValue(T target, T value)
{
    if (this->head->data == target)
    {
        struct Node<T> *node = new struct Node<T>;
        node->data = value;
        node->next = this->head;
        this->head = node;
    }
    else if (this->tail->data == target)
    {
        struct Node<T> *node = new struct Node<T>;
        node->data = value;
        struct Node<T> *ptr1 = this->head;
        struct Node<T> *ptr2 = this->head->next;
        while (ptr2->next != nullptr)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        ptr1->next = node;
        node->next = ptr2;
    }
    else
    {
        struct Node<T> *ptr1 = this->head;
        struct Node<T> *ptr2 = this->head->next;
        while (ptr2->data != target)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            if (ptr2 == nullptr)
            {
                cout<<"Target value does not exist in the linked list!"<<endl;
                return ;
            }
        }
        if (ptr2->data == target)
        {
            struct Node<T> *node = new struct Node<T>;
            node->data = value;
            ptr1->next = node;
            node->next = ptr2;
            cout<<"Insertion successful!"<<endl;
        }
    }
}

template <class T>
void MyLinkedList<T>::insertAtTailRecursiveHelper(struct Node<T>* node, T value) 
{
    if (node->next == nullptr) 
    {
        struct Node<T>* newNode = new struct Node<T>;
        newNode->data = value;
        newNode->next = nullptr;
        node->next = newNode;
        this->tail = newNode;
    } 
    else 
        insertAtTailRecursiveHelper(node->next, value);
}

template <class T>
void MyLinkedList<T>::insertAtTailRecursive(T value) 
{
    if (isEmpty()) 
    {
        struct Node<T>* newNode = new struct Node<T>;
        newNode->data = value;
        newNode->next = nullptr;
        this->head = this->tail = newNode;
    } 
    else
        insertAtTailRecursiveHelper(this->head, value);
}
