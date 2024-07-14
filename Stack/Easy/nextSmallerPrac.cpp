#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    vector<int> arr = {4, 1, 3, 2, 1, 6, 3, 7};
    int n = arr.size();
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int element = arr[i];
        while (s.top() != -1 && s.top() >= element)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(element);
    }

    for (int x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}