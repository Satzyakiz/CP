// You are given coins of different denominations and a total
// amount of money amount. Write a function to compute the fewest number
// of coins that you need to make up that amount.
// If that amount of money cannot be made up by any combination of the coins,
// return -1
// Input: coins = [1, 2, 5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1
// Input: coins = [2], amount = 3
// Output: -1

//Solution using 1D dp array
int coinChange(vector<int>& coins, int m) {
        int n = coins.size();
        vector<int> dp(m+1);
        dp[0] = 0;
        for(int i=1; i<m+1; i++){
          //initialize the first column with infinite. i.e. we need infinite coins to make that value
            dp[i] = INT_MAX-1;  //To avoid integer overflow in min() statement
        }
        for(int i=0; i<n; i++){
            for(int j=coins[i]; j<m+1; j++){
                dp[j] = min(1+dp[j-coins[i]], dp[j]);
            }
        }

        return dp[m] == INT_MAX-1 ? -1 : dp[m];
}
