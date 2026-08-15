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

int dp[100000][21];

bool leq(string &a, string &b) {
    return sz(a)<sz(b) || sz(a)==sz(b) && a<=b;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s, b; cin >> s >> b;

    fill(&dp[0][0], &dp[s.length()][0], INF);
    string tmp;
    for(int i=1;i<=b.length();i++) {
        tmp = s.substr(0, i);
        if(leq(tmp, b)) dp[0][i]=0;
    }
    for(int i=1;i<s.length();i++) {
        for(int j=i;j>=i-20 && j>=0;j--) {
            tmp=s.substr(j, i-j+1);
            if(!leq(tmp, b) || tmp[0]=='0') continue;
            if(j==0) dp[i][i-j+1]=0;
            else {
                for(int k=1;k<=20 && j-k>=0;k++) {
                    if(dp[j-1][k]==INF) continue;
                    string tmp2=s.substr(j-k, k);
                    if(leq(tmp2, tmp)) dp[i][i-j+1]=min(dp[i][i-j+1], dp[j-1][k]+1);
                }
            }
        }
    }

    int res=INF;
    for(int i=1;i<21;i++) res=min(res, dp[s.length()-1][i]);
    if(res==INF) cout << "NO WAY";
    else cout << res;
}15183
