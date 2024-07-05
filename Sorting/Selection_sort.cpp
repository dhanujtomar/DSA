#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
    // your code goes here
    int tc;
    int n;
    cin >> tc;
    cin >> n;
    int d[n];
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
        cout << d[i];
    }
    cout << endl;

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {

            if (d[minIndex] > d[j])
                minIndex = j;
        }
        swap(d[minIndex], d[i]);
    }

    for (int x : d)
    {
        cout << x << ",";
    }
}
