// Input:
// 2
// 5
// 1 2 3 4 5
// 3
// 3 3 3
// Output:
// 38
// 27

//Strategy: Same as recursive, just add a loop for chain length.

#include<bits/stdc++.h>
using namespace std;

int mcm(vector<int> arr){
  int n = arr.size();
  vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
  for(int i=0; i<n; i++) dp[i][i] = 0;

  for(int L=2; L<=n; L++){ //length of chain
    for(int i=1; i<n-L+1; i++){
      int j = i+L-1;
      for(int k=i; k<j; k++){
        int temp = dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j];
        dp[i][j] = min(dp[i][j],temp);
      }
    }
  }
  return dp[1][n-1];
  //dp[1][n-1]: 0th row is unused as 1 matrix need not have a multiplication
  //at least 2 matrices are required for multiplication
}

int main(){
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0; i<n; i++) cin>>arr[i];
  cout<<mcm(arr)<<endl;
  return 0;
}
