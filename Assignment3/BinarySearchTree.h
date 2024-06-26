#include "Tree.h"

template <class T>
class BinarySearchTree: public Tree<T>
{
    protected:
        void preOrderPro(struct Node<T> *root);
        void inOrderPro(struct Node<T> *root);
        void postOrderPro(struct Node<T> *root);
        void tree_size(struct Node<T> *root, T &ref);
        void convert_to_array(struct Node<T> *root, T *arr, int &itr);
        void search_pro(struct Node<T> *root, bool &check, T value);
    public:
        BinarySearchTree();
        void insert(T);
        void preOrder();
        void inorder();
        void postOrder();
        bool isEmpty();
        T pop_inorder();
        void arrayFun();
        bool deleteNode(T);
        bool search(T);
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

template <class T>
T BinarySearchTree<T>::pop_inorder()
{
    if(!isEmpty())
    {
        T ref = 0;
        // pop_inorder_pro(this->root, ref);
        return ref;
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return 0;
}

template <class T>
void BinarySearchTree<T>::tree_size(struct Node<T> *root, T &ref)
{
    if (root != nullptr)
    {
        tree_size(root->left, ref);
        ref += 1;
        tree_size(root->right, ref);
    }
}

template <class T>
void BinarySearchTree<T>::convert_to_array(struct Node<T> *root, T *arr, int &itr)
{
    if (root != nullptr)
    {
        
        convert_to_array(root->left, arr, itr);
        arr[itr] = root->data;
        itr+=1;
        convert_to_array(root->right, arr, itr);
    }
}

template <class T>
void BinarySearchTree<T>::arrayFun()
{
    int size = 0;
    tree_size(this->root, size);
    cout << "Size of Tree is: " << size << endl;
    T arr[size] = {0};
    int itr = 0;
    convert_to_array(this->root, arr, itr);
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << endl;
    // done to perfection with all the algorithm working fine as expected!
}

template <class T>
void BinarySearchTree<T>::search_pro(struct Node<T> *root, bool &check, T value)
{
    if (root != nullptr)
    {
        search_pro(root->left, check, value);
        if (root->data == value)
        {
            check = true;
            return ;
        }
        search_pro(root->right, check, value);
    }
}

template <class T>
bool BinarySearchTree<T>::search(T value)
{
    if (isEmpty())
    {
        cout << "Invalid Operation! Tree is empty" << endl;
        return false;
    }
    bool check = false;
    search_pro(this->root, check, value);
    if (check)
    {
        cout << "Value found in the tree" << endl;
        return true;
    }
    cout << "Value is not present in the tree" << endl;
    return false;
}

template <class T>
bool BinarySearchTree<T>::deleteNode(T value)
{
    if (!isEmpty())
    {
        if (search(value))
        {
            // leaf node case
            // node with one child case
            // node with two children case
        }
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return false;
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