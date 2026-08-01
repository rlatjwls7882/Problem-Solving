#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef long long ll;

int n,m,k;
bool vis[1000][1000];
string s[1000];

bool chk() {
    memset(vis, 0, sizeof vis);
    for(int i=0;i+k-1<n;i++) {
        for(int j=0;j+k-1<m;j++) {
            bool up=true, left=true, right=true, bottom=true;
            for(int kk=0;kk<k;kk++) {
                if(!(s[i][j+kk]=='#' && !vis[i][j+kk])) {
                    up=false;
                    break;
                }
            }
            for(int kk=0;kk<k;kk++) {
                if(!(s[i+kk][j]=='#' && !vis[i+kk][j])) {
                    left=false;
                    break;
                }
            }
            for(int kk=0;kk<k;kk++) {
                if(!(s[i+kk][j+k-1]=='#' && !vis[i+kk][j+k-1])) {
                    right=false;
                    break;
                }
            }
            for(int kk=0;kk<k;kk++) {
                if(!(s[i+k-1][j+kk]=='#' && !vis[i+k-1][j+kk])) {
                    bottom=false;
                    break;
                }
            }
            if(up) {
                if(left && right) {
                    for(int kk=0;kk<k;kk++) {
                        vis[i][j+kk]=true;
                    }
                    for(int kk=0;kk<k;kk++) {
                        vis[i+kk][j]=true;
                    }
                    for(int kk=0;kk<k;kk++) {
                        vis[i+kk][j+k-1]=true;
                    }
                } else if(left && bottom) {
                    for(int kk=0;kk<k;kk++) {
                        vis[i][j+kk]=true;
                    }
                    for(int kk=0;kk<k;kk++) {
                        vis[i+kk][j]=true;
                    }
                    for(int kk=0;kk<k;kk++) {
                        vis[i+k-1][j+kk]=true;
                    }
                } else if(right && bottom) {
                    for(int kk=0;kk<k;kk++) {
                        vis[i][j+kk]=true;
                    }
                    for(int kk=0;kk<k;kk++) {
                        vis[i+kk][j+k-1]=true;
                    }
                    for(int kk=0;kk<k;kk++) {
                        vis[i+k-1][j+kk]=true;
                    }
                }
            } else if(left && right && bottom) {
                for(int kk=0;kk<k;kk++) {
                    vis[i+kk][j]=true;
                }
                for(int kk=0;kk<k;kk++) {
                    vis[i+kk][j+k-1]=true;
                }
                for(int kk=0;kk<k;kk++) {
                    vis[i+k-1][j+kk]=true;
                }
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(s[i][j]=='#' && !vis[i][j]) return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--) {
        cin>>n>>m>>k;
        for(int i=0;i<n;i++)cin>>s[i];
        cout << (chk() ? "yes\n":"no\n");
    }
}
