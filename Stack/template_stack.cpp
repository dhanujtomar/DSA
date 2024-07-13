#include <iostream>

using namespace std;

template <typename T>
class Stack
{
    T *arr;
    int top;
    int size;

public:
    Stack(int size)
    {
        this->size = size;
        arr = new T[size];
        top = -1;
    }

    void push_back(T data)
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
            return (T)-1;
        }
        top--;
    }

    T peek()
    {
        if (isEmpty())
        {
            cout << "UnderFlow" << endl;
            return nullptr;
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
    Stack<string> s(3);
    s.push_back("1");
    s.push_back("2");
    s.push_back("3");
    s.push_back("4");
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