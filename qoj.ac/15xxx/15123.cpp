#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

ll d, n, k;
bool vis[200'001];
vector<vector<pll>> conn(200'001), child(200'001);

pll dfs(int cur) { // cost, kk
    ll rk=0, mx1=0, mx2=0;
    for(auto [nxt, l]:child[cur]) {
        auto [cost, kk] = dfs(nxt);
        rk+=kk;
        if(cost+l<=d) {
            if(mx1<cost+l) {
                mx2=mx1;
                mx1=cost+l;
            } else if(mx2<cost+l) {
                mx2=cost+l;
            }
        } else {
            rk++;
            if(mx1<l) {
                mx2=mx1;
                mx1=l;
            } else if(mx2<l) {
                mx2=l;
            }
        }
        if(rk>k) return {0, rk};
    }
    if(mx1+mx2>d) mx1=0, rk++;
    return {mx1, rk};
}

void buildTree(int cur) {
    vis[cur]=true;
    for(auto [nxt, l]:conn[cur]) {
        if(!vis[nxt]) {
            child[cur].push_back({nxt, l});
            buildTree(nxt);
        }
    }
}

bool solve(ll m) {
    d=m;
    auto [cost, kk]=dfs(1);
    return kk<=k;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    ll mx=0, sum=0;
    for(int i=0;i<n-1;i++) {
        int u, v, l; cin >> u >>  v>> l;
        conn[u].push_back({v, l});
        conn[v].push_back({u, l});
        sum+=l;
        mx=max(mx,(ll)l);
    }
    buildTree(1);

    ll l=mx, r=1'000'000'000'000'000;
    while(l<r) {
        ll m=l+r>>1;
        if(solve(m)) r=m;
        else l=m+1;
    }
    cout << l;
}
