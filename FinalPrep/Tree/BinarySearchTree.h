#include "Tree.h"

template <class T>
class BinarySearchTree: public Tree<T>
{
    protected:
        void inorder_pro(struct Node<T> *root);
        void preorder_pro(struct Node<T> *root);
        void postorder_pro(struct Node<T> *root);
        void search_pro(struct Node<T> *root, T value, bool &check);
        void max_value(struct Node<T> *root, T &max);
        void min_value(struct Node<T> *root, T &min);
    public:
        BinarySearchTree();
        void insert(T);
        bool remove(T);
        void inorder();
        void preorder();
        void postorder();
        bool search(T);
        bool isEmpty();
        T minimum();
        T maximum();
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
void BinarySearchTree<T>::insert(T value)
{
    struct Node<T> *node = new struct Node<T>;
    node->data = value;
    node->left = nullptr;
    node->right = nullptr;
    if (isEmpty())
        this->root = node;
    // else if (search(value))
    //     cout << "Invalid Operation! Binary Search Tree can't have duplicate values" << endl;
    else
    {
        struct Node<T> *temp = this->root;
        while(true)
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
void BinarySearchTree<T>::search_pro(struct Node<T> *root, T value, bool &check)
{
    if (root != nullptr)
    {
        if (root->data == value)
        {
            check = true;
            return ;
        }
        search_pro(this->root->left, value, check);
        search_pro(this->root->right, value, check);
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
            cout << "Value found in the Tree!" << endl;
            return true;
        }
        cout << "Value not found in the Tree!" << endl;
        return false;
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return false;
}

template <class T>
void BinarySearchTree<T>::inorder_pro(struct Node<T> *root)
{
    if (root != nullptr)
    {
        inorder_pro(root->left);
        cout << root->data <<' ';
        inorder_pro(root->right);
    }
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
void BinarySearchTree<T>::min_value(struct Node<T> *root, T &min)
{
    if (root->left != nullptr)
        min_value(root->left, min);
    else
    {
        min = root->data;
        return ;
    }
}

template <class T>
void BinarySearchTree<T>::max_value(struct Node<T> *root, T &max)
{
    if (root->right != nullptr)
        max_value(root->right, max);
    else
    {
        max = root->data;
        return ;
    }
}

template <class T>
T BinarySearchTree<T>::minimum()
{
    if (!isEmpty())
    {
        T min = T();
        min_value(this->root, min);
        return min;
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return T();
}

template <class T>
T BinarySearchTree<T>::maximum()
{
    if (!isEmpty())
    {
        T max = T();
        max_value(this->root, max);
        return max;
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return T();
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
    cout << "Invalid Operation! Tree is empty" << endl;
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
}

template <class T>
bool BinarySearchTree<T>::remove(T value)
{
    if (!isEmpty())
    {
        if (search(value))
        {
            if (this->root->data == value && this->root->left == nullptr && this->root->right == nullptr)
            {
                delete this->root;
                this->root = nullptr;
                return true;
            }
            if (this->root->data == value)
            {
                T new_root = T();
                new_root = minimum();
                struct Node<T> *temp = this->root;
                while (temp->left != nullptr)
                    temp = temp->left;
                delete temp;
                temp = nullptr;
                this->root->data = new_root;
                return true;
            }
            else
            {
                // case for leaf node
                struct Node<T> *p = this->root;
                struct Node<T> *c = this->root;
                while (c->data != value)
                {
                    if (value < c->data)
                    {
                        p = c;
                        c = c->left;
                    }
                    else
                    {
                        p = c;
                        c = c->right;
                    }
                }
                if (c->data == value && c->left != nullptr && c->right != nullptr)
                {
                    struct Node<T> *temp = c;
                    c = c->right;
                    p = temp;
                    while (true)
                    {
                        if (c->left == nullptr)
                            break;
                        p = c;
                        c = c->left;
                    }
                    temp->data = c->data;
                    value = c->data;
                }
                else if (c->data == value && c->left == nullptr && c->right == nullptr)
                {
                    if (c->data < p->data) // leaf node is left child
                    {
                        delete c;
                        c = nullptr;
                        p->left = nullptr;
                        return true;
                    }
                    else // leaf node is right child
                    {
                        delete c;
                        c = nullptr;
                        p->right = nullptr;
                        return true;
                    }
                }
                else if (c->data == value && c->left == nullptr && c->right != nullptr)
                {
                    if (c->data < p->data)
                    {
                        p->left = c->right;
                        delete c;
                        c = nullptr;
                    }
                    else
                    {
                        p->left = c->right;
                        delete c;
                        c = nullptr;
                    }
                    return true;
                }
                else if (c->data == value && c->left != nullptr && c->right == nullptr)
                {
                    if (c->data < p->data)
                    {
                        p->left = c->left;
                        delete c;
                        c = nullptr;
                    }
                    else
                    {
                        p->right = c->left;
                        delete c;
                        c = nullptr;
                    }
                    return true;
                }
            }
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