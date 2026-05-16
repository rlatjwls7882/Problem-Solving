#include<bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    long long res=0;
    for(int i=0;i<s.length();i++) {
        if(s[i]=='C') res+=min((int)s.length()-i, i+1);
    }
    cout << res;
}