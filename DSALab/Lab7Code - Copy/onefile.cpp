#include <iostream>
#include <string>
#include <cmath>
#include <conio.h>

using namespace std;

template <class T>
class Queue
{
    protected:
        int currentSize, maxSize, front, rear;
        T *arr;
    public:
        Queue();
        Queue(int maxSize);
        virtual void enqueue(T) = 0;
        virtual T dequeue() = 0;
        virtual bool isFull() = 0;
        virtual bool isEmpty() = 0;
        virtual void display() = 0;
        virtual int size() = 0;
        virtual T peek() = 0;
        ~Queue()
        {
            delete [] arr;
        }
};


template <class T>
Queue<T>::Queue()
{
    this->maxSize = 10;
    this->currentSize = 0;
    this->front = 0;
    this->rear = 0;
    this->arr = new T[this->maxSize];
}

template <class T>
Queue<T>::Queue(int maxSize)
{
    this->maxSize = maxSize;
    this->currentSize = 0;
    this->front = 0;
    this->rear = 0;
    this->arr = new T[maxSize];
}


template <class T>
class MyQueue: public Queue<T>
{
    public:
        MyQueue();
        MyQueue(int maxSize);
        MyQueue(MyQueue &copy);
        bool isFull();
        bool isEmpty();
        void display();
        int size();
        T peek();
        void enqueue(T);
        T dequeue();
        ~MyQueue(){}
};


template <class T>
MyQueue<T>::MyQueue():
    Queue<T>::Queue()
{}

template <class T>
MyQueue<T>::MyQueue(int maxSize):
    Queue<T>::Queue(maxSize)
{}

template <class T>
MyQueue<T>::MyQueue(MyQueue &copy)
{
    this->front = copy.front;
    this->rear = copy.rear;
    this->maxSize = copy.maxSize;
    this->currentSize = copy.currentSize;
    this->arr = copy.arr;
}

template <class T>
bool MyQueue<T>::isFull()
{
    return ((this->rear + 1) % this->maxSize == this->front);
}

template <class T>
bool MyQueue<T>::isEmpty()
{
    return (this->front == this->rear);
}

template <class T>
void MyQueue<T>::enqueue(T value)
{
    if (isFull())
    {
        cout<<"Queue Overflow!"<<endl;
        return ;
    }
    this->arr[this->rear % this->maxSize] = value;
    this->rear++;
}

template <class T>
T MyQueue<T>::dequeue()
{
    if (isEmpty())
    {
        cout<<"Queue Underflow!"<<endl;
        return -1;
    }
    T value = this->arr[this->front % this->maxSize];
    this->front++;
    return value;
}

template <class T>
void MyQueue<T>::display()
{
    if (isEmpty())
    {
        cout<<"Queue Underflow"<<endl;
        return ;
    }
    for (int i = this->front; i < this->rear; i++)
        cout<<this->arr[i % this->maxSize]<<' ';
    cout<<endl;
}

template <class T>
int MyQueue<T>::size()
{
    return (this->rear - this->front);
}

template <class T>
T MyQueue<T>::peek()
{
    if (isEmpty())
    {
        cout<<"Queue Underflow!"<<endl;
        return -1;
    }
    T value = this->arr[this->front % this->maxSize];
    return value;
}


template <class T>
void displayOddNumbersInQueue(MyQueue<T> obj);
template <class T>
void displayEvenNumbersInQueue(MyQueue<T> obj);

int main()
{
    cout<<"Enter the size of queue: ";
    int size;
    cin>>size;
    if (size <= 0)
        cout<<"Invalid Size provided!"<<endl;
    else
    {
        MyQueue<int> obj(size+1);
        while (true)
        {
            cout<<"Enter your desired operations: "<<endl
                << "1 Check if queue is full or not" << endl
                << "2 Check if queue is empty or not" << endl
                << "3 Display queue" << endl
                << "4 enqueue data in the Queue" << endl
                << "5 dequeue data from Queue" << endl
                << "6 Check size of the Queue" << endl
                << "7 Display Peek value of the Queue" << endl
                << "8 Display Odd Numbers in the Queue" << endl
                << "9 Display Even Numbers in the Queue" << endl
                << "10 Exit" <<endl
            <<"Your choice: ";
            int ch;
            cin>>ch;
            if (ch == 1)
            {
                if (obj.isFull())
                {
                    cout<<"Queue is full!"<<endl;
                    cout<<"Press any key to continue!"<<endl;
                    getch();
                }
                else
                {
                    cout<<"Queue is not full!"<<endl;
                    cout<<"Press any key to continue!"<<endl;
                    getch();
                }
            }
            else if (ch == 2)
            {
                if (obj.isEmpty())
                {
                    cout<<"Queue is empty!"<<endl;
                    cout<<"Press any key to continue!"<<endl;
                    getch();
                }
                else
                {
                    cout<<"Queue is not empty!"<<endl;
                    cout<<"Press any key to continue!"<<endl;
                    getch();
                }
            }
            else if (ch == 3)
            {
                obj.display();
                cout<<"Press any key to continue!"<<endl;
                getch();
            }
            else if (ch == 4)
            {
                cout<<"Enter a value: ";
                int value;
                cin>>value;
                obj.enqueue(value);
                cout<<"Press any key to continue!"<<endl;
                getch();
            }
            else if(ch == 5)
            {
                cout<<obj.dequeue()<<endl;
                cout<<"Press any key to continue!"<<endl;
                getch();
            }
            else if (ch == 6)
            {
                cout<<obj.size()<<endl;
                cout<<"Press any key to continue!"<<endl;
                getch();
            }
            else if (ch == 7)
            {
                cout<<obj.peek()<<endl;
                cout<<"Press any key to continue!"<<endl;
                getch();
            }
            else if (ch == 8)
            {
                displayOddNumbersInQueue(obj);
                cout<<"Press any key to continue!"<<endl;
                getch();
            }
            else if (ch == 9)
            {
                displayEvenNumbersInQueue(obj);
                cout<<"Press any key to continue!"<<endl;
                getch();
            }
            else if (ch == 10)
            {
                cout<<"Program Exited!"<<endl;
                break;
            }
            else
            {
                cout<<"Invalid option provided!"<<endl;
                break;
            }
        }
    }
    return 0;
}

template <class T>
void displayOddNumbersInQueue(MyQueue<T> obj)
{
    cout<<"Odd values in the queue"<<endl;
    MyQueue<T> temp(obj);
    while (!temp.isEmpty())
    {
        T value = temp.dequeue();
        if (value % 2 != 0)
            cout<<value<<' ';
    }
    cout<<endl;
}
template <class T>
void displayEvenNumbersInQueue(MyQueue<T> obj)
{
    cout<<"Even values in the queue"<<endl;
    MyQueue<T> temp(obj);
    while (!temp.isEmpty())
    {
        T value = temp.dequeue();
        if (value % 2 == 0)
            cout<<value<<' ';
    }
    cout<<endl;
}