#include <iostream>

using namespace std;

int BinarySearch(int *arr, int size, int value)
{
    int first = 0,
        last = size-1,
        mid = size/2;
    while (first < last)
    {
        if (arr[mid] == value)
        {
            cout << "Value found at index: " << mid << endl;
            return mid;
        }
        else if (value < arr[mid])
        {
            last = last/2;
            mid = last/2;
        }
        else
        {
            first = mid;
            mid = (first+last)/2;
        }
    }
    cout << "Value not found!" << endl;
    return -1;
}

void pyramidPattern(int x, int k)
{
    if (x != x+k)
    {
        cout << x << endl;
        pyramidPattern(x+1, k);
    }
    else
        return ;
}

int main()
{
    int arr[] = {
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 10, 11, 12 
    },
    size = sizeof(arr)/sizeof(int);
    cout << BinarySearch(arr, size, 7) << endl;
    // pyramidPattern(47, 4);
    return 0;
}