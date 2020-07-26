// Given 3 strings X, Y and Z, the task is to find the longest common 
// sub-sequence in all three given sequences.
//
// Input:
// 1
// 5 8 13
// geeks geeksfor geeksforgeeks
//
// Output:
// 5
//
// Explanation:
// All the 3 strings given have "geeks" as the longest subsequence present
// which has a length of 5.

#include<bits/stdc++.h>
using namespace std;

int LCS(string a,string  b,string c){
    int m = a.size(), n = b.size(), o = c.size();
    int dp[101][101][101];
    memset(dp,0,sizeof(dp));
    int ans = 0;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=o; k++){
                if(a[i-1] == b[j-1] && a[i-1] == c[k-1]){
                    dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
                }else{
                    dp[i][j][k] = max(max(dp[i-1][j][k],dp[i][j-1][k]),dp[i][j][k-1]);
                }
            }
        }
    }
    return dp[m][n][o];
}
void solve(){
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    string s1,s2,s3;
    cin>>s1>>s2>>s3;

    cout<<LCS(s1,s2,s3)<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
