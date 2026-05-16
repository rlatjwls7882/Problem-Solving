#include<bits/stdc++.h>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    int n, m; cin >> n >> m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int cnt=0;
            for(int k=0;k<4;k++) {
                int nx=i+dx[k];
                int ny=j+dy[k];
                if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                cnt++;
            }
            cout << cnt << ' ';
        }
        cout << '\n';
    }
}