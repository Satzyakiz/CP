// There are NN items, numbered 1,2,…,N1,2,…,N. For each ii (1≤i≤N1≤i≤N), 
// Item ii has a weight of wiwi and a value of vivi.
// Taro has decided to choose some of the NN items and carry them home
// in a knapsack. The capacity of the knapsack is WW, which means that
// the sum of the weights of items taken must be at most WW.
// Find the maximum possible sum of the values of items that Taro takes home.
// Sample Input 1
// 3 8
// 3 30
// 4 50
// 5 60
// Sample Output 1
// 90
// Items 11 and 33 should be taken. Then, the sum of the weights
// is 3+5=83+5=8, and the sum of the values is 30+60=9030+60=90.
// ________________________________________
// Sample Input 2
// 5 5
// 1 1000000000
// 1 1000000000
// 1 1000000000
// 1 1000000000
// 1 1000000000
// Sample Output 2
// 5000000000
// The answer may not fit into a 32-bit integer type.


#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
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
