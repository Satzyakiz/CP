//In unbounded knapsack, an element can be chosen multiple times
// unlike 0-1 knapsack where each item can be chosen only once
#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int> val,vector<int> wt,int W,int n){
  vector<vector<int>> dp(n+1,vector<int>(W+1));
  for(int i=0; i<n+1; i++){
    for(int j=0; j<W+1; j++){
      if(i == 0 || j == 0){
        dp[i][j] = 0;
      }
      else{
        if(wt[i-1] <= j){
          //here j is current weight of KnapSack(the max curr wt)
          dp[i][j] = max(val[i-1]+dp[i][j-wt[i-1]] , dp[i-1][j]);
          //The current element can also be chosen another time (infinite times)
          // val[i-1]+dp[i][j-wt[i-1]] --> this part has the only change compared to 0-1 Knapsack
          // dp[i][j-wt[i-1]] : the "i" part. "i" instead of "i-1".
        }
        else{
          dp[i][j] = dp[i-1][j];
        }
      }
    }
  }
  return dp[n][W];
}

int main(){
  int n,W;
  cin>>n>>W;
  vector<int> val(n);
  vector<int> wt(n);
  for(int i=0; i<n; i++){
    cin>>val[i];
  }
  for(int i=0; i<n; i++){
    cin>>wt[i];
  }
  cout<<knapsack(val,wt,W,n)<<endl;
  return 0;
}
