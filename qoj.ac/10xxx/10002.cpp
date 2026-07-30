#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("fma")
using namespace std;
#define all(x) x.begin(), x.end()
#define x first
#define y second

typedef pair<int, int> pii;

int cnt;
queue<pii> q;
string s[2000];
string dir="URDL";
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
vector<int> L[2001], R[2001], U[2001], D[2001];
vector<vector<vector<int>>> par(4, vector<vector<int>>(2001, vector<int>(2001)));

void update(int i, int j) {
    cnt++;
    q.push({i, j});
}

int find(vector<int> &par, int x) {
    if(x<0 || x>=par.size()) return x;
    if(x==par[x]) return x;
    return par[x]=find(par, par[x]);
}

int erase(vector<int> &par, int i, int dir) {
    if(i<0 || i>=par.size()) return i;
    if(dir==0) par[i]=find(par, i+1);
    else par[i]=find(par, i-1);
    return find(par, i);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    for(int i=0;i<n;i++) cin >> s[i];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(s[i][j]=='R') R[i].push_back(j);
            else if(s[i][j]=='L') L[i].push_back(j);
            else if(s[i][j]=='U') U[j].push_back(i);
            else D[j].push_back(i);
        }
    }
    for(int j=0;j<m;j++) sort(all(U[j])), sort(all(D[j]));
    for(int i=0;i<4;i++) for(int j=0;j<2001;j++) for(int kk=0;kk<2001;kk++) par[i][j][kk]=kk;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            for(int d=0;d<4;d++) {
                if(dir[d]==s[i][j]) {
                    int nx=dx[d]*k+i;
                    int ny=dy[d]*k+j;
                    if(nx<0 || nx>=n || ny<0 || ny>=m) {
                        if(d==0) erase(par[d][j], lower_bound(all(U[j]), i)-U[j].begin(), 0);
                        else if(d==1) erase(par[d][i], lower_bound(all(R[i]), j)-R[i].begin(), 1);
                        else if(d==2) erase(par[d][j], lower_bound(all(D[j]), i)-D[j].begin(), 1);
                        else erase(par[d][i], lower_bound(all(L[i]), j)-L[i].begin(), 0);
                        update(i, j);
                    }
                }
            }
        }
    }
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        auto i = lower_bound(all(L[cur.x]), cur.y)-L[cur.x].begin();
        int x=find(par[3][cur.x], i);
        while(0<=x && x<L[cur.x].size() && L[cur.x][x]<=cur.y+k) {
            update(cur.x, L[cur.x][x]);
            x=erase(par[3][cur.x], x, 0);
        }

        i = upper_bound(all(R[cur.x]), cur.y)-R[cur.x].begin()-1;
        x=find(par[1][cur.x], i);
        while(0<=x && x<R[cur.x].size() && R[cur.x][x]>=cur.y-k) {
            update(cur.x, R[cur.x][x]);
            x=erase(par[1][cur.x], x, 1);
        }

        i = lower_bound(all(U[cur.y]), cur.x)-U[cur.y].begin();
        x=find(par[0][cur.y], i);
        while(0<=x && x<U[cur.y].size() && U[cur.y][x]<=cur.x+k) {
            update(U[cur.y][x], cur.y);
            x=erase(par[0][cur.y], x, 0);
        }

        i = upper_bound(all(D[cur.y]), cur.x)-D[cur.y].begin()-1;
        x=find(par[2][cur.y], i);
        while(0<=x && x<D[cur.y].size() && D[cur.y][x]>=cur.x-k) {
            update(D[cur.y][x], cur.y);
            x=erase(par[2][cur.y], x, 1);
        }
    }
    cout << cnt;
}
/*
5 5 2
DDDRD
DDDDD
RDLUL
UURUU
UUUUU

*/
