#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

const int n = 1e5 + 7, m = 1e9 + 7;
const int p = 13;
vector<int> power(n);

void powers()
{
    power[0] = 1;
    for (int i = 1; i < n; i++)
    {
        power[i] = (power[i - 1] * p) % m;
    }
}

class Hash
{
    long long hash;
    int prime;
    int size;
    int m;

public:
    Hash() : hash(0), size(0), prime(p), m(1e9 + 7) {}

    void createHash(string &s)
    {
        size = s.size();
        for (int i = 0; i < size; i++)
        { // ABCD
            hash += ((s[i] - 'a' + 1) * power[i]);
        }
    }

    void updateHash(char old, char newCh)
    {
        long long oldVal = old - 'a' + 1;
        long long newVal = newCh - 'a' + 1;

        hash = (hash - oldVal) / prime; // remove old contribution

        hash = (hash + newVal * power[size - 1]); // add new
    }

    long long getHash()
    {
        return hash;
    }
};

int main()
{
    powers();

    Hash h1, h2;
    string s1 = "geeksforgeeks";
    string s2 = "geeksgeeksfor";

    // egbvfklr
    // bvfklreg
    int n = 5;
    cout << s2[n] << endl;

    h1.createHash(s1);
    h2.createHash(s2);
    for (int i = 0; i < n; i++)
        h2.updateHash(s2[i], s2[i]);

    cout << s1 << ": " << h1.getHash() << endl;
    cout << s2 << ": " << h2.getHash() << endl;

    // cout << power[s1.size() - 1];

    return 0;
}