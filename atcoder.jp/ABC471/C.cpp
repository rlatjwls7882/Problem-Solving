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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;

    vector<int> min, plu;
    while(n--) {
        int a; cin >> a;
        if(a<0) min.push_back(a);
        else plu.push_back(a);
    }
    sort(all(min));
    sort(all(plu), greater<int>());

    ll res=0, x=0;
    while(sz(min) || sz(plu)) {
        if(plu.empty() || sz(min) && abs(x-min.back())<=abs(x-plu.back())) {
            res+=abs(x-min.back());
            x=min.back();
            min.pop_back();
        } else {
            res+=abs(x-plu.back());
            x=plu.back();
            plu.pop_back();
        }
    }
    cout << res;
}
