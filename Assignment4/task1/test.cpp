#include "BinarySearchTree.h"
#include <unordered_map>

int main()
{
    BinarySearchTree<int> obj;
    obj.insert(10);
    obj.insert(20);
    obj.insert(30);
    obj.insert(40);
    obj.insert(50);
    obj.insert(50);
    obj.insert(50);
    obj.insert(50);
    obj.insert(25);
    obj.insert(25);
    obj.insert(35);
    obj.insert(35);
    obj.insert(35);
    obj.insert(90);
    BinarySearchTree<int> obj2;
    obj2.insert(30);
    obj2.insert(10);
    obj2.insert(20);
    obj2.insert(40);
    obj2.insert(50);
    obj2.insert(25);
    obj2.insert(35);
    obj2.insert(90);
    obj2.identical_trees(obj, obj2);

    unordered_map<int, int> counter;
    int size = obj.size_of_tree();
    int arr[size] = {0};
    obj.returnArray(arr, size);
    for (int i = 0; i < size; i++)
        counter[arr[i]]++;
    int max_key = 0,
        max_value = 0;
    for (auto i: counter)
        cout << i.first << ' ' << i.second << endl;
    for (auto i: counter)
    {
        if (i.second > max_value)
        {
            max_value = i.second;
            max_key = i.first;
        }
    }
    cout << "Max Key: " << max_key << endl
        << "Max Frequency: " << max_value
    << endl;

    return 0;
}