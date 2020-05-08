// Count the no of subsets whose difference is given
// IP: [1,1,2,3]
// OP: 3
// (i) [1,1,2] [3] (ii) [1,3] [1,2] (iii) [1,3] [1,2]

// Let 2 subsets be S1 and S2
// Now,  S1+S2 = Total
//       S1-S2 = Diff
//     ----------------------
//       2*S1 = Total+Diff
//     => S1 = (Total+Diff)/2

#include<bits/stdc++.h>
using namespace std;
int countSubsetsWithGivenDiff(vector<int> arr,int diff){
    int total = 0,n = arr.size();
    for(int x: arr) total += x;
    int S = (total+diff)/2;
    vector<vector<int>> dp(n+1,vector<int>(S+1));
    for(int i=0; i<n+1; i++) dp[i][0] = 1;
    for(int i=1; i<n+1; i++){
      for(int j=1; j<S+1; j++){
        if(arr[i-1] <= j){
          dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
        }
        else{
          dp[i][j] = dp[i-1][j];
        }
      }
    }
    return dp[n][S];
}

int main(){
  int n,diff;
  cin>>n>>diff;
  vector<int> arr(n);
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  cout<<countSubsetsWithGivenDiff(arr,diff)<<endl;
  return 0;
}
