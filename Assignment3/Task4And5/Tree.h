#include <iostream>
#include <string>
#include <cmath>

using namespace std;

template <class T>
struct RBNode
{
    T data;
    struct RBNode<T> *leftChild;
    struct RBNode<T> *rightChild;
    struct RBNode<T> *parent;
    char color;
};

template <class T>
class Tree
{
    protected:
        struct RBNode<T> *root;
    public:
        Tree();
        virtual void insertNode(T) = 0;
        virtual bool deleteNode(T) = 0;
        virtual void inOrder() = 0;
        virtual void preOrder() = 0;
        virtual void postOrder() = 0;
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
}