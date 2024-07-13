<<<<<<< HEAD
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

template <class T>
struct Node
{
    T data;
    struct Node<T> *left, *right;
};

template <class T>
class Tree
{
    protected:
        struct Node<T> *root;
    public:
        Tree();
        virtual void insertNode(T) = 0;
        virtual bool deleteNode(T) = 0;
        ~Tree();
};

template <class T>
Tree<T>::Tree()
{
    this->root = nullptr;
}

template <class T>
Tree<T>::~Tree()
{
    delete this->root;
=======
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

template <class T>
struct Node
{
    T data;
    struct Node<T> *left, *right;
};

template <class T>
class Tree
{
    protected:
        struct Node<T> *root;
    public:
        Tree();
        virtual void insertNode(T) = 0;
        virtual bool deleteNode(T) = 0;
        ~Tree();
};

template <class T>
Tree<T>::Tree()
{
    this->root = nullptr;
}

template <class T>
Tree<T>::~Tree()
{
    delete this->root;
>>>>>>> 6b2f82d8e44f7796eed3207ffa1665bcdc1c3fed
}