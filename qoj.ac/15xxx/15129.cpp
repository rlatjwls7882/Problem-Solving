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

const ll MOD = 1e9+7;
const ll INV = 500000004;
string s[100];
int dx[]={0,0,1,-1,1,1,-1,-1};
int dy[]={1,-1,0,0,1,-1,1,-1};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n, m, d0, d1, d2; cin >> n >> m >> d0 >> d1 >> d2;
    for(int i=0;i<n;i++) cin >> s[i];

    ll r=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            ll a=1;
            if(s[i][j]=='V') a=0;
            else if(s[i][j]=='?') a=INV;

            ll b=1;
            for(int k=0;k<4;k++) {
                int nx=dx[k]+i;
                int ny=dy[k]+j;
                if(nx<0||nx>=n||ny<0||ny>=m||s[nx][ny]=='.')continue;
                if(s[nx][ny]=='V') b=0;
                else b=b*INV%MOD;
            }

            ll c=1;
            for(int k=4;k<8;k++) {
                int nx=dx[k]+i;
                int ny=dy[k]+j;
                if(nx<0||nx>=n||ny<0||ny>=m||s[nx][ny]=='.')continue;
                if(s[nx][ny]=='V') c=0;
                else c=c*INV%MOD;
            }
            r = (r + d0*(1+MOD-a) + d1*a%MOD*(1+MOD-b) + d2*a%MOD*b%MOD*(1+MOD-c))%MOD;
        }
    }
    cout << r;
}
