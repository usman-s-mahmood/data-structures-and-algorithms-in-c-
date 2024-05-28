#include <iostream>

using namespace std;

int recursiveSum(int *arr, int size);

int main()
{
    const int size = 10;
    int *arr = new int[size];
    // populating the array
    for (int i = 0; i < size; i++)
        arr[i] = i + 1;
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << endl;
    // Iterative Approach
    int sum = recursiveSum(arr, size);
    // for (int i = 0; i < size; i++) // Base Case: i < size; starting case: i = 0;
        // sum += arr[i];
    cout << "Sum of array elements is: " << sum << endl;
    return 0;
}

int recursiveSum(int *arr, int size)
{
    int itr = 0,
        sum = 0;
    if (itr == size)
        return sum;
    sum += arr[itr];
    itr++;
    return recursiveSum(arr, size);
}