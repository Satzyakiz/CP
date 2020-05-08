// Return True or False if a equal sum subsets are present.
//If the sum of all elements are even, there is a possibility, but if the sum of
//all nos is odd, return False as it would be impossible to break that into equal sum
//subsets.
// I/P:
// arr = [1 5 11 5] --> [1 5 5] [ 11 ]
// O/P: True
// I/P:
// arr = [3 6 11 6] --> Impossible , subset of val 13 is not found
// O/P: False


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
  int n;
  cin>>n;
  vector<int> arr(n);
  int sum = 0;
  for(int i=0; i<n; i++){
    cin>>arr[i];
    sum += arr[i];
  }
  if(sum & 1){
      cout<<"Impossible\n";
  }
  else{
      if(subsetSumPresent(arr,sum/2)){
          cout<<"Possible\n";
      }
      else
        cout<<"Impossible\n";
  }
  return 0;
}
