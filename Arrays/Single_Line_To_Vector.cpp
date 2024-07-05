#include <bits/stdc++.h>

#include <sstream>

using namespace std;

int main()
{
    string numbers = "2,5,7,4,1,4,5,2,3";
    stringstream str(numbers);
    vector<int> nums;

    int number;
    while (str >> number)
    {
        nums.push_back(number);
    }
    sort(nums.begin() + 1, nums.end());
    nums.erase(nums.begin());

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums.at(i);
    }

    return 0;
}