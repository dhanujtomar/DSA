#include <iostream>

using namespace std;

class Stack
{
    int *arr;
    int top;
    int size;

public:
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push_back(int data)
    {
        if (isFull())
        {
            cout << "Stack overflow" << endl;
            return;
        }
        top++;
        arr[top] = data;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "UnderFlow" << endl;
            return;
        }
        top--;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "UnderFlow" << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == size - 1;
    }
};

int main()
{
    Stack s(3);
    s.push_back(1);
    s.push_back(2);
    s.push_back(3);
    s.push_back(4);
    cout << s.peek();
    s.pop();
    cout << s.peek();
    s.pop();
    cout << s.peek() << endl;
    s.pop();
    cout << s.peek() << endl;
    s.pop();
    return 0;
}