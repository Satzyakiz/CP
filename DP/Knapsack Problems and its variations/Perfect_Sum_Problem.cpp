// Given an array of integers and a sum, the task is to count all 
// subsets of given array with sum equal to given sum.
//
// Input:
// 2
// 6
// 2 3 5 6 8 10
// 10
// 5
// 1 2 3 4 5
// 10
//
// Output:
// 3
// 3

#include<bits/stdc++.h>
using namespace std;

int subsetSum(vector<int> &arr,int sum){
    int n = arr.size(), mod = 1e9+7;
    vector<vector<long long>> dp(n+1,vector<long long>(sum+1));
    for(int j=0; j<=sum; j++)
        dp[0][j] = 0;
    for(int i=0; i<=n; i++)
        dp[i][0] = 1;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(arr[i-1] <= j){
                dp[i][j] = (dp[i-1][j-arr[i-1]] + dp[i-1][j])%mod;
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][sum]%mod;

}
void solve(){
    int n,x;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    cin>>x;
    cout<<subsetSum(arr,x)<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
