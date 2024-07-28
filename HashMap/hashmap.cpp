#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    // Creation
    unordered_map<string, int> m;

    // Insertion using

    // Pair
    pair<string, int> p1 = {"babbar", 3};
    m.insert(p1);

    pair<string, int> p2("love",2);
    m.insert(p2);

    pair<string, int> p3 = make_pair("DSA", 4);
    m.insert(p3);

    m["course"] = 1;

    return 0;
}