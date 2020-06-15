
// There are N stones, numbered 1,2,…,N1,2,…,N. For each ii (1≤i≤N1≤i≤N),
// the height of Stone i is h-i.
// There is a frog who is initially on Stone 11. He will repeat the following
// action some number of times to reach Stone NN:
// •	If the frog is currently on Stone ii, jump to Stone i+1i+1 or
// Stone i+2i+2. Here, a cost of |hi−hj||hi−hj| is incurred,
// where jj is the stone to land on.
// Find the minimum possible total cost incurred before the frog reaches Stone N.
// IP: 
// 6
// 30 10 60 10 60 50
// OP: 40

#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin>>n;
  vector<int> arr(n+1),dp(n+1,INT_MAX);
  for(int i=0; i<n; i++) cin>>arr[i+1];
  dp[1] = 0;
  int i=1;
  while(i<=n){
    if(i+1 <= n){
      dp[i+1] = min(dp[i+1],dp[i]+abs(arr[i+1]-arr[i]));
    }
    if(i+2 <= n){
      dp[i+2] = min(dp[i+2],dp[i]+abs(arr[i+2]-arr[i]));
    }
    i++;
  }
  cout<<dp[n];
  return 0;
}
