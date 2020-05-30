#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define dbl double
#define endl "\n"
#define fo(i,n) for(int i=0; i<n; i++)
#define FOR(i,n,k) for(int i=0; i<n; i+=k)
#define sFOR(i,s,n) for(int i=s; i<n; i++)
#define vi vector<int>
#define SORT(v) sort(v.begin(),v.end())
#define REV(v) reverse(v.begin(),v.end())
#define eb(x) emplace_back(x)
#define UM unordered_map<int,int>
#define INF INT_MAX
#define NEG_INF INT_MIN
#define MOD 1000000000+7

int getAns(vi Alice, vi Bob){
  int ans = 0,posA = 0,posB = 0;
  int n = Alice.size();
  for(int i=0; i<n; i++){
    if(Alice[i] == Bob[i] && posA == posB){
      ans += Alice[i];
    }
    posA += Alice[i];
    posB += Bob[i];
  }
  return ans;
}
void solve(){
  int n;
  cin>>n;
  vi Alice(n),Bob(n);
  for(int i=0; i<n; i++)
    cin>>Alice[i];
  for(int i=0; i<n; i++)
    cin>>Bob[i];
  cout<<getAns(Alice,Bob)<<endl;
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
  while(t--){
    solve();
  }
  return 0;
}
