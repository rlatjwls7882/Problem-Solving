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
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> T sq(T x) { return x*x; }

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ld PI = acosl(-1);
const ld EPS = 1e-10;

mt19937 rd((unsigned)chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> rnd_int(0, 0); // rnd_int(rd)
uniform_real_distribution<double> rnd_real(0, 1); // rnd_real(rd)

using P=pair<ll, ll>;
istream& operator>>(istream& in, P& p){return in>>p.x>>p.y;}
P operator+(P a,P b){return {a.x+b.x,a.y+b.y};}
P operator-(P a,P b){return {a.x-b.x,a.y-b.y};}
ll operator*(P a,P b){return a.x*b.x+a.y*b.y;} // 내적
ll operator/(P a,P b){return a.x*b.y-a.y*b.x;} // 외적
int Sign(ll x){return (x>0)-(x<0);} // 양수면 1, 음수면 -1, 0이면 0 반환
ll Dist(P a,P b){return (a-b)*(a-b);} // 두 점 거리의 제곱
ll SignedArea(P a,P b,P c){return (b-a)/(c-a);}
int CCW(P a,P b,P c){return Sign(SignedArea(a,b,c));}
int Half(P p){return p.y<0||(p.y==0&&p.x<0);}

bool Intersect(P a,P b,P c,P d) {
    int ab=CCW(a,b,c)*CCW(a,b,d);
    int cd=CCW(c,d,a)*CCW(c,d,b);
    if(!ab&&!cd) {
        if(a>b) swap(a,b);
        if(c>d) swap(c,d);
        return !(b<c||d<a);
    }
    return ab<=0&&cd<=0;
}

bool Inside(P a, P b, P p) {
    return a.x<=p.x && p.x<=b.x && a.y<=p.y && p.y<=b.y;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        P l, r, p1, p2; cin >> l >> r >> p1 >> p2;
        vector<P> hull = {{l.x, l.y}, {l.x, r.y}, {r.x, r.y}, {r.x, l.y}};
        if(Intersect(p1, p2, {l.x, l.y}, {l.x, r.y}) || Intersect(p1, p2, {l.x, l.y}, {r.x, l.y}) || Intersect(p1, p2, {r.x, r.y}, {l.x, r.y}) || Intersect(p1, p2, {r.x, r.y}, {r.x, l.y}) || Inside(l, r, p1) || Inside(l, r, p2)) {
            cout << "STOP\n";
        } else {
            cout << "OK\n";
        }
    }
}
