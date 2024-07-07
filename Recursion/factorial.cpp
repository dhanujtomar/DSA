#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n <= 2)
    {
        return n;
    }
    return n * factorial(n - 1);
}

int main()
{
    int n = 5;
    cout << "factorial of " << n << " is: " << factorial(n);
    return 0;
}