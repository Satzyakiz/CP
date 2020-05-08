// Return True or False if a particular subset is present whose sum is equals to S
// I/P:
// arr = [2 3 7 8 10] sum = 11
// O/P: True
// if sum = 16, O/P: False

//First to last approach
#include<bits/stdc++.h>
using namespace std;


bool subsetSumPresent(vector<int> arr,int S){
  int n = arr.size();
  vector<vector<bool>> dp(n+1,vector<bool>(S+1));
  //No sum of value S can be created using empty subset
  for(int j=0; j<S+1; j++){
    dp[0][j] = false;
  }
  //empty subsets always lead to 0 sum
  //below empty subsets are calculated
  for(int i=0; i<n+1; i++){
    dp[i][0] = true;
  }
  for(int i=1; i<n+1; i++){
    for(int j=1; j<S+1; j++){
      if(arr[i-1] <= j){
        dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
      }
      else{
        dp[i][j] = dp[i-1][j];
      }
    }
  }
  return dp[n][S];
}

int main(){
  int n,S;
  cin>>n>>S;
  vector<int> arr(n);
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  cout<<subsetSumPresent(arr,S)<<endl;
  return 0;
}
