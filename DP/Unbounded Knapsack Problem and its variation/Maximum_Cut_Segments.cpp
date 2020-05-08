// Maximize The Cut Segments
// Given an integer N denoting the Length of a line segment.
// you need to cut the line segment in such a way that the cut length of a line
// segment each time is integer either x , y or z.
// and after performing all cutting operation the total number of cutted segments must be maximum.
// Input
// 2
// 4
// 2 1 1
// 5
// 5 3 2
// Output
// 4
// 2

//One dimensional dp solution
#include <bits/stdc++.h>
using namespace std;
int maxCut(vector<int> arr,int n){
    vector<int> dp(n+1,INT_MIN);
    dp[0] = 0;
    for(int i=0; i<arr.size(); i++){
      for(int j=1; j<n+1; j++){
        if(arr[i] <= j){
          dp[j] = max(1+dp[j-arr[i]],dp[j]);
        }
      }
    }
    return dp[n];
}
void solve(){
    int n;
    cin>>n;
    vector<int> arr(3);
    for(int i=0; i<3; i++){
        cin>>arr[i];
    }
    cout<<maxCut(arr,n)<<endl;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}
