#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

int main()
{
    string path = "/../";

    stack<string> s;

    stringstream sPath(path);
    string dir;

    int countP = 0;

    while (getline(sPath, dir, '/'))
    {
        if (!s.empty() && dir == "..")
        {
            s.pop();
            continue;
        }
        else if (dir == "" || dir == "." || dir == "..")
        {
            continue;
        }
        s.push(dir);
    }
    string ans = "";
    int count = 0;

    while (!s.empty())
    {
        ans = "/" + s.top() + ans;
        s.pop();
        count++;
    }
    if (ans == "")
        cout << "/";
    else
        cout << ans;

    return 0;
}