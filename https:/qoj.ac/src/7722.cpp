#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    int row = n/k;

    vector<vector<int>> res(k+1);

    if(row==1) {
        for(int i=1;i<=k;i++) res[i].push_back(i);
    } else if(row%2==0) {
        int l=1, r=n;
        for(int i=1;i<=k;i++) {
            for(int cnt=0;cnt<row/2;cnt++) res[i].push_back(l++);
            for(int cnt=0;cnt<row/2;cnt++) res[i].push_back(r--);
        }
    } else {
        for(int i=1;i<=k;i++) res[i].push_back(i);

        if(k%2) {
            for(int i=1;i<=k/2+1;i++) res[i].push_back(3*k-k/2-1+i);
            for(int i=k/2+2;i<=k;i++) res[i].push_back(3*k-k+(i-k/2-1));

            for(int i=1;i<=k/2+1;i++) res[i].push_back(k+1+2*(k/2+1-i));
            for(int i=k/2+2;i<=k;i++) res[i].push_back(k+2+2*(k-i));
        } else {
            for(int i=1;i<=k/2;i++) res[i].push_back(3*k-k/2+i);
            for(int i=k/2+1;i<=k;i++) res[i].push_back(3*k-k+(i-k/2));

            for(int i=1;i<=k/2;i++) res[i].push_back(k+2*(k/2-i+1));
            for(int i=k/2+1;i<=k;i++) res[i].push_back(k+1+2*(k-i));
        }

        for(int i=5;i<=row;i+=2) {
            for(int j=1;j<=k;j++) {
                res[j].push_back((i-2)*k+j);
                res[j].push_back(i*k+1-j);
            }
        }
    }

    for(int i=1;i<=k;i++) {
        for(int e : res[i]) cout << e << ' ';
        cout << '\n';
    }
}
