#include <iostream>
#include <vector>

using namespace std;

int BSsqrt(int num)
{
    int s = 0, e = num;
    int mid = s + (e - s) / 2;
    int ans;

    while (s <= e)
    {
        long long int square = (long long int)mid*(long long int)mid;
        if (square == num)
        {
            return mid;
        }
        if (square > num)
        {
            e = mid - 1;
        }
        else if (square < num)
        {
            ans = mid;
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

double morePrecise(int n, int tempSol, int precision)
{
    double ans = tempSol;
    double factor = 1;
    for (int i = 0; i < precision; i++)
    {
        factor = factor / 10;
        for (double j = ans; j * j < n; j = j + factor)
        {
            ans = j;
        }
    }
    return ans;
}

int main()
{
    int num = 37;

    int tempSol = BSsqrt(num);
    cout << tempSol << endl;
    cout << morePrecise(num, tempSol, 3);
}