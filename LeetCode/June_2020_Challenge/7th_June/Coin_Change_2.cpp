// Example 1:
//
// Input: amount = 5, coins = [1, 2, 5]
// Output: 4
// Explanation: there are four ways to make up the amount:
// 5=5
// 5=2+2+1
// 5=2+1+1+1
// 5=1+1+1+1+1
// Example 2:
//
// Input: amount = 3, coins = [2]
// Output: 0
// Explanation: the amount of 3 cannot be made up just with coins of 2.
// Example 3:
//
// Input: amount = 10, coins = [10]
// Output: 1

int change(int m, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int j=0; j<m+1; j++)
            dp[0][j] = 0;
        for(int i=0; i<n+1; i++)
            dp[i][0] = 1;
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(coins[i-1] <= j){
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
