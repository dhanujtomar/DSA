#include <bits/stdc++.h>
using namespace std;

// Fills lps[] for given pattern pat
void computeLPSArray(string &pat, int M, vector<int> &lps)
{
    // Length of the previous longest prefix suffix
    int prevLPS = 0;

    // lps[0] is always 0
    lps[0] = 0;

    // loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[prevLPS])
        {
            lps[i] = prevLPS + 1;
            prevLPS++;
            i++;
        }
        else
        {
            if (prevLPS == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
                prevLPS = lps[prevLPS - 1];
        }
    }
}

// Prints occurrences of pat in txt
vector<int> KMPSearch(string &pat, string &txt)
{
    int M = pat.length();
    int N = txt.length();

    vector<int> lps(M);

    vector<int> result;

    computeLPSArray(pat, M, lps);

    int i = 0; // index for txt
    int j = 0; // index for pat

    while ((N - i) >= (M - j))
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
        else
        {
            if (j == 0)
                i++;
            else
                j = lps[j - 1];
        }

        if (j == M)
        {
            result.push_back(i - j + 1);
            j = lps[j - 1];
        }
    }
    return result;
}

int main()
{
    string txt = "geeksforgeeks";
    string pat = "geeks";
    vector<int> result = KMPSearch(pat, txt);

    // Print all the occurance (1-based indices)
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}
