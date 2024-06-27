#include <iostream>
#include <string>
#include <cmath>

using namespace std;

template <class T>
struct RBNode
{
    T data;
    struct RBNode<T> *leftChild;
    struct RBNode<T> *rightChild;
    char color;
};

template <class T>
class Tree
{
    protected:
        struct RBNode<T> *root;
    public:
        Tree();
        virtual void insertNode(T) = 0;
        virtual bool deleteNode(T) = 0;
        virtual void inOrder() = 0;
        virtual void preOrder() = 0;
        virtual void postOrder() = 0;
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
    delete this->root;
}


template <class T>
class RBTree: public Tree<T>
{
    protected:
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

template <class T>
void RBTree<T>::insertNode(T value)
{
    
}

template <class T>
bool RBTree<T>::deleteNode(T value)
{
    if (!isEmpty())
    {
        if (search(value))
        {
            return false;
        }
    }
    cout << "Invalid Operaion! Tree is empty" << endl;
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
        parent_value = root->data;
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
int main()
{
    RBTree<int> obj;
    cout << "Welcome To Red Black Tree Demonstration System" << endl;
    int ch = -1;
    while (ch != 12)
    {
        cout << "Select your desired option" << endl
            << "Press 1 to insert values in the tree(one by one)\nPress 2 for searching a value from the tree\nPress 3 for pre-order traversalNLR\nPress 4 for in-order traversalLNR\nPress 5 for post-order traversalLRN\nPress 6 for pre-order traversal2 NRL\nPress 7 for in-order traversal2 RNL\nPress 8 for post-order traversal2 RLN\nPress 9 for displaying parent of a node present in Tree\nPress 10 to read integer values from the file input.txt to create a red-black tree\nPress 11 to destroy the complete tree \nPress 12 to EXIT" << endl
        << "Enter your choice: ";
        cin >> ch;
        if (ch == 1)
        {
            cout << "Enter a value to insert: " ;
            int value;
            cin >> value;
            obj.insertNode(value);
            system("pause");
        }
        else if (ch == 2)
        {
            cout << "Enter a value to search: ";
            int value;
            cin >> value;
            obj.search(value);
            system("pause");
        }
        else if (ch == 3)
        {
            obj.preOrder();
            system("pause");
        }
        else if (ch == 4)
        {
            obj.inOrder();
            system("pause");
        }
        else if (ch == 5)
        {
            obj.postOrder();
            system("pause");
        }
        else if (ch == 6)
        {
            obj.preorder2();
            system("pause");
        }
        else if (ch == 7)
        {
            obj.inorder2();
            system("pause");
        }
        else if (ch == 8)
        {
            obj.postorder2();
            system("pause");
        }
        else if (ch == 9)
        {
            obj.inOrder();
            cout << "Enter a value in this range to display the it's parent: ";
            int value;
            cin >> value;
            obj.parentNode(value);
            system("pause");
        }
        else if (ch == 10)
        {
            // to be designed
            system("pause");
        }
        else if (ch == 11)
        {
            obj.destroyRBTree();
            system("pause");
        }
        else if (ch == 12)
        {
            cout << "Program terminated successfully!" << endl;
            return 0;
        }
        else
        {
            cout << "Invalid Operation! Program terminated" << endl;
            return -1;
        }
    }
    
}