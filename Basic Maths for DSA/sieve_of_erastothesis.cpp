#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num = 43;
    vector<bool> prime(num + 1, true);

    prime[0] = false;
    int lastprime;

    for (int i = 2; i <= num; i++)
    {
        if(prime[i]==false)
            continue;
        for (int j = 2; j <= num; j++)
        {
            prime[i * j] = false;
        }
        lastPrime = i;
    }

    int nextprime=-1;
    
    while(nextPrime==-1){
        if(prime[i]==false)
            continue;
        for (int j = 2; j <= num; j++)
        {
            prime[i * j] = false;
        }
    }
    
    for (int i = 0; i < num; i++)
    {
        if (prime[i])
        {
            cout << i << endl;
        }
    }


    return 0;
}