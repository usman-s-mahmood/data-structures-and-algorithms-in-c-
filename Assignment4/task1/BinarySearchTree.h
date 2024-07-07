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
        T max_value_pro(struct Node<T> *root);
        T min_value_pro(struct Node<T> *root);
        void parent_node_pro(struct Node<T> *root, T value, T &parent_value);
        void pre_order_array(struct Node<T> *root, T *arr, int &itr);
        void convert_to_array_pre_order(struct Node<T> *root, T *arr, int &itr);
        void convert_to_array_post_order(struct Node<T> *root, T *arr, int &itr);
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
        T maxValue();
        T minValue();
        T parentNode(T);
        int size_of_tree();
        void compare_pre_order_array(T *arr);
        void identical_trees(BinarySearchTree<T>, BinarySearchTree<T>);
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

template <class T>
int BinarySearchTree<T>::size_of_tree()
{
    if (!isEmpty())
    {
        int size = 0;
        tree_size(this->root, size);
        cout << "Size of tree is: " << size << endl;
        return size;
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return 0;
}

template <class T>
void BinarySearchTree<T>::pre_order_array(struct Node<T> *root, T *arr, int &itr)
{
    if (root != nullptr)
    {
        arr[itr] = root->data;
        itr++;
        pre_order_array(root->left, arr, itr);
        pre_order_array(root->right, arr, itr);
    }
}

template <class T>
void BinarySearchTree<T>::compare_pre_order_array(T *arr)
{
    if (!isEmpty())
    {
        int size = 0,
            itr = 0;
        tree_size(this->root, size);
        int pre_order_arr[size] = {0};
        this->pre_order_array(this->root, pre_order_arr, itr);
        bool flag = true;
        for (int i = 0; i < size; i++)
            if (arr[i] != pre_order_arr[i])
                flag = false;
        if (flag)
            cout << "Sequence is correct!" << endl;
        else
            cout << "Your given sequence does not match the pre order of this Binary search tree" << endl;
        cout << "Correct pre order sequence of tree" << endl;
        for (int i = 0; i < size; i++)
            cout << pre_order_arr[i] << ' ';
        cout << endl;
        return ;
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return ;
}

template <class T>
void BinarySearchTree<T>::convert_to_array_pre_order(struct Node<T> *root, T *arr, int &itr)
{
    if (root != nullptr)
    {
        arr[itr] = root->data;
        itr++;
        convert_to_array_pre_order(root->left, arr, itr);
        convert_to_array_pre_order(root->right, arr, itr);
    }
}

template <class T>
void BinarySearchTree<T>::convert_to_array_post_order(struct Node<T> *root, T *arr, int &itr)
{
    if (root != nullptr)
    {
        convert_to_array_post_order(root->left, arr, itr);
        convert_to_array_post_order(root->right, arr, itr);
        arr[itr] = root->data;
        itr++;
    }
}

template <class T>
void BinarySearchTree<T>::identical_trees(BinarySearchTree<T> tree1, BinarySearchTree<T> tree2)
{
    if (!tree1.isEmpty() && !tree2.isEmpty())
    {
        int size1 = 0,
            size2 = 0,
            itr = 0;
        size1 = tree1.size_of_tree();
        size2 = tree2.size_of_tree();
        if (size1 != size2)
        {
            cout << "First Check Failed! Sizes of both trees mismatch" << endl;
            return ;
        }
        int in_arr_1[size1] = {0},
            pre_arr_1[size1] = {0},
            post_arr_1[size1] = {0},
            in_arr_2[size2] = {0},
            pre_arr_2[size2] = {0},
            post_arr_2[size2] = {0};
        convert_to_array(tree1.root, in_arr_1, itr);
        itr = 0;
        convert_to_array_pre_order(tree1.root, pre_arr_1, itr);
        itr = 0;
        convert_to_array_post_order(tree1.root, post_arr_1, itr);
        itr = 0;
        
        convert_to_array(tree2.root, in_arr_2, itr);
        itr = 0;
        convert_to_array_pre_order(tree2.root, pre_arr_2, itr);
        itr = 0;
        convert_to_array_post_order(tree2.root, post_arr_2, itr);
        itr = 0;
        cout << "Traversal arrays of tree1: " << endl;
        cout << "Inorder: ";
        for (int i = 0; i < size1; i++)
            cout << in_arr_1[i] << ' ';
        cout << endl;
        cout << "Preorder: ";
        for (int i = 0; i < size1; i++)
            cout << pre_arr_1[i] << ' ';
        cout << endl;
        cout << "Postorder: ";
        for (int i = 0; i < size1; i++)
            cout << post_arr_1[i] << ' ';
        cout << endl;
        cout << "Traversal arrays of tree2: " << endl;
        cout << "Inorder: ";
        for (int i = 0; i < size2; i++)
            cout << in_arr_2[i] << ' ';
        cout << endl;
        cout << "Preorder: ";
        for (int i = 0; i < size2; i++)
            cout << pre_arr_2[i] << ' ';
        cout << endl;
        cout << "Postorder: ";
        for (int i = 0; i < size2; i++)
            cout << post_arr_2[i] << ' ';
        cout << endl;
        bool check1 = true, 
            check2 = true, 
            check3 = true;
        for (int i = 0; i < size1; i++)
            if (in_arr_1[i] != in_arr_2[i])
                check1 = false;
        for (int i = 0; i < size1; i++)
            if (pre_arr_1[i] != pre_arr_2[i])
                check2 = false;
        for (int i = 0; i < size1; i++)
            if (post_arr_1[i] != post_arr_2[i])
                check3 = false;
        if (check1 && check2 && check3)
            cout << "Trees are identical" << endl;
        else
            cout << "Trees are not identical! traversals don't match" << endl;
        return ;
    }
    cout << "Invalid Operation! One of the provided trees is empty" << endl;
    return ;
}

// -- --


// Returns level of key k if it is present in tree, 
// otherwise returns -1
template <class T>
int findLevel(Node<T> *root, int k, int level)
{
    // Base Case
    if (root == NULL)
        return -1;
 
    // If key is present at root, or in left subtree
    // or right subtree, return true;
    if (root->data == k)
        return level;
 
    int l = findLevel(root->left, k, level+1);
    return (l != -1)? l : findLevel(root->right, k, level+1);
}
 
// This function returns pointer to LCA of two given
// values n1 and n2. It also sets d1, d2 and dist if 
// one key is not ancestor of other
// d1 --> To store distance of n1 from root
// d2 --> To store distance of n2 from root
// lvl --> Level (or distance from root) of current node
// dist --> To store distance between n1 and n2
template <class T>
Node<T> *findDistUtil(Node<T>* root, int n1, int n2, int &d1, int &d2, int &dist, int lvl)
{
    // Base case
    if (root == NULL) return NULL;
 
    // If either n1 or n2 matches with root's key, report
    // the presence by returning root (Note that if a key is
    // ancestor of other, then the ancestor key becomes LCA
    if (root->data == n1)
    {
        d1 = lvl;
        return root;
    }
    if (root->data == n2)
    {
        d2 = lvl;
        return root;
    }
    // Look for n1 and n2 in left and right subtrees
    Node<T> *left_lca  = findDistUtil(root->left, n1, n2, d1, d2, dist, lvl+1);
    Node<T> *right_lca = findDistUtil(root->right, n1, n2, d1, d2, dist, lvl+1);
 
    // If both of the above calls return Non-NULL, then
    // one key is present in once subtree and other is 
    // present in other. So this node is the LCA
    if (left_lca && right_lca)
    {
        dist = d1 + d2 - 2*lvl;
        return root;
    }
 
    // Otherwise check if left subtree or right subtree 
    // is LCA
    return (left_lca != NULL)? left_lca: right_lca;
}
 
// The main function that returns distance between n1
// and n2. This function returns -1 if either n1 or n2
// is not present in Binary Tree.
template <class T>
int findDistance(Node<T> *root, int n1, int n2)
{
    // Initialize d1 (distance of n1 from root), d2 
    // (distance of n2 from root) and dist(distance 
    // between n1 and n2)
    int d1 = -1, d2 = -1, dist;
    Node<T> *lca = findDistUtil(root, n1, n2, d1, d2, dist, 1);
 
    // If both n1 and n2 were present in Binary 
    // Tree, return dist
    if (d1 != -1 && d2 != -1)
        return dist;
 
    // If n1 is ancestor of n2, consider n1 as root 
    // and find level of n2 in subtree rooted with n1
    if (d1 != -1)
    {
        dist = findLevel(lca, n2, 0);
        return dist;
    }
 
    // If n2 is ancestor of n1, consider n2 as root 
    // and find level of n1 in subtree rooted with n2
    if (d2 != -1)
    {
        dist = findLevel(lca, n1, 0);
        return dist;
    }
 
    return -1;
}