// You are given coins of different denominations and a total amount of money.
// Write a function to compute the number of combinations that make up that amount.
// You may assume that you have infinite number of each kind of coin.

// Input: amount = 5, coins = [1, 2, 5]
// Output: 4
// Explanation: there are four ways to make up the amount:
// 5=5
// 5=2+2+1
// 5=2+1+1+1
// 5=1+1+1+1+1
// Input: amount = 3, coins = [2]
// Output: 0
// Explanation: the amount of 3 cannot be made up just with coins of 2.
int change(int m, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1));
        //No value can be made without having any coin
        for(int j=1; j<m+1; j++){
            dp[0][j] = 0;
        }
        //Very important, initialize the first column with 1, as
        // value 0 can be made in one way, without choosing any item
        // among available items
        for(int i=0; i<n+1; i++){
            dp[i][0] = 1;
        }
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(coins[i-1] <= j){
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j]; // + is used where we want to get the count.
                    //for boolean or true or false cases, we use or(||)
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][m];
}


//O(n) space
#include<bits/stdc++.h>
using namespace std;

int get(vector<int> &coins, int x){
    vector<int> dp(x+1);
    dp[0] = 1;
    for(int i=0; i<coins.size(); i++){
        for(int j=coins[i]; j<=x; j++){
            dp[j] += dp[j-coins[i]];
        }
    }

    return dp[x];
}
void solve(){
    int n;
    cin>>n;
    vector<int> coins(n);
    for(int i=0; i<n; i++) cin>>coins[i];
    int s;
    cin>>s;
    cout<<get(coins,s)<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
