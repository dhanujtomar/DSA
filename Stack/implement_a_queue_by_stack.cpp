#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void printVec(vector<int> arr);
void print(stack<int>);

void toBottom(stack<int> &s, int element)
{
    if (s.empty())
    {
        s.push(element);
        return;
    }
    int num = s.top();
    s.pop();
    toBottom(s, element);
    s.push(num);
}

void reverseStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int num = s.top();
    s.pop();
    reverseStack(s);
    toBottom(s, num);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    stack<int> s;

    for (int i = 0; i < arr.size(); i++)
    {
        s.push(arr[i]);
    }

    printVec(arr);
    print(s);

    reverseStack(s);

    print(s);

    return 0;
}

void print(stack<int> s)
{
    cout << "Stack: " << endl;
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl
         << endl;
}

void printVec(vector<int> arr)
{
    cout << "Vector: " << endl;
    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << endl
         << endl;
}