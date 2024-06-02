#include <iostream>

using namespace std;

int binarySearch(int arr[], int left, int right, int target) 
{
    if (left > right) 
        return -1; 
    int mid = left + (right - left) / 2;    
    if (arr[mid] == target)
        return mid;
    else if (arr[mid] > target) 
        return binarySearch(arr, left, mid - 1, target);
    else 
        return binarySearch(arr, mid + 1, right, target);
}

int main() 
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;
    cout << "Elements present in the array: " << endl;
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << endl;
    cout << "Enter the target number: ";
    cin >> target;
    int result = binarySearch(arr, 0, size - 1, target);
    if (result != -1)
        cout << "Element found at index " << result << endl; 
    else 
        cout << "Element not found in the array" << endl;
    return 0;
}
