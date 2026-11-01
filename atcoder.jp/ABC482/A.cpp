#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;cin>>s;
  int cnt=0;
  for(auto e:s)cnt+=e=='o';
  cout <<(cnt%2==0?"even":"odd");
}
