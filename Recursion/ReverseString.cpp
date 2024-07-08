#include <iostream>

using namespace std;

void reverseStringOpt(string &s, int i, int j)
{
    if (j > i)
    {
        return;
    }
    i++;
    j--;

    reverseStringOpt(s, i, j);
}

int main()
{
    string s = "abcde";
    int n = s.length();

    reverseStringOpt(s, 0, n - 1);
    cout << s << endl;
}