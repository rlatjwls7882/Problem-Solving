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
#define compress(x) sort(all(x)), x.erase(unique(all(x)), x.end())

typedef long long ll;
typedef long double ld;
typedef __int128 i128;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> T sq(T x) { return x*x; }

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ld PI = acosl(-1);
const ld EPS = 1e-10;

mt19937 rd((unsigned)chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> rnd_int(0, 0); // rnd_int(rd)
uniform_real_distribution<double> rnd_real(0, 1); // rnd_real(rd)

vector<vi> conn(100'001);

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m;cin>>n>>m;
    while(m--){
        int u,v;cin>>u>>v;
        conn[u].push_back(v);
        conn[v].push_back(u);
    }

    ll res=0;
    vi vis(n+1, -1);
    for(int i=1;i<=n;i++){
        if(vis[i]==-1){
            queue<int> q;q.push(i);
            vll c(2);
            vis[i]=0;
            bool chk=true;
            while(!q.empty()){
                int cur=q.front();q.pop();
                c[vis[cur]&1]++;

                for(int nxt:conn[cur]){
                    if(vis[nxt]==-1){
                        vis[nxt]=vis[cur]+1;
                        q.push(nxt);
                    }else if((vis[nxt]&1)==(vis[cur]&1)){
                        chk=false;
                    }
                }
            }
            if(chk) res+=sq(c[0])+sq(c[1]);
            else res+=sq(c[0]+c[1]);
        }
    }
    cout<<res;
}
