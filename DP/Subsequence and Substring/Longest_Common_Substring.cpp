// Given two strings X and Y. The task is to find the length of the longest
// common substring.
// Input:
// 2
// 6 6
// ABCDGH
// ACDGHR
// 3 2
// ABC
// AC
//
// Output:
// 4
// 1
//
// Example:
// Testcase 1: CDGH is the longest substring present in both of the strings.

#include<bits/stdc++.h>
using namespace std;

int LCS(string a,string  b){
    int m = a.size(), n = b.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1));
    int ans = 0;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    return ans;
}
void solve(){
    int n1,n2;
    cin>>n1>>n2;
    string s1,s2;
    cin>>s1>>s2;

    cout<<LCS(s1,s2)<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
