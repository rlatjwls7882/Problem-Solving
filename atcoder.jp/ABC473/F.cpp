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

const int MAX=500'001;
ll SZ=1,a[MAX*4],lz[MAX*4];
void push(int p) {
    if(!lz[p]) return;
    a[p]+=lz[p];
    if(p<SZ) lz[p<<1]+=lz[p], lz[p<<1|1]+=lz[p];
    lz[p]=0;
}
void update(int L,int R,ll x,int p=1,int l=0,int r=SZ-1) {
    push(p);
    if(R<l||r<L) return;
    if(L<=l&&r<=R) {lz[p]+=x; push(p); return;}
    int m=l+r>>1;
    update(L,R,x,p<<1,l,m);
    update(L,R,x,p<<1|1,m+1,r);
    a[p]=min(a[p<<1],a[p<<1|1]);
}
ll query(int L,int R,int p=1,int l=0,int r=SZ-1){
    push(p);
    if(R<l||r<L) return LLONG_MAX;
    if(L<=l&&r<=R) return a[p];
    int m=l+r>>1;
    return min(query(L,R,p<<1,l,m), query(L,R,p<<1|1,m+1,r));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; string s; cin >> n >> s;
    while(SZ<n) SZ<<=1;

    int l=0;
    for(int i=0;i<n;i++) {
        if(s[i]=='A') l++;
        else l--;
        a[SZ+i]=l;
    }
    for(int i=SZ-1;i>=0;i--) a[i]=min(a[i*2], a[i*2+1]);

    int q; cin >> q;
    while(q--) {
        int o,i,l,r;char c; cin>>o;
        if(o==1) {
            cin>>i>>c;
            if(s[i-1]!=c) {
                s[i-1]=c;
                if(c=='A') update(i-1, n-1, 2);
                else update(i-1, n-1, -2);
            }
        } else {
            cin>>l>>r;
            cout << (query(l-1, r-1)-(l-2>=0 ? query(l-2, l-2) : 0)>=0 ? "Yes\n" : "No\n");
        }
    }
}
