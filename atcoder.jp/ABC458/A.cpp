#include<bits/stdc++.h>
using namespace std;

int main() {
    string s; int n; cin >> s >> n;
    for(int i=n;i<s.length()-n;i++) cout << s[i];
}