#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> freqFromFile;
    
    ifstream in;
    in.open("/Users/mohsinabbas/Desktop/Test/Test/input.txt");
    
    if (!in)
        cout << "File not found" << endl;
    
    cout << "yes" << endl;
    
    string input;
    while (!in.eof())
    {
       // cout << "yes" << endl;
        in>>input;
       // cout << input << endl;
        freqFromFile[input]++;
    }
    
    in.close();
    
    cout << "Look here: " << endl;
    
    for (auto x : freqFromFile)
          cout << x.first << " " << x.second << endl;
    
    return 0;
}
