#include <iostream>
#include <deque>
#include <queue>

using namespace std;
void print(queue<int> d);

void reverse(queue<int> &d)
{
    queue<int> q;
    if (d.empty())
    {
        return;
    }
    int num = d.front();
    d.pop();
    reverse(d);
    d.push(num);
}

int main()
{
    queue<int> d;
    d.push(4);
    d.push(2);
    d.push(3);
    d.push(1);
    d.push(5);
    d.push(6);

    print(d);
    reverse(d);
    print(d);

    return 0;
}

void print(queue<int> d)
{
    while (!d.empty())
    {
        cout << d.front();
        d.pop();
    }
    cout << endl;
}