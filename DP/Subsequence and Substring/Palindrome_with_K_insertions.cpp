// Given a string you have to transform it into a palindrome .
// In order to acheive that you have to perform exactly k
// insertion of characters(you cannot perform any more or less
// number of insertions).Now you have to report whether the
// string can be converted to a palindrome by making exactly k insertions.
//
// Input :
//
// 2
//
// 4 2
//
// abac
//
// 5 3
//
// abcde
//
// Output :
//
// YES
//
// NO

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int LCS(string a,string b){
    int n = a.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][n];
}
int LPS(string s){
    string b = s;
    reverse(b.begin(),b.end());
    return LCS(s,b);
}
void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    if(n - LPS(s) <= k)
        cout<<"YES\n";
    else
        cout<<"NO\n";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
