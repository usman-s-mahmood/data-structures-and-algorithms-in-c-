#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<string, int> hash_table;
    string input = string();
    while (true)
    {
        cout << "Enter a string for it's frequency tracking. Enter stop to see the occurances of input strings: " ;
        getline(cin, input);
        if (input == "STOP" || input == "stop")
            break;
        hash_table[input]++;
    }
    cout << "Frequency of strings entered in console!" << endl;
    for (auto i:hash_table)
        cout << "Actual word: " << i.first << " | number of occurances in hash table: "<< i.second << endl;
    return 0;
}