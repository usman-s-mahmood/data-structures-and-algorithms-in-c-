#include "Tree.h"
#include "MyDoubleLinkedList.h"

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
        T max_value_pro(struct Node<T> *root);
        T min_value_pro(struct Node<T> *root);
        void parent_node_pro(struct Node<T> *root, T value, T &parent_value);
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
        void target_subset(T);
        void mergeBSTsIntoDDL(BinarySearchTree<T>, BinarySearchTree<T>);
        T maxValue();
        T minValue();
        T parentNode(T);
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
void BinarySearchTree<T>::target_subset(T target)
{
    if (isEmpty())
    {
        cout << "Invalid Operation! Tree is Empty" << endl;
        return ;
    }
    int size = 0,
        itr = 0;
    tree_size(this->root, size);
    T arr[size] = {0};
    convert_to_array(this->root, arr, itr);
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << endl;
    for (int i = 0; i < size; i++)
        for (int j = i+1; j < size; j++)
            for (int k = j+1; k < size; k++)
                if (arr[i] + arr[j] + arr[k] == target)
                    cout << '[' << arr[i] << ", " << arr[j] << ", " << arr[k] << ']' << endl;
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
            // root node case
        }
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return false;
}

template <class T>
void BinarySearchTree<T>::mergeBSTsIntoDDL(BinarySearchTree<T> obj1, BinarySearchTree<T> obj2)
{
    int size1 = 0,
        size2 = 0,
        itr1 = 0,
        itr2 = 0;
    tree_size(obj1.root, size1);
    tree_size(obj2.root, size2);
    T arr1[size1] = {0},
        arr2[size2] = {0};
    convert_to_array(obj1.root, arr1, itr1);
    convert_to_array(obj2.root, arr2, itr2);
    int max_size = size1 + size2;
    T max_arr[max_size] = {0};
    for (int i = 0; i < size1; i++)
        max_arr[i] = arr1[i];
    for (int i = size1, j = 0; i < max_size && j < size2; i++, j++)
        max_arr[i] = arr2[j];
    // for (int i = 0; i < max_size; i++)
    //     cout << max_arr[i] << ' ';
    // cout << endl;
    int temp = 0;
    for (int i = 0; i < max_size; i++)
        for (int j = i+1; j < max_size; j++)
            if (max_arr[i] > max_arr[j])
            {
                temp = max_arr[i];
                max_arr[i] = max_arr[j];
                max_arr[j] = temp;
            }
    cout << "Values of BST1" << endl;
    for (int i = 0; i < size1; i++)
        cout << arr1[i] << ' ';
    cout << endl;
    cout << "Values of BST2" << endl;
    for (int i = 0; i < size2; i++)
        cout << arr2[i] << ' ';
    cout << endl;
    // for (int i = 0; i < max_size; i++)
    //     cout << max_arr[i] << ' ';
    // cout << endl;
    MyDoubleLinkedList<T> obj;
    for (int i = 0; i < max_size; i++)
        obj.insertAtTail(max_arr[i]);
    cout << "Conversion of BST1 and BST2 in Sorted Double Linked List" << endl;
    obj.display();
}

template <class T>
T BinarySearchTree<T>::max_value_pro(struct Node<T> *root)
{
    if (root->right != nullptr)
        return max_value_pro(root->right);
    else
        return root->data;
}

template <class T>
T BinarySearchTree<T>::min_value_pro(struct Node<T> *root)
{
    if (root->left != nullptr)
        return min_value_pro(root->left);
    else
        return root->data;
}

template <class T>
T BinarySearchTree<T>::maxValue()
{
    if (!isEmpty())
    {
        T max = max_value_pro(this->root);
        cout << "Max Value is: " << max << endl;
        return max;
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return T();
}

template <class T>
T BinarySearchTree<T>::minValue()
{
    if (!isEmpty())
    {
        T min = min_value_pro(this->root);
        cout << "Minimum value is: " << min << endl;
        return min;
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return T();
}

template <class T>
void BinarySearchTree<T>::parent_node_pro(struct Node<T> *root, T value, T &parent_value)
{
    if (root->left->data == value || root->right->data == value)
    {
        parent_value = root->data;
        return ;
    }
    else if (root->left == nullptr && root->right == nullptr)
        return ;
    else
    {
        if (value < root->data)
            parent_node_pro(root->left, value, parent_value);
        else
            parent_node_pro(root->right, value, parent_value);
    }
}

template <class T>
T BinarySearchTree<T>::parentNode(T value)
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