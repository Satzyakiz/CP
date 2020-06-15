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
#define MOD 1000000007

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  #ifndef ONLINE_JUDGE
  freopen("D:/CP/input.txt","r",stdin);
  freopen("D:/CP/output.txt","w",stdout);
  #endif
  int r,c;
  cin>>r>>c;
  vector<vector<char>> mat(r+1,vector<char>(c+1));
  vector<vector<ll>> dp(r+1,vector<ll>(c+1,0));
  for(int i=1; i<=r; i++){
    for(int j=1; j<=c; j++){
      cin>>mat[i][j];
    }
  }
  dp[1][1] = 1;
  for(int i=2; i<=r; i++){
    if(mat[i][1] != '#')
      dp[i][1] = dp[i-1][1];
  }
  for(int j=2; j<=c; j++){
    if(mat[1][j] != '#')
      dp[1][j] = dp[1][j-1];
  }
  for(int i=2; i<=r; i++){
    for(int j=2; j<=c; j++){
      if(mat[i][j] != '#'){
          dp[i][j] = (dp[i-1][j]+dp[i][j-1])%MOD;

      }
    }
  }

  cout<<dp[r][c]%MOD;
  return 0;
}
