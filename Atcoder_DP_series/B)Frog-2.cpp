// There are NN stones, numbered 1,2,…,N1,2,…,N. For each ii (1≤i≤N1≤i≤N), 
// the height of Stone ii is hihi.
// There is a frog who is initially on Stone 11. He will repeat the following
// action some number of times to reach Stone NN:
// •	If the frog is currently on Stone ii, jump to one of the following:
// Stone i+1,i+2,…,i+Ki+1,i+2,…,i+K. Here, a cost of |hi−hj||hi−hj| is
// incurred, where jj is the stone to land on.
// Find the minimum possible total cost incurred before the
// frog reaches Stone NN.
// IP:
// 3 1
// 10 20 10
// OP:
// 20


#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,k;
  cin>>n>>k;
  vector<int> arr(n+1),dp(n+1,INT_MAX);
  for(int i=0; i<n; i++) cin>>arr[i+1];
  dp[1] = 0;
  int i=1;
  while(i<=n){
    for(int j=1; j<=k; j++){
      if(i+j > n)
        break;
      dp[i+j] = min(dp[i+j],dp[i] + abs(arr[i+j] - arr[i]));
    }
    i++;
  }
  cout<<dp[n];
  return 0;
}
