#include "MyQueue.cpp"

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