

// We have N persons sitting on a round table. Any person can do a
// handshake with any other person.
//
//     1
// 2        3
//     4
// Handshake with 2-3 and 1-4 will cause cross.
//
// In how many ways these N people can make handshakes so that no two
// handshakes crosses each other. N would be even.
//
// For example, in above diagram, there are two non-crossing ways to
// handshake {{1, 2}, {3, 4}} and {{1, 3}, {2, 4}}.
// Input:
// 2
// 2
// 8
//
// Output:
// 1
// 14

//Application of Catalan Numbers


#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> dp(16);

int catalan(int n){
    dp[0] = dp[1] = 1;
    for(int i=2; i<=n; i++){
        dp[i] = 0;
        for(int j=1; j<=i; j++){
            dp[i] += dp[j-1] * dp[i-j];
        }
    }
    return dp[n];
}
void solve(){
    int n;
    cin>>n;
    dp.clear();
    cout<<catalan(n/2)<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
