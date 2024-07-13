#include "Tree.h"

template <class T>
class BinarySearchTree: public Tree<T>
{
    protected:
        void search_pro(struct Node<T> *root, T value, bool &check);
        void inorder_pro(struct Node<T> *root);
        void preorder_pro(struct Node<T> *root);
        void postorder_pro(struct Node<T> *root);
    public:
        BinarySearchTree();
        void insertNode(T);
        bool deleteNode(T);
        bool search(T);
        void inorder();
        void preorder();
        void postorder();
        bool isEmpty();
        ~BinarySearchTree();
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
void BinarySearchTree<T>::insertNode(T value)
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
                    break ;
                }
                else
                    temp = temp->left;
            }
            else
            {
                if (temp->right == nullptr)
                {
                    temp->right = node;
                    break ;
                }
                else
                    temp = temp->right;
            }
        }
    }
}

template <class T>
void BinarySearchTree<T>::inorder_pro(struct Node<T> *root)
{
    if (root != nullptr)
    {
        inorder_pro(root->left);
        cout << root->data << ' ';
        inorder_pro(root->right);
    }
}

template <class T>
void BinarySearchTree<T>::inorder()
{
    if (!isEmpty())
    {
        inorder_pro(this->root);
        cout << endl;
        return ;
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return ;
}

template <class T>
void BinarySearchTree<T>::preorder_pro(struct Node<T> *root)
{
    if (root != nullptr)
    {
        cout << root->data << ' ';
        preorder_pro(root->left);
        preorder_pro(root->right);
    }
}

template <class T>
void BinarySearchTree<T>::preorder()
{
    if (!isEmpty())
    {
        preorder_pro(this->root);
        cout << endl;
        return ;
    }
    cout << "Invalid Operation! Tree is Empty" << endl;
    return ;
}

template <class T>
void BinarySearchTree<T>::postorder_pro(struct Node<T> *root)
{
    if (root != nullptr)
    {
        postorder_pro(root->left);
        postorder_pro(root->right);
        cout << root->data << ' ';
    }
}

template <class T>
void BinarySearchTree<T>::postorder()
{
    if (!isEmpty())
    {
        postorder_pro(this->root);
        cout << endl;
        return ;
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return ;
}

template <class T>
void BinarySearchTree<T>::search_pro(struct Node<T> *root, T value, bool &check)
{
    if (root != nullptr)
    {
        search_pro(root->left, value, check);
        if (root->data == value)
        {
            check = true;
            return ;
        }
        search_pro(root->right, value, check);
    }
}

template <class T>
bool BinarySearchTree<T>::search(T value)
{
    if (!isEmpty())
    {
        bool check = false;
        search_pro(this->root, value, check);
        if (check)
        {
            cout << "Value found in the tree!" << endl;
            return true;
        }
        cout << "Value does not exist in the tree!" << endl;
        return false;
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return false;
}

template <class T>
bool BinarySearchTree<T>::deleteNode(T value)
{
    if (!isEmpty())
    {
        if (search(value))
        {
            // root node case
            // leaf node case
            // node with one child
            // node with two children
            return true;
        }
        return false;
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return false;
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
    Tree<T>::~Tree();
}