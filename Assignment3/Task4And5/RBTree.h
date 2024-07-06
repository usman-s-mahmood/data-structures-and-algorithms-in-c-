#include "Tree.h"

template <class T>
class RBTree: public Tree<T>
{
    protected:
        
        void leftRotate(struct RBNode<T> *&root, struct RBNode<T> *&pt);
        void rightRotate(struct RBNode<T> *&root, struct RBNode<T> *&pt);
        void fixInsertRBTree(struct RBNode<T> *&root, struct RBNode<T> *&pt);
        void fixDeleteRBTree(struct RBNode<T> *&root, struct RBNode<T> *&pt);
        struct RBNode<T>* BSTInsert(struct RBNode<T>* root, struct RBNode<T>* pt);
        struct RBNode<T>* minValueNode(struct RBNode<T>* node);
        void deleteBSTNode(struct RBNode<T>* &root, struct RBNode<T>* &node);
        // -- --
        void INORDER(struct RBNode<T> *root);
        void PREORDER(struct RBNode<T> *root);
        void POSTORDER(struct RBNode<T> *root);
        void convert_to_array(struct RBNode<T> *root, T *arr, int &itr);
        void SEARCH(struct RBNode<T> *root, T value, bool &check);
        void INORDER_RNL(struct RBNode<T> *root);
        void PREORDER_NRL(struct RBNode<T> *root);
        void POSTORDER_RLN(struct RBNode<T> *root);
        void TREE_SIZE(struct RBNode<T> *root, int &ref);
        void parent_node_pro(struct RBNode<T> *root, T value, T &parent_value);
    public:
        RBTree();
        void insertNode(T);
        bool deleteNode(T);
        void inOrder();
        void preOrder();
        void postOrder();
        void inorder2();
        void preorder2();
        void postorder2();
        bool search(T);
        bool isEmpty();
        int tree_size();
        T parentNode(T);
        void destroyRBTree();
        ~RBTree();
};


// -- --


// Rotate left at node x
template <class T>
void RBTree<T>::leftRotate(struct RBNode<T> *&root, struct RBNode<T> *&pt)
{
    struct RBNode<T> *pt_right = pt->rightChild;

    pt->rightChild = pt_right->leftChild;

    if (pt->rightChild != nullptr)
        pt->rightChild->parent = pt;

    pt_right->parent = pt->parent;

    if (pt->parent == nullptr)
        root = pt_right;

    else if (pt == pt->parent->leftChild)
        pt->parent->leftChild = pt_right;

    else
        pt->parent->rightChild = pt_right;

    pt_right->leftChild = pt;
    pt->parent = pt_right;
}

// Rotate right at node x
template <class T>
void RBTree<T>::rightRotate(struct RBNode<T> *&root, struct RBNode<T> *&pt)
{
    struct RBNode<T> *pt_left = pt->leftChild;

    pt->leftChild = pt_left->rightChild;

    if (pt->leftChild != nullptr)
        pt->leftChild->parent = pt;

    pt_left->parent = pt->parent;

    if (pt->parent == nullptr)
        root = pt_left;

    else if (pt == pt->parent->leftChild)
        pt->parent->leftChild = pt_left;

    else
        pt->parent->rightChild = pt_left;

    pt_left->rightChild = pt;
    pt->parent = pt_left;
}

