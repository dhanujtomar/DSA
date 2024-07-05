#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

int main()
{
    // your code goes here
    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        std::sort(arr, arr + n);

        int max = 1;
        int temp = 1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == arr[i + 1])
            {
                temp++;
                max = std::max(temp, max);
            }
            else
            {
                temp = 1;
            }
        }

        cout << n - max << endl;
        // Replace all other numbers in the dataset with the most frequently occurring number.
        //  fequency of number appearing the most - total number
    }
}