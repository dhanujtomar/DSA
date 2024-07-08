#include <iostream>

using namespace std;

int power(int n, int m)
{
    if (m == 0)
    {
        return 1;
    }
    if (m == 1)
    {
        return n;
    }

    int ans = power(n, m / 2);

    if (m % 2 == 0)
        return ans * ans;
    else
        return ans * ans * n;
}

int main()
{
    int n, m;
    n = 5;
    m = 4;

    cout << power(n, m);
    return 0;
}