#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("fma")
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define x first
#define y second
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rep(x) for(int __i=(x);__i>0;--__i)
#define compress(x) sort(all(x)), x.erase(unique(all(x)), x.end())

typedef long long ll;
typedef long double ld;
typedef __int128 i128;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> T sq(T x) { return x*x; }

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ld PI = acosl(-1);
const ld EPS = 1e-10;

mt19937 rd((unsigned)chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> rnd_int(0, 0); // rnd_int(rd)
uniform_real_distribution<double> rnd_real(0, 1); // rnd_real(rd)

int n, m, k, u1, v1, u2, v2;
int stone[501][501];
bool vis[501][501];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool solve(int b) {
    queue<pii> q; q.push({u1, v1});
    memset(vis, 0, sizeof vis);
    vis[u1][v1]=true;
    int blank=0;
    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if(!stone[x][y]) blank++;
        for(int i=0;i<4;i++) {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<=0 || nx>n || ny<=0 || ny>m || vis[nx][ny] || stone[nx][ny]>b) continue;
            vis[nx][ny]=true;
            q.push({nx, ny});
        }
    }
    return blank>=(u2-u1+1)*(v2-v1+1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i=1;i<=k;i++) {
        int x, y; cin >> x >> y;
        stone[x][y]=i;
    }
    cin >> u1 >> v1 >> u2 >> v2;

    int l=0, r=k+1;
    for(int i=u1;i<=u2;i++) for(int j=v1;j<=v2;j++) l=max(l, stone[i][j]);
    while(l<r) {
        int m=l+r>>1;
        if(solve(m)) r=m;
        else l=m+1;
    }
    cout << (l==k+1 ? -1 : l);
}
