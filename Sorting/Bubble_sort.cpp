#include <bits/stdc++.h>

using namespace std;

int main()
{
    // your code goes here
    int n;
    int tc;
    cin >> tc;
    while (tc--)
    {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }

        for (int i = 0; i < n; i = i + 2)
        {
            cout << arr[i] << endl;
        }
    }
    return 0;
}