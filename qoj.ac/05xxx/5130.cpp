#include<bits/stdc++.h>
using namespace std;

typedef long double ld;

unordered_map<char, ld> dir = {
    {'N', 0},
    {'E', 90},
    {'S', 180},
    {'W', 270}
};

ld getDir(string s) {
    ld moveAng = 45;
    ld cur = dir[s.back()];
    for(int i=s.length()-2;i>=0;i--) {
        int next = dir[s[i]];
        if(s[i]=='N' && cur>=270) next = 360;

        if(next>cur) cur += moveAng;
        else cur -= moveAng;
        moveAng/=2;
    }
    return cur;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string x, y; cin >> x >> y;
    ld a = getDir(x), b = getDir(y);
    cout << fixed << setprecision(6) << min(max(a, b)-min(a, b), min(a, b)-max(a, b)+360);
}
