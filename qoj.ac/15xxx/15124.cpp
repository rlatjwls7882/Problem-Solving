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

struct Dinic { // O(V²E), 모든 간선의 용량이 1이면 O(min(V^(2/3), √E)E)
    struct Edge {
        int to, rev;
        ll c;
    };
    const int S, E;
    vector<int> level, work;
    vector<vector<Edge>> conn;
    ll total=0;
    Dinic(int SZ, int s, int e) : S(s), E(e), work(SZ), level(SZ), conn(SZ) {}

    void edge(int u, int v, ll cap) {
        conn[u].push_back({v, (int)conn[v].size(), cap});
        conn[v].push_back({u, (int)conn[u].size()-1, 0});
    }

    bool bfs() {
        fill(level.begin(), level.end(), -1);
        queue<int> q; q.push(S);
        level[S]=0;
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            for(Edge &next:conn[cur]) {
                if(level[next.to]==-1 && next.c) {
                    level[next.to]=level[cur]+1;
                    q.push(next.to);
                }
            }
        }
        return level[E]!=-1;
    }

    ll dfs(int cur, ll curFlow) {
        if(cur==E) return curFlow;
        for(int &i=work[cur];i<conn[cur].size();i++) {
            Edge &next=conn[cur][i];
            if(level[next.to]==level[cur]+1 && next.c) {
                ll flow = dfs(next.to, min(curFlow, next.c));
                if(flow) {
                    next.c-=flow;
                    conn[next.to][next.rev].c+=flow;
                    return flow;
                }
            }
        }
        return 0;
    }

    ll res() {
        ll flow;
        while(bfs()) {
            fill(work.begin(), work.end(), 0);
            while(flow=dfs(S, LINF)) total+=flow;
        }
        return total;
    }
};

int a[500][500];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> a[i][j];

    int s=n*n, e=n*n+1;
    int col=e+1, row=col+n;
    Dinic dinic(row+n, s, e);
    int res=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            int cur=i*n+j;
            if(a[i][j]==0) {
                dinic.edge(col+i, cur, 1);
                dinic.edge(row+j, cur, 1);
                dinic.edge(cur, e, 1);
            } else if(a[i][j]>1) {
                res+=2*(a[i][j]-1);
                dinic.edge(s, cur, a[i][j]-1);
                dinic.edge(cur, col+i, a[i][j]-1);
                dinic.edge(cur, row+j, a[i][j]-1);
            }
        }
    }
    cout << res-dinic.res();
}
