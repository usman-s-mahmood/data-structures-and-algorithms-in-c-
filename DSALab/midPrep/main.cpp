#include "MyStack.h"
// #include "CircularQueue.h"
void palindrome_check(const char *word, int size);
template <class T>
void sumOfAllValues(MyStack <T> obj);
template <class T>
void searchValue(MyStack<T> obj);
template <class T>
void removeDuplicates(MyStack<T> obj);

int main()
{
    // the algo below works fine for all palindromes
    // cout<<"Enter a word that is palindrome: ";
    // char word[100];
    // gets(word);
    // palindrome_check(word, strlen(word));
    // the below algo works fine!
    // MyStack <int> obj(5);
    // obj.push(1);
    // obj.push(1);
    // obj.push(1);
    // obj.push(1);
    // obj.push(1);
    // sumOfAllValues(obj);
    // the algo below works as expected
    // MyStack<int> obj(5);
    // obj.push(1);
    // obj.push(2);
    // obj.push(3);
    // obj.push(4);
    // obj.push(5);
    // searchValue(obj);
    MyStack<int> obj(5);
    obj.push(1);
    obj.push(2);
    obj.push(3);
    obj.push(1);
    obj.push(4);
    removeDuplicates(obj);
    return 0;
}
void palindrome_check(const char *word, int size)
{
    MyStack <char> stk1(size+1), stk2(size+1);
    for (int i = 0; i < size; i++)
        stk1.push(word[i]);
    for (int i = size-1; i >= 0; i--)
        stk2.push(word[i]);
    bool flag = true;
    // stk1.display(); stk2.display(); // added this line for debugging
    while (!stk1.isEmpty() && !stk2.isEmpty())
    {
        char val1 = stk1.pop(), val2 = stk2.pop();
        if (val1 != val2)
            flag = false;
    }
    if (flag)
        cout<<"Word is palindrome"<<endl;
    else
        cout<<"Word is not palindrome"<<endl;
}
template <class T>
void sumOfAllValues(MyStack <T> obj)
{
    MyStack<T> copy(obj);
    cout<<"Original Values of Stack: "<<endl;
    obj.display();
    int sum = 0;
    while (!copy.isEmpty())
    {
        T value = copy.pop();
        sum += value;
    }
    cout<<"Sum of values: "<<sum<<endl;
}

template <class T>
void searchValue(MyStack<T> obj)
{
    MyStack<T> copy(obj);
    obj.display();
    cout<<"Enter a value to search in the stack: ";
    T value;
    cin>>value;
    bool flag = false;
    while (!copy.isEmpty())
    {
        T popValue = copy.pop();
        if (popValue == value)
            flag = true;
    }
    if (flag)
    {
        cout<<"Value found in the stack!"<<endl;
        return ;
    }
    cout<<"Value not found in the stack!"<<endl;
}

template <class T>
void removeDuplicates(MyStack<T> obj)
{
    MyStack<T> result; // To store elements without duplicates
    std::cout << "Values before removing duplicates: " << std::endl;
    int size = 0;
    obj.display();
    while (!obj.isEmpty()) {
        T current = obj.pop(); // Remove and get the top element

        // Check if the current element is not present in the rest of the stack
        bool duplicate = false;
        MyStack<T> temp(obj); // Create a temporary stack to compare with the remaining elements
        while (!temp.isEmpty()) {
            if (current == temp.top()) {
                duplicate = true;
                break;
            }
            temp.pop();
        }

        // If the current element is not a duplicate, push it onto the result stack
        if (!duplicate) 
        {
            result.push(current);
            size++;
        }
    }

    cout << "Values after removing duplicates: " << endl;
    // result.display();
    MyStack<T> revStack(size);
    while (!result.isEmpty())
        revStack.push(result.pop());
    revStack.display();
}
