#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
    while (b > 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    int num1 = 750;
    int num2 = 250;

    int a = max(num1, num2);
    int b = min(num1, num2);

    cout << gcd(a, b) << endl;

    return 0;
}