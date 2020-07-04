#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> arr;
void solve(){
    ll a,b,n,m;
    cin>>a>>b>>n>>m;
    if(n <= a && m <= b)
        cout<<"Yes\n";
    else
        cout<<"No\n";
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  #ifndef ONLINE_JUDGE
  freopen("D:/CP/input.txt","r",stdin);
  freopen("D:/CP/output.txt","w",stdout);
  #endif
  int t;
  cin>>t;
  while(t--)
    solve();
  return 0;
}
