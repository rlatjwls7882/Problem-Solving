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

ll l[2000], r[2000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n, m, d, x; cin >> n >> m >> d >> x;

    ll len=x+d*n;
    for(int i=0;i<n;i++) {
        cin >> l[i] >> r[i];
        len+=r[i]-l[i]+1;
    }
    if(len>m) return !(cout << -1);

    ll res=LINF;
    for(int i=0;i<=n;i++) {
        ll cur=0, rem=x+2*d-((i<n?l[i]-1:m)-(i-1>=0?r[i-1]:0))-(i==0 || i==n ? d : 0), L=i, R=i, lw=i-1>=0?1:LINF, rw=i<n?1:LINF;
        while(rem>0) {
            if(lw<rw) {
                ll lmv=L-2>=0 ? l[L-1]-r[L-2]-1-d : l[L-1]-1;
                ll cnt=min(lmv, rem);
                cur+=cnt*lw;
                rem-=cnt;
                L--;
                lw=L-1>=0?lw+1:LINF;
            } else {
                ll rmv=R+1<n ? l[R+1]-r[R]-1-d : m-r[R];
                ll cnt=min(rmv, rem);
                cur+=cnt*rw;
                rem-=cnt;
                R++;
                rw=R<n?rw+1:LINF;
            }
        }
        res=min(res, cur);
    }
    cout << res;
}
