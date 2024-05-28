#include "MyStack.h"

class ExpressionConverter: public MyStack<char> 
{
public:
    ExpressionConverter();
    string convertToPostfix(const string& infix);
    string convertToPrefix(const string& infix);
    void push(char);
    char pop();
    ~ExpressionConverter() {}
};

ExpressionConverter::ExpressionConverter() {}

void ExpressionConverter::push(char value) 
{
    if (this->isFull()) 
    {
        cout << "Stack Overflow!" << endl;
        return;
    }
    this->arr[this->currentSize] = value;
    this->currentSize++;
}

char ExpressionConverter::pop() 
{
    if (this->isEmpty()) 
    {
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
    for (char c : infix) 
    {
        if (isalnum(c))
            postfix += c;
        else if (c == '(')
            this->push(c);
        else if (c == ')')
        {
            while (!this->isEmpty() && this->top() != '(')
                postfix += this->pop();
            this->pop();
        }
        else 
        { 
            while (!this->isEmpty() && getPrecedence(this->top()) >= getPrecedence(c)) 
                postfix += this->pop();
            this->push(c);
        }
    }

    while (!this->isEmpty())
        postfix += this->pop();
    return postfix;
}

string ExpressionConverter::convertToPrefix(const string& infix) 
{
    string prefix = "";
    for (int i = infix.size() - 1; i >= 0; i--) 
    {
        char c = infix[i];
        if (isalnum(c)) 
            prefix = c + prefix;
        else if (c == ')')
            this->push(c);
        else if (c == '(')
        {
            while (!this->isEmpty() && this->top() != ')')
                prefix = this->pop() + prefix;
            this->pop();
        } 
        else 
        {
            while (!this->isEmpty() && getPrecedence(this->top()) > getPrecedence(c))
                prefix = this->pop() + prefix;
            this->push(c);
        }
    }

    while (!this->isEmpty()) 
        prefix = this->pop() + prefix;

    return prefix;
}
