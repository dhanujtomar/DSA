#include <iostream>

using namespace std;

bool checkPalindrome(string &s, int i, int j)
{
    if (i > j)
    {
        return true;
    }
    if (s[i] != s[j])
        return false;
    return checkPalindrome(s, ++i, --j);
}

int main()
{
    string s = "abcba";

    cout << checkPalindrome(s, 0, s.length() - 1) << endl;
}