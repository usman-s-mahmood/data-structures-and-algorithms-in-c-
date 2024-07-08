#include "Tree.h"

template <class T>
class BinarySearchTree : public Tree<T>
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
BinarySearchTree<T>::BinarySearchTree() : Tree<T>::Tree()
{
}

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
        return;
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return;
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
        return;
    }
    cout << "Invalid Operation! Tree is Empty" << endl;
    return;
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
        return;
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return;
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
            return;
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
            Node<T> *p = this->root;
            Node<T> *c = this->root;
            while (true)
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

                if (c == nullptr)
                    return false;

                if (c->data == value)
                    break;
            }

            cout << "p->data = " << p->data << endl;
            cout << "c->data = " << c->data << endl;

            if (c->left != nullptr && c->right != nullptr) // 2 children case
            {
                Node<T> *t = c;
                c = c->right;
                p = t;

                while (1)
                {
                    if (c->left == nullptr)
                        break;

                    p = c;
                    c = c->left;
                }

                t->data = c->data;
                value = c->data;
            }

            if (c->left == nullptr && c->right == nullptr) // leaf node
            {
                if (c->data < p->data) // left child of parent
                {
                    delete c;
                    c = nullptr;
                    p->left = nullptr;
                }

                else // right child of the parent
                {
                    delete c;
                    c = nullptr;
                    p->right = nullptr;
                }

                return true;
            }

            else if (c->left == nullptr && c->right != nullptr) // single child case 1
            {
                if (c->data < p->data) // left child of parent
                {
                    p->left = c->right;
                    delete c;
                    c = nullptr;
                }

                else // right child of parent
                {
                    p->right = c->right;
                    delete c;
                    c = nullptr;
                }

                return true;
            }

            else if (c->left != nullptr && c->right == nullptr) // single child case 2
            {
                if (c->data < p->data) // left child of parent
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
        return false;
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return false;
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
    // Tree<T>::~Tree();
}