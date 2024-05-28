#include <iostream>
#include <string>
#include <cmath>

using namespace std;

template <class T>
struct Node 
{
    T data;
    Node *next;
};