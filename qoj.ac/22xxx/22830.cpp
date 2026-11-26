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

int a[2][100'000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;cin>>n;
    if(n%2==0)return !(cout<<-1);
    if(n==1)return !(cout<<"1\n1");

    pii st={-1,-1};
    vector<vector<int>> seat(2);
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            if(!a[i][j])st={i,j};
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            if(st.y!=j)seat[i].push_back(a[i][j]);
        }
    }

    vi res;
    if(st.x==0)res.push_back(a[1][st.y]);

    for(int i=0;i<n-1;i+=2){
        res.push_back(seat[0][i+1]);
        res.push_back(seat[1][i+1]);
        res.push_back(seat[0][i]);
        res.push_back(seat[1][i]);
        res.push_back(seat[1][i+1]);
        res.push_back(seat[0][i+1]);
        res.push_back(a[st.x^1][st.y]);
        res.push_back(seat[0][i]);
        res.push_back(seat[0][i+1]);
        res.push_back(seat[1][i+1]);
        res.push_back(seat[0][i]);
        res.push_back(a[st.x^1][st.y]);
    }
    if(st.x==1)res.push_back(a[0][st.y]);

    cout<<res.size()<<'\n';
    for(auto e:res)cout<<e<<' ';
}
