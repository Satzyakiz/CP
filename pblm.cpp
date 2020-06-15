#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long
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
ll solve(vector<int> &wt,vector<int> &val,int W){
  int m = wt.size();
  vector<vector<ll>> dp(m+1,vector<ll>(W+1));
  for(int i=1; i<=m; i++){
    for(int j=1; j<=W; j++){
      if(wt[i-1] <= j){
        dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
      }else{
        dp[i][j] = dp[i-1][j];
      }
    }
  }
  return dp[m][W];
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  #ifndef ONLINE_JUDGE
  freopen("D:/CP/input.txt","r",stdin);
  freopen("D:/CP/output.txt","w",stdout);
  #endif
  int n,W;
  cin>>n>>W;
  vector<int> wt(n);
  vector<int> val(n);
  for(int i=0; i<n; i++){
    cin>>wt[i]>>val[i];
  }
  cout<<solve(wt,val,W);
  return 0;
}
