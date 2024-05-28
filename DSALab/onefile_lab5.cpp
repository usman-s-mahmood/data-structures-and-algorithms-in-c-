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

template <class T>
class MyStack: public Stack<T>
{
    public:
        MyStack();
        MyStack(int);
        void push(T);
        T pop();
        bool isFull();
        bool isEmpty();
        T top();
        void display();
        ~MyStack(){}
};

template <class T>
MyStack<T>::MyStack():
    Stack<T>::Stack()
{}

template <class T>
MyStack<T>::MyStack(int maxSize):
    Stack<T>::Stack(maxSize)
{}

template <class T>
bool MyStack<T>::isFull()
{
    return (this->currentSize == this->maxSize);
}

template <class T>
bool MyStack<T>::isEmpty()
{
    return (this->currentSize == 0);
}

template <class T>
void MyStack<T>::push(T value)
{
    if(isFull())
    {
        cout<<"Stack Overflow!"<<endl;
        return ;
    }
    this->arr[this->currentSize] = value;
    this->currentSize++;
}

template <class T>
T MyStack<T>::pop()
{
    if(isEmpty())
    {
        cout<<"Stack Underflow!"<<endl;
        return -1;
    }
    T value = this->arr[this->currentSize-1];
    this->currentSize--;
    return value;
}

template <class T>
T MyStack<T>::top()
{
    if(isEmpty())
    {
        cout<<"Stack Underflow!"<<endl;
        return -1;
    }
    return this->arr[this->currentSize - 1];
}

template <class T>
void MyStack<T>::display()
{
    if(isEmpty())
    {
        cout<<"Stack Underflow!"<<endl;
        return ;
    }
    cout<<"Max Size: "<<this->maxSize<<endl
        <<"Current Size: "<<this->currentSize<<endl
        <<"Values with there indexes: "
    <<endl;
    for (int i = 0; i < this->currentSize; i++)
        cout<<i<<". "<<this->arr[i]<<endl;
}

class ExpressionConverter: public MyStack<char> {
public:
    ExpressionConverter();
    string convertToPostfix(const string& infix);
    string convertToPrefix(const string& infix);
    void push(char);
    char pop();
    ~ExpressionConverter() {}
};

ExpressionConverter::ExpressionConverter() {}

void ExpressionConverter::push(char value) {
    if (this->isFull()) {
        cout << "Stack Overflow!" << endl;
        return;
    }
    this->arr[this->currentSize] = value;
    this->currentSize++;
}

char ExpressionConverter::pop() 
{
    if (this->isEmpty()) {
        cout << "Stack Underflow!" << endl;
        return -1;
    }
    char value = this->arr[this->currentSize-1];
    this->currentSize--;
    return value;
}

bool isOperator(char c) 
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int getPrecedence(char op) 
{
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

string ExpressionConverter::convertToPostfix(const string& infix) 
{
    string postfix = "";
    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            this->push(c);
        } else if (c == ')') {
            while (!this->isEmpty() && this->top() != '(') {
                postfix += this->pop();
            }
            this->pop(); // Pop '('
        } else { // Operator
            while (!this->isEmpty() && getPrecedence(this->top()) >= getPrecedence(c)) {
                postfix += this->pop();
            }
            this->push(c);
        }
    }

    while (!this->isEmpty()) {
        postfix += this->pop();
    }

    return postfix;
}

string ExpressionConverter::convertToPrefix(const string& infix) 
{
    string prefix = "";
    for (int i = infix.size() - 1; i >= 0; i--) {
        char c = infix[i];
        if (isalnum(c)) {
            prefix = c + prefix;
        } else if (c == ')') {
            this->push(c);
        } else if (c == '(') {
            while (!this->isEmpty() && this->top() != ')') {
                prefix = this->pop() + prefix;
            }
            this->pop(); // Pop ')'
        } else { // Operator
            while (!this->isEmpty() && getPrecedence(this->top()) > getPrecedence(c)) {
                prefix = this->pop() + prefix;
            }
            this->push(c);
        }
    }

    while (!this->isEmpty()) {
        prefix = this->pop() + prefix;
    }

    return prefix;
}

int main() 
{
    ExpressionConverter converter;

    int choice;
    string infix, result;
    
    do {
        cout << "1. Convert infix expression to prefix" << endl;
        cout << "2. Convert infix expression to postfix" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter infix expression: ";
                cin >> infix;
                result = converter.convertToPrefix(infix);
                cout << "Prefix expression: " << result << endl;
                break;
            case 2:
                cout << "Enter infix expression: ";
                cin >> infix;
                result = converter.convertToPostfix(infix);
                cout << "Postfix expression: " << result << endl;
                break;
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
    return 0;
}