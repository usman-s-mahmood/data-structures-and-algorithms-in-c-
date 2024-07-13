#include <iostream>

using namespace std;

int main()
{
    int arr[] = {
        8, 9, 1, 7,
        5, 4, 12, 22,
        -3, 33, 47, 8
    },
    min = arr[0],
    temp[sizeof(arr)/sizeof(int)] = {0};
    for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
        if (arr[i] < min)
            min = arr[i];
    int itr = 0, temp_itr = 0;
    cout << "Indexes of itr: ";
    for (itr; itr < sizeof(arr)/sizeof(int); itr++)
    {
        if (arr[itr] == min)
            break;
        cout << itr << ' ';
        temp[temp_itr] = arr[itr];
        temp_itr++;
    }
    while (itr < sizeof(arr)/sizeof(int))
    {
        itr++;
        cout << itr << ' ';
        temp[temp_itr] = arr[itr];
        temp_itr++;
        if (itr == sizeof(arr)/sizeof(int) - 1)
            break;
        
    }
    cout << endl;
    cout << "Size of array: " << sizeof(arr)/sizeof(int) << endl << "Size of iterator: " << itr << endl;
    cout << "Values in actual array: " ;
    for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
        cout << arr[i] << ' ';
    cout << endl;
    cout << "temp array has values: " ;
    for (int i = 0; i < itr; i++)
        cout << temp[i] << ' ';
    cout << endl;
    return 0;
}