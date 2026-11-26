#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("fma")
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define x firsta
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

int a[100'000];
vector<vi>conn(100'000);
bool vis[100'000];
int cnt;
ll m;

ll dfs(int cur){
    vis[cur]=true;
    ll ret=a[cur];
    bool chk=false;
    for(int nxt:conn[cur]){
        if(!vis[nxt]){
            ll cur=dfs(nxt);
            if(!chk) {
                if(cur+ret<=m)cnt++, chk=true;
                else ret=min(ret,cur);
            }
        }
    }
    vis[cur]=false;

    if(chk)return INT_MAX;
    else return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,k;cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        conn[u-1].push_back(v-1);
        conn[v-1].push_back(u-1);
    }

    ll l=0,r=INT_MAX;
    while(l<r){
        m=l+r>>1;
        cnt=0;
        dfs(0);
        if(cnt>=k)r=m;
        else l=m+1;
    }
    cout<<(r==INT_MAX?-1:r);
}
