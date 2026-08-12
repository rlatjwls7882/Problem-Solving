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

int inD[200'000];
vector<vi> conn(200'000);

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    while(m--) {
        int a, b; cin >> a >> b;
        conn[a-1].push_back(b-1);
        inD[b-1]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<n;i++) {
        if(!inD[i]) pq.push(i);
    }

    vi r;
    while(!pq.empty()) {
        int cur=pq.top(); pq.pop();
        r.push_back(cur);
        for(int nxt:conn[cur]) {
            if(--inD[nxt]==0) pq.push(nxt);
        }
    }
    if(sz(r)==n) for(auto e:r) cout << e+1 << ' ';
    else cout << "IMPOSSIBLE";
}
