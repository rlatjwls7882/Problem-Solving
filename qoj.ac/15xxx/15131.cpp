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

const ll MOD = 10'000'000'000;
const ll MOD1 = 15'000'000'000;
const ll MOD2 = 4'000'000'000;
const ll MOD3 = 1'600'000'000;

ll p(i128 a, ll n, ll M) {
    i128 r=1;
    while(n) {
        if(n&1) r=r*a%M;
        n>>=1;
        a=a*a%M;
    }
    return r;
}

pll fib(ll n) {
    if(n==0) return {0, 1};
    auto [a, b]=fib(n>>1);
    ll c=(i128)a*(2*b-a+MOD)%MOD;
    ll d=((i128)a*a+(i128)b*b)%MOD;
    if(n&1) return {d, c+d};
    return {c, d};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        ll k = p(7, p(7, p(7, n, MOD3), MOD2), MOD1);
        auto [a, b]=fib(k);
        string s=to_string(a);
        cout << string(10-sz(s), '0') << s << '\n';
    }
}
