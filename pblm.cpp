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

unordered_map<string,bool> um;

int eggDrop(int eggs,int floors){
  if(floors == 0 || floors == 1) return floors;
  if(eggs == 1) return floors;
  vector<vector<int>> dp(eggs+1,vector<int> (floors+1));
  //Initialization
  for(int i=0; i<eggs+1; i++){
    dp[i][0] = 0;
    dp[i][1] = 1;
  }
  for(int j=0; j<floors+1; j++){
    dp[1][j] = j; //If 1 egg is there, we would req j no of tries
    //to determine the egg would break or not
    //where j is the no of floors
  }
  int minVal = INT_MAX;
  for(int i=2; i<eggs+1; i++){ // No of eggs at an instant
    for(int j=2; j<floors+1; j++){ //Current max no of floors at an instant
      dp[i][j] = INT_MAX;
      for(int x=1; x<=j; x++){ //Current floor no upto j floors
        int temp = 1 + max(dp[i-1][x-1],dp[i][j-x]);
        dp[i][j] = min(temp,dp[i][j]);
      }
    }
  }
  return dp[eggs][floors];
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
    int eggs,floors;
    cin>>eggs>>floors;
    cout<<eggDrop(eggs,floors)<<endl;
  }
  return 0;
}
