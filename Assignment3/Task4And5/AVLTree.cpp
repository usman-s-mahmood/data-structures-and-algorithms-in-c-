#include "Tree.h"
#include <iostream>

using namespace std;

template <class T>
struct AVLNode
{
    T data;
    struct AVLNode<T> *leftChild;
    struct AVLNode<T> *rightChild;
    int height;

    AVLNode(T value)
    {
        data = value;
        leftChild = rightChild = nullptr;
        height = 1;
    }
};

template <class T>
class AVLTree : public Tree<T>
{
private:
    void INORDER(struct AVLNode<T> *root);
    int height(struct AVLNode<T> *node)
    {
        return node ? node->height : 0;
    }

    int getBalance(struct AVLNode<T> *node)
    {
        return node ? height(node->leftChild) - height(node->rightChild) : 0;
    }

    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    struct AVLNode<T>* rightRotate(struct AVLNode<T> *y)
    {
        struct AVLNode<T> *x = y->leftChild;
        struct AVLNode<T> *T2 = x->rightChild;

        x->rightChild = y;
        y->leftChild = T2;

        y->height = max(height(y->leftChild), height(y->rightChild)) + 1;
        x->height = max(height(x->leftChild), height(x->rightChild)) + 1;

        return x;
    }

    struct AVLNode<T>* leftRotate(struct AVLNode<T> *x)
    {
        struct AVLNode<T> *y = x->rightChild;
        struct AVLNode<T> *T2 = y->leftChild;

        y->leftChild = x;
        x->rightChild = T2;

        x->height = max(height(x->leftChild), height(x->rightChild)) + 1;
        y->height = max(height(y->leftChild), height(y->rightChild)) + 1;

        return y;
    }

    struct AVLNode<T>* insert(struct AVLNode<T> *node, T data)
    {
        if (!node)
            return new AVLNode<T>(data);

        if (data < node->data)
            node->leftChild = insert(node->leftChild, data);
        else if (data > node->data)
            node->rightChild = insert(node->rightChild, data);
        else
            return node;

        node->height = 1 + max(height(node->leftChild), height(node->rightChild));

        int balance = getBalance(node);

        if (balance > 1 && data < node->leftChild->data)
            return rightRotate(node);

        if (balance < -1 && data > node->rightChild->data)
            return leftRotate(node);

        if (balance > 1 && data > node->leftChild->data)
        {
            node->leftChild = leftRotate(node->leftChild);
            return rightRotate(node);
        }

        if (balance < -1 && data < node->rightChild->data)
        {
            node->rightChild = rightRotate(node->rightChild);
            return leftRotate(node);
        }

        return node;
    }

    struct AVLNode<T>* minValueNode(struct AVLNode<T> *node)
    {
        struct AVLNode<T> *current = node;
        while (current->leftChild)
            current = current->leftChild;
        return current;
    }

    struct AVLNode<T>* deleteNode(struct AVLNode<T> *root, T data)
    {
        if (!root)
            return root;

        if (data < root->data)
            root->leftChild = deleteNode(root->leftChild, data);
        else if (data > root->data)
            root->rightChild = deleteNode(root->rightChild, data);
        else
        {
            if ((!root->leftChild) || (!root->rightChild))
            {
                struct AVLNode<T> *temp = root->leftChild ? root->leftChild : root->rightChild;

                if (!temp)
                {
                    temp = root;
                    root = nullptr;
                }
                else
                    *root = *temp;
                delete temp;
            }
            else
            {
                struct AVLNode<T> *temp = minValueNode(root->rightChild);
                root->data = temp->data;
                root->rightChild = deleteNode(root->rightChild, temp->data);
            }
        }

        if (!root)
            return root;

        root->height = 1 + max(height(root->leftChild), height(root->rightChild));

        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->leftChild) >= 0)
            return rightRotate(root);

        if (balance > 1 && getBalance(root->leftChild) < 0)
        {
            root->leftChild = leftRotate(root->leftChild);
            return rightRotate(root);
        }

        if (balance < -1 && getBalance(root->rightChild) <= 0)
            return leftRotate(root);

        if (balance < -1 && getBalance(root->rightChild) > 0)
        {
            root->rightChild = rightRotate(root->rightChild);
            return leftRotate(root);
        }

        return root;
    }

public:
    AVLTree()
    {
        this->root = nullptr;
    }

    void insertNode(T data)
    {
        this->root = insert(this->root, data);
    }

    bool deleteNode(T data)
    {
        if (search(data))
        {
            this->root = deleteNode(this->root, data);
            return true;
        }
        return false;
    }

    ~AVLTree()
    {
        destroyTree(this->root);
    }

private:
    void destroyTree(struct AVLNode<T> *node)
    {
        if (node)
        {
            destroyTree(node->leftChild);
            destroyTree(node->rightChild);
            delete node;
        }
    }

    bool search(T data)
    {
        return searchNode(this->root, data);
    }

    bool searchNode(struct AVLNode<T> *node, T data)
    {
        if (!node)
            return false;

        if (data == node->data)
            return true;
        else if (data < node->data)
            return searchNode(node->leftChild, data);
        else
            return searchNode(node->rightChild, data);
    }

    void inOrder()
    {

    }

    void preOrder()
    {

    }

    void postOrder()
    {

    }

};


int main()
{
    AVLTree<int> obj;
    obj.insertNode(2);
    obj.insertNode(3);
    obj.insertNode(1);
    obj.insertNode(5);
    obj.insertNode(51);
    obj.insertNode(13);
    return 0;
}