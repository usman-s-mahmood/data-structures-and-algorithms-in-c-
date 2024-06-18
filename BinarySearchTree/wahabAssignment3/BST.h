#include "Tree.h"
#include <vector>
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
        int heightOfTree(Node<T>* root);
        bool isBalanced(Node<T>* root);
        bool areIdentical(Node<T>* root1, Node<T>* root2);
        int distanceBetweenNodes(Node<T>* root, int node1, int node2);
        int depth(Node<T>* root, int val);
        void inorderTraversal(Node<T>* root, vector<int>& result);
        vector<int> sortedArrayFromBST(Node<T>* root);
        bool isValidBST(Node<T>* root);
        bool isValidBSTUtil(Node<T>* root, long long minVal, long long maxVal);
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
template <class T>
int BinarySearchTree<T>::heightOfTree(Node<T>* root) {
    if (root == nullptr)
        return 0;
    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);
    return 1 + max(leftHeight, rightHeight);
}
template <class T>
bool BinarySearchTree<T>::isBalanced(Node<T>* root) {
    if (root == nullptr)
        return true;
    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);
    return abs(leftHeight - rightHeight) <= 1 &&
           isBalanced(root->left) &&
           isBalanced(root->right);
}
template <class T>
bool BinarySearchTree<T>::areIdentical(Node<T>* root1, Node<T>* root2) {
    if (root1 == nullptr && root2 == nullptr)
        return true;
    if (root1 == nullptr || root2 == nullptr)
        return false;
    return (root1->data == root2->data) &&
           areIdentical(root1->left, root2->left) &&
           areIdentical(root1->right, root2->right);
}
template <class T>
int BinarySearchTree<T>::distanceBetweenNodes(Node<T>* root, int node1, int node2) {
    if (root == nullptr)
        return 0;
    if (root->data > node1 && root->data > node2)
        return distanceBetweenNodes(root->left, node1, node2);
    if (root->data < node1 && root->data < node2)
        return distanceBetweenNodes(root->right, node1, node2);
    if (root->data >= node1 && root->data <= node2)
        return depth(root, node1) + depth(root, node2);
}
template <class T>
int BinarySearchTree<T>::depth(Node<T>* root, int val) {
    if (root == nullptr)
        return 0;
    if (root->data == val)
        return 0;
    else if (root->data > val)
        return 1 + depth(root->left, val);
    else
        return 1 + depth(root->right, val);
}
template <class T>
void BinarySearchTree<T>::inorderTraversal(Node<T>* root, vector<int>& result) {
    if (root == nullptr)
        return;
    inorderTraversal(root->left, result);
    result.push_back(root->data);
    inorderTraversal(root->right, result);
}
template <class T>
vector<int> BinarySearchTree<T>::sortedArrayFromBST(Node<T>* root) {
    vector<int> result;
    inorderTraversal(root, result);
    return result;
}
template <class T>
bool BinarySearchTree<T>::isValidBST(Node<T>* root) {
    return isValidBSTUtil(root, LONG_MIN, LONG_MAX);
}
template <class T>
bool BinarySearchTree<T>::isValidBSTUtil(Node<T>* root, long long minVal, long long maxVal) {
    if (root == nullptr)
        return true;
    if (root->data <= minVal || root->data >= maxVal)
        return false;
    return isValidBSTUtil(root->left, minVal, root->data) && 
           isValidBSTUtil(root->right, root->data, maxVal);
}

