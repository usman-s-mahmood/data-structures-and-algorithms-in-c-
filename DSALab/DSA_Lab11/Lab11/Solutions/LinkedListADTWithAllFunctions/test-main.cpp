#include <iostream>

using namespace std;

template <class T>
struct Node
{
    T data;
    struct Node *next;
};

int main()
{
    struct Node<int> *n = new struct Node<int>;
    n->data = 15;
    cout<<n->data<<endl;
    return 0;
}