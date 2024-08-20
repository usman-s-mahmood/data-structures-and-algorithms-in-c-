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
        virtual void insert(T) = 0;
        virtual bool remove(T) = 0;
        // virtual void inorder() = 0;
        // virtual void preorder() = 0;
        // virtual void postorder() = 0;
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
    // delete this->root;
}