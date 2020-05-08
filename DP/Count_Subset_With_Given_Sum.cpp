//Get the count of subsets whose sum is equal to S
//IP: [2 3 7 8 10] S = 10
//OP: 3 --> [2 8],[3 7],[10]

#include<bits/stdc++.h>
using namespace std;

int countEqualSumSubset(vector<int> arr,int S){
  int n = arr.size();
  vector<vector<int>> dp(n+1,vector<int>(S+1));
  for(int i=0; i<S+1; i++)
    dp[0][i] = 0;
  for(int i=0; i<n+1; i++)
    dp[i][0] = 1;
  for(int i=1; i<n+1; i++){
    for(int j=1; j<S+1; j++){
      if(arr[i-1] <= j){
        dp[i][j] = dp[i-1][j]+dp[i-1][j-arr[i-1]];
      }
      else{
        dp[i][j] = dp[i-1][j];
      }
    }
  }
  //visualizing dp matrix
//   for(int i=0; i<n+1; i++){
//       for(int j=0; j<S+1; j++){
//           cout<<dp[i][j]<<"   ";
//       }
//       cout<<endl;
//   }
  return dp[n][S];
}

int main(){
  int n,S;
  cin>>n>>S;
  vector<int> arr(n);
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  cout<<countEqualSumSubset(arr,S)<<endl;
  return 0;
}
