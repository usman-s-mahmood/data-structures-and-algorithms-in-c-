#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <cmath>

using namespace std;

template <class T>
class Stack
{
    protected:
        int maxSize, currentSize;
        T *arr;
    public:
        Stack();
        Stack(int);
        virtual void push(T) = 0;
        virtual T pop() = 0;
        ~Stack()
        {
            delete [] arr;
        }
};

template <class T>
Stack<T>::Stack()
{
    this->maxSize = 10;
    this->currentSize = 0;
    this->arr = new T[this->maxSize];
}

template <class T>
Stack<T>::Stack(int maxSize)
{
    this->maxSize = maxSize;
    this->currentSize = 0;
    this->arr = new T[this->maxSize];
}