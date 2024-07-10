#include <iostream>

using namespace std;

class Solution
{
public:
    bool solve(int n)
    {
        if (n == 1)
        {
            return true;
        }
        if (n % 3 != 0)
        {
            return false;
        }
        return solve(n / 3);
    }
    bool isPowerOfThree(int n)
    {
        if (n <= 0)
        {
            return false;
        }
        return solve(n);
    }
};

int main()
{
    Solution s;
    int num = 27;
    cout << s.isPowerOfThree(num);
    return 0;
}