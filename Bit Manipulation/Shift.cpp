#include <iostream>
#include <stack>

using namespace std;

void swapNumbers(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

void checkSetBit(int n, int i)
{
    if ((n & (1 << i)) != 0)
    {
        cout << "ith bit is set";
    }
    else
    {
        cout << "ith bit is not set";
    }
    cout << endl;
}

void convert_to_binary(int n)
{
    stack<int> s;
    while (n)
    {
        s.push(n % 2);
        n = n / 2;
    }
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
}

int main()
{
    // swap numbers using bitwise
    int a = 17, b = 0;
    checkSetBit(a, b);
    convert_to_binary(17);
    return 0;
}