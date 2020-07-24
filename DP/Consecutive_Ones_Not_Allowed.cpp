// Given a positive integer N, count all possible distinct binary strings
// of length N such that there are no consecutive 1’s. Output your answer
// mod 10^9 + 7.
// Example:
// Input:
// 2
// 3
// 2
// Output:
// 5
// 3
// Explanation:
// Testcase 1: case 5 strings are (000, 001, 010, 100, 101)
// Testcse 2:  case 3 strings are (00,01,10)


//Fibonacci Pattern

#include<bits/stdc++.h>
using namespace std;

vector<int> dp(101);

void solve(){
    int n;
    cin>>n;
    int mod = 1e9+7;
    if(dp[n] != 0){
        cout<<dp[n]<<endl;
        return;
    }
    for(int i=3; i<=n; i++){
        dp[i] = (dp[i-1] + dp[i-2])%mod;
    }
    cout<<dp[n]<<endl;
}

int main(){
    int t;
    cin>>t;
    dp[0] = 0;
    dp[1] = 2;
    dp[2] = 3;
    while(t--)
        solve();
    return 0;
}
