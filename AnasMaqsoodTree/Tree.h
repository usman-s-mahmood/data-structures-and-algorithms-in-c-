#include <iostream>
#include <string>
#include <cmath>

using namespace std;

template <class T>
struct Node
{
    T data;
    struct Node<T> *left;
    struct Node<T> *right;
};

template <class T>
class Tree
{
    protected:
        struct Node<T> *root;
    public:
        Tree();
        virtual void insert(T) = 0;
        ~Tree(){}
};

template <class T>
Tree<T>::Tree()
{
    this->root = nullptr;
}