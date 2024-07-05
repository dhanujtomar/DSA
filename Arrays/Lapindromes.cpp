#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	string s = "rotor";
    int n = s.length();
	
    std::vector<int>a1(26,0);
    std::vector<int>a2(26,0);
    
    for(int i=0; i<n/2; i++){
        char c = s[i];
        int position = (int)c -97;
        a1[position]++;
    }
    for(int i=(n+1)/2; i<n; i++){
        char c = s[i];
        int position = (int)c -97;
        a2[position]++;
    }
    bool ans = true;
    for(int i=0; i<26; i++){
        if(a1[i]!=a2[i]){
            ans = false;
            break;
        }
    }
    cout << (ans?"YES":"NO") << endl;
}
