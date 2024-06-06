#include "Tree.h"

template <class T>
class BinarySearchTree: public Tree<T>
{
    protected:
        void preOrderPro(struct Node<T> *root);
        void inOrderPro(struct Node<T> *root);
        void postOrderPro(struct Node<T> *root);
    public:
        BinarySearchTree();
        void insert(T);
        void preOrder();
        void inorder();
        void postOrder();
        bool isEmpty();
        ~BinarySearchTree(){}
};

template <class T>
BinarySearchTree<T>::BinarySearchTree():
    Tree<T>::Tree()
{}

template <class T>
bool BinarySearchTree<T>::isEmpty()
{
    return (this->root == nullptr);
}

template <class T>
void BinarySearchTree<T>::inOrderPro(struct Node<T> *root)
{
    if (root != nullptr)
    {
        inOrderPro(root->left);
        cout << root->data << ' ';
        inOrderPro(root->right);
    }
}

template <class T>
void BinarySearchTree<T>::preOrderPro(struct Node<T> *root)
{
    if (root != nullptr)
    {
        cout << root->data << ' ';
        preOrderPro(root->left);
        preOrderPro(root->right);
    }
}

template <class T>
void BinarySearchTree<T>::postOrderPro(struct Node<T> *root)
{
    if (root != nullptr)
    {
        postOrderPro(root->left);
        postOrderPro(root->right);
        cout << root->data << ' ';
    }
}

template <class T>
void BinarySearchTree<T>::preOrder()
{
    preOrderPro(this->root);
    cout << endl;
}

template <class T>
void BinarySearchTree<T>::inorder()
{
    inOrderPro(this->root);
    cout << endl;
}

template <class T>
void BinarySearchTree<T>::postOrder()
{
    postOrderPro(this->root);
    cout << endl;
}

template <class T>
void BinarySearchTree<T>::insert(T value)
{
    struct Node<T> *node = new struct Node<T>;
    node->data = value;
    node->left = nullptr;
    node->right = nullptr;
    if (isEmpty())
        this->root = node;
    else
    {
        struct Node<T> *temp = this->root;
        while (true)
        {
            if (value < temp->data)
            {
                if (temp->left == nullptr)
                {
                    temp->left = node;
                    break;
                }
                else
                    temp = temp->left;
            }
            else
            {
                if (temp->right == nullptr)
                {
                    temp->right = node;
                    break;
                }
                else
                    temp = temp->right;
            }
        }
    }    
}
/*
template <class T>
void BinarySearchTree<T>::insert(T value)
{
    struct Node<T> *node = new struct Node;
    node->data = value;
    node->left = nullptr;
    node->right = nullptr;
    if (this->root == nullptr)
        this->root = node;
    else
    {
        struct Node<T> *temp = this->root;
        while (true)
        {
            if (value < temp->data)
            {
                if (temp->left == nullptr)
                {
                    temp->left = node;
                    break;
                }
                else
                    temp = temp->left;
            }
            else
            {
                if (temp->right == nullptr)
                {
                    temp->right = node;
                    break;
                }
                else
                    temp = temp->right;

            }
        }
    }
}
*/