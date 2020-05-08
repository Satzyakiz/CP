// 0/1 KnapSack
// I/P:
// 3
// 4 
// 1 2 3
// 4 5 1
// O/P:
// 3
//
// I/P:
// 3
// 3
// 1 2 3
// 4 5 6
// O/P:
// 0
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
          dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]] , dp[i-1][j]);
           // val[i-1]+dp[i-1][W-wt[i-1]]: It is considered when the item is chosen
           // or taken in the knapsack
           // dp[i-1][W]: It is considered when the item is not chosen in the knapsack
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
