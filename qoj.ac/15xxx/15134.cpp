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

int b[17];
int dp[1<<17][101];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for(int i=0;i<n-1;i++) cin >> b[i];

    memset(dp, -1, sizeof dp);
    for(int i=1;i<=100;i++) dp[0][i]=-2;
    for(int i=0;i<(1<<n-1);i++) {
        for(int j=1;j<=100;j++) {
            if(dp[i][j]==-1) continue;
            for(int k=0;k<n-1;k++) {
                if(i&(1<<k) || b[k]%j || b[k]/j>100 || b[k]/j<1) continue;
                dp[i|(1<<k)][b[k]/j]=k;
            }
        }
    }

    for(int i=1;i<=100;i++) {
        int vis=(1<<n-1)-1;
        if(dp[vis][i]!=-1) {
            cout << "Yes\n";
            cout << i;
            while(vis) {
                int k=dp[vis][i];
                i=b[k]/i;
                vis-=1<<k;
                cout << ' ' << i;
            }
            return 0;
        }
    }
    cout << "No";
}
