#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int, int> m;
    int maxElement = 0;
    int maxFreq = 0;

    for (int i = 0; i < n; i++)
    {
        int element = arr[i];
        m[element]++;
        maxFreq = max(m[element], maxFreq);
    }

    for (int i = 0; i < n; i++)
    {
        int element = arr[i];
        if (m[element] == maxFreq)
        {
            maxElement = element;
            break;
        }
    }

    return maxElement;
}