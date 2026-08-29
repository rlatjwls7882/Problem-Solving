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

int n, k;
vector<int> a;
vector<vector<int>> r;

void dfs(int dep, int sum) {
    if(dep==0) {
        a[0]=k-sum;
        r.push_back(a);
        return;
    }
    for(int i=0;sum+(dep+1)*i<=k;i++) {
        a[dep]=i;
        dfs(dep-1, sum+(dep+1)*i);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>k;
    a=vector<int>(n);
    dfs(n-1,0);
    sort(all(r));
    for(auto a:r) {
        for(auto e:a) cout << e << ' ';
        cout << '\n';
    }
}
