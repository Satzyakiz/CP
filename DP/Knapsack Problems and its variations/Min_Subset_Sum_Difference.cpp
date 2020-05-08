// Divide the set into subsets such that the difference of sum
// of the subsets is minimum
// IP: [1 3 7]
// OP: 3 --> [7] - [1 3] : 7 - 4 = 3

// Logic:
// Let the subsets be S1 and S2 and let S2 > S1.
// Target: S2 - S1 should be min.
// Total -> S1 + S2 (Sum of all elements)
// Therefore, target: Total - S1 - S1 -> Total - 2*S1 should be minimum

#include <bits/stdc++.h>
using namespace std;
int minSubsetSumDifference(int arr[],int n){
  int total = 0;
  for(int i=0; i<n; i++){
      total += arr[i];
  }

  bool dp[n+1][total+1];
  for(int j=0; j<total+1; j++){
      dp[0][j] = false;
  }
  for(int i=0; i<n+1; i++){
    dp[i][0] = true;
  }
  for(int i=1; i<n+1; i++){
    for(int j=1; j<total+1; j++){
        dp[i][j] = dp[i-1][j];
        if(arr[i-1] <= j){
            dp[i][j] = dp[i][j] || dp[i-1][j-arr[i-1]];
        }
    }
  }
  //The last row of DP matrix consists of the subset values that are possible in certain subsets
  int diff = INT_MAX;
  for (int j=0; j<total+1; j++) {
        if (dp[n][j] == true)
        {
            diff = min(diff,abs(total-2*j));
        }
    }
  return diff;
}

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<minSubsetSumDifference(arr,n)<<endl;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}