// This function fixes violations caused by BST insertion
template <class T>
void RBTree<T>::fixInsertRBTree(struct RBNode<T> *&root, struct RBNode<T> *&pt)
{
    struct RBNode<T> *parent_pt = nullptr;
    struct RBNode<T> *grand_parent_pt = nullptr;

    while ((pt != root) && (pt->color != 'B') && (pt->parent->color == 'R'))
    {
        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;

        /*  Case : A 
            Parent of pt is left child of Grand-parent of pt */
        if (parent_pt == grand_parent_pt->leftChild)
        {
            struct RBNode<T> *uncle_pt = grand_parent_pt->rightChild;

            /* Case : 1
               The uncle of pt is also red
               Only Recoloring required */
            if (uncle_pt != nullptr && uncle_pt->color == 'R')
            {
                grand_parent_pt->color = 'R';
                parent_pt->color = 'B';
                uncle_pt->color = 'B';
                pt = grand_parent_pt;
            }

            else
            {
                /* Case : 2
                   pt is right child of its parent
                   Left-rotation required */
                if (pt == parent_pt->rightChild)
                {
                    leftRotate(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                /* Case : 3
                   pt is left child of its parent
                   Right-rotation required */
                rightRotate(root, grand_parent_pt);
                std::swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }

        /* Case : B 
           Parent of pt is right child of Grand-parent of pt */
        else
        {
            struct RBNode<T> *uncle_pt = grand_parent_pt->leftChild;

            /*  Case : 1
                The uncle of pt is also red
                Only Recoloring required */
            if ((uncle_pt != nullptr) && (uncle_pt->color == 'R'))
            {
                grand_parent_pt->color = 'R';
                parent_pt->color = 'B';
                uncle_pt->color = 'B';
                pt = grand_parent_pt;
            }
            else
            {
                /* Case : 2
                   pt is left child of its parent
                   Right-rotation required */
                if (pt == parent_pt->leftChild)
                {
                    rightRotate(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                /* Case : 3
                   pt is right child of its parent
                   Left-rotation required */
                leftRotate(root, grand_parent_pt);
                std::swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }
    }

    root->color = 'B';
}

// Utility function to insert a new node with given data
template <class T>
struct RBNode<T>* RBTree<T>::BSTInsert(struct RBNode<T>* root, struct RBNode<T>* pt)
{
    if (root == nullptr)
        return pt;

    if (pt->data < root->data)
    {
        root->leftChild = BSTInsert(root->leftChild, pt);
        root->leftChild->parent = root;
    }
    else if (pt->data > root->data)
    {
        root->rightChild = BSTInsert(root->rightChild, pt);
        root->rightChild->parent = root;
    }

    return root;
}

// -- --

template <class T>
struct RBNode<T>* RBTree<T>::minValueNode(struct RBNode<T>* node)
{
    struct RBNode<T>* ptr = node;

    while (ptr->leftChild != nullptr)
        ptr = ptr->leftChild;

    return ptr;
}

template <class T>
void RBTree<T>::deleteBSTNode(struct RBNode<T>* &root, struct RBNode<T>* &node)
{
    if (root == nullptr || node == nullptr)
        return;

    if (node->data < root->data)
        deleteBSTNode(root->leftChild, node);
    else if (node->data > root->data)
        deleteBSTNode(root->rightChild, node);
    else
    {
        if (root->leftChild == nullptr || root->rightChild == nullptr)
        {
            struct RBNode<T>* temp = root->leftChild ? root->leftChild : root->rightChild;

            if (temp == nullptr)
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
            struct RBNode<T>* temp = minValueNode(root->rightChild);
            root->data = temp->data;
            deleteBSTNode(root->rightChild, temp);
        }
    }

    if (root == nullptr)
        return;

    fixDeleteRBTree(this->root, root);
}

// A utility function to fix violations caused by BST deletion
template <class T>
void RBTree<T>::fixDeleteRBTree(struct RBNode<T> *&root, struct RBNode<T> *&x)
{
    struct RBNode<T>* sibling;
    struct RBNode<T>* pt = nullptr;

    while (x != root && x->color == 'B')
    {
        if (x == x->parent->leftChild)
        {
            sibling = x->parent->rightChild;

            // Case 1: Sibling is red
            if (sibling->color == 'R')
            {
                sibling->color = 'B';
                x->parent->color = 'R';
                leftRotate(root, x->parent);
                sibling = x->parent->rightChild;
            }

            // Case 2: Both children of sibling are black
            if (sibling->leftChild->color == 'B' && sibling->rightChild->color == 'B')
            {
                sibling->color = 'R';
                x = x->parent;
            }
            else
            {
                // Case 3: Right child of sibling is black
                if (sibling->rightChild->color == 'B')
                {
                    sibling->leftChild->color = 'B';
                    sibling->color = 'R';
                    rightRotate(root, sibling);
                    sibling = x->parent->rightChild;
                }

                // Case 4: Right child of sibling is red
                sibling->color = x->parent->color;
                x->parent->color = 'B';
                sibling->rightChild->color = 'B';
                leftRotate(root, x->parent);
                x = root;
            }
        }
        else
        {
            sibling = x->parent->leftChild;

            // Case 1: Sibling is red
            if (sibling->color == 'R')
            {
                sibling->color = 'B';
                x->parent->color = 'R';
                rightRotate(root, x->parent);
                sibling = x->parent->leftChild;
            }

            // Case 2: Both children of sibling are black
            if (sibling->rightChild->color == 'B' && sibling->leftChild->color == 'B')
            {
                sibling->color = 'R';
                x = x->parent;
            }
            else
            {
                // Case 3: Left child of sibling is black
                if (sibling->leftChild->color == 'B')
                {
                    sibling->rightChild->color = 'B';
                    sibling->color = 'R';
                    leftRotate(root, sibling);
                    sibling = x->parent->leftChild;
                }

                // Case 4: Left child of sibling is red
                sibling->color = x->parent->color;
                x->parent->color = 'B';
                sibling->leftChild->color = 'B';
                rightRotate(root, x->parent);
                x = root;
            }
        }
    }

    x->color = 'B';
}

// -- -- 
template <class T>
void RBTree<T>::insertNode(T data)
{
    struct RBNode<T> *pt = new RBNode<T>;
    pt->data = data;
    pt->leftChild = pt->rightChild = pt->parent = nullptr;
    pt->color = 'R';

    this->root = BSTInsert(this->root, pt);

    fixInsertRBTree(this->root, pt);
}

template <class T>
bool RBTree<T>::deleteNode(T data)
{
    if (isEmpty())
    {
        cout << "Invalid Operation! Tree is empty" << endl;
        return false;
    }

    struct RBNode<T>* node = this->root;
    while (node != nullptr)
    {
        if (node->data == data)
        {
            deleteBSTNode(this->root, node);
            return true;
        }
        else if (data < node->data)
            node = node->leftChild;
        else
            node = node->rightChild;
    }

    cout << "Value not found in the Tree!" << endl;
    return false;
}

template <class T>
RBTree<T>::RBTree():
    Tree<T>::Tree()
{}

template <class T>
bool RBTree<T>::isEmpty()
{
    return (this->root == nullptr);
}

template <class T>
void RBTree<T>::convert_to_array(struct RBNode<T> *root, T *arr, int &itr)
{
    if (root != nullptr)
    {
        
        convert_to_array(root->leftChild, arr, itr);
        arr[itr] = root->data;
        itr+=1;
        convert_to_array(root->rightChild, arr, itr);
    }
}

template <class T>
void RBTree<T>::TREE_SIZE(struct RBNode<T> *root, int &ref)
{
    if (root != nullptr)
    {
        TREE_SIZE(root->leftChild, ref);
        ref += 1;
        TREE_SIZE(root->rightChild, ref);
    }
}

template <class T>
void RBTree<T>::inOrder()
{
    if (!isEmpty())
    {
        INORDER(this->root);
        cout << endl;
        return ;
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return ;
}

template <class T>
void RBTree<T>::preOrder()
{
    if (!isEmpty())
    {
        PREORDER(this->root);
        cout << endl;
        return ;
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return ;
}

template <class T>
void RBTree<T>::postOrder()
{
    if (!isEmpty())
    {
        POSTORDER(this->root);
        cout << endl;
        return ;
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return ;
}

template <class T>
void RBTree<T>::inorder2()
{
    if (!isEmpty())
    {
        INORDER_RNL(this->root);
        cout << endl;
        return ;
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return ;
}

template <class T>
void RBTree<T>::preorder2()
{
    if (!isEmpty())
    {
        PREORDER_NRL(this->root);
        cout << endl;
        return ;
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return ;
}

template <class T>
void RBTree<T>::postorder2()
{
    if (!isEmpty())
    {
        POSTORDER_RLN(this->root);
        cout << endl;
        return ;
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return ;
}

template <class T>
void RBTree<T>::INORDER(struct RBNode<T> *root)
{
    if (root != nullptr)
    {
        INORDER(root->leftChild);
        cout << "( " << root->data << ", color: " << root->color << ") ";
        INORDER(root->rightChild);
    }
}

template <class T>
void RBTree<T>::PREORDER(struct RBNode<T> *root)
{
    if (root != nullptr)
    {
        cout << "( " << root->data << ", color: " << root->color << ") ";
        PREORDER(root->leftChild);
        PREORDER(root->rightChild);
    }
}

template <class T>
void RBTree<T>::POSTORDER(struct RBNode<T> *root)
{
    if (root != nullptr)
    {
        POSTORDER(root->leftChild);
        POSTORDER(root->rightChild);
        cout << "( " << root->data << ", color: " << root->color << ") ";
    }
}

template <class T>
void RBTree<T>::INORDER_RNL(struct RBNode<T> *root)
{
    if (root != nullptr)
    {
        INORDER_RNL(root->rightChild);
        cout << "( " << root->data << ", color: " << root->color << ") ";
        INORDER_RNL(root->leftChild);
    }
}

template <class T>
void RBTree<T>::PREORDER_NRL(struct RBNode<T> *root)
{
    if (root != nullptr)
    {
        cout << "( " << root->data << ", color: " << root->color << ") ";
        PREORDER_NRL(root->rightChild);
        PREORDER_NRL(root->leftChild);
    }
}

template <class T>
void RBTree<T>::POSTORDER_RLN(struct RBNode<T> *root)
{
    if (root != nullptr)
    {
        POSTORDER_RLN(root->rightChild);
        POSTORDER_RLN(root->leftChild);
        cout << "( " << root->data << ", color: " << root->color << ") ";
    }
}

template <class T>
int RBTree<T>::tree_size()
{
    if (!isEmpty())
    {
        int size = 0;
        TREE_SIZE(this->root, size);
        cout << "Size of Tree is: " << size << endl;
        return size;
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return -1;
}

template <class T>
void RBTree<T>::SEARCH(struct RBNode<T> *root, T value, bool &check)
{
    if (root != nullptr)
    {
        SEARCH(root->leftChild, value, check);
        if (root->data == value)
        {
            check = true;
            return ;
        }
        SEARCH(root->rightChild, value, check);
    }
}

template <class T>
bool RBTree<T>::search(T value)
{
    if (!isEmpty())
    {
        bool check = false;
        SEARCH(this->root, value, check);
        if (check)
        {
            cout << "Value present in the Red Black tree" << endl;
            return true;
        }
        else
        {
            cout << "Value not found in the Tree !" << endl;
            return false;
        }
    }
    cout << "Invalid Operation! Tree is Empty" << endl;
    return false;
}

template <class T>
void RBTree<T>::destroyRBTree()
{
    if (!isEmpty())
    {
        int size = 0,
            itr = 0;
        TREE_SIZE(this->root, size);
        T arr[size] = {0};
        convert_to_array(this->root, arr, itr);
        for (int i = 0; i < size; i++)
            deleteNode(arr[i]);
        cout << "All the nodes of Red Black Tree are destroyed!" << endl;
        return ;
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return ;
}

template <class T>
void RBTree<T>::parent_node_pro(struct RBNode<T> *root, T value, T &parent_value)
{
    if (root->leftChild->data == value || root->rightChild->data == value)
    {
        parent_value = root->data;
        return ;
    }
    else if (root->leftChild == nullptr && root->rightChild == nullptr)
        return ;
    else
    {
        if (value < root->data)
            parent_node_pro(root->leftChild, value, parent_value);
        else
            parent_node_pro(root->rightChild, value, parent_value);
    }
}

template <class T>
T RBTree<T>::parentNode(T value)
{
    if (!isEmpty())
    {
        if (search(value))
        {
            if (this->root->data == value)
            {
                cout << value << " belongs to root node and root doesnot have a parent!" << endl;
                return T();
            }
            T parent_value = T();
            parent_node_pro(this->root, value, parent_value);
            cout << "Parent of " << value << " is: " << parent_value << endl;
            return parent_value;
        }
        return T();
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return T();
}

template <class T>
RBTree<T>::~RBTree()
{
    RBTree<T>::destroyRBTree();
    Tree<T>::~Tree();
}