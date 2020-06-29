// 
// Say you have an array for which the i-th element is the price of
// a given stock on day i.
//
// Design an algorithm to find the maximum profit. You may complete at
// most k transactions.
//
// Note:
// You may not engage in multiple transactions at the same time
// (ie, you must sell the stock before you buy again).
//
// Example 1:
//
// Input: [2,4,1], k = 2
// Output: 2
// Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4),
// profit = 4-2 = 2.
// Example 2:
//
// Input: [3,2,6,5,0,3], k = 2
// Output: 7
// Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6),
// profit = 6-2 = 4.
//              Then buy on day 5 (price = 0) and sell on day 6 (price = 3),
//              profit = 3-0 = 3.


int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    if(n == 0) return 0;
    if (k >= n / 2) {
        int profit = 0;
        for (int i = 1; i < n; i++)
            if (prices[i] > prices[i - 1]) profit += prices[i] - prices[i - 1];
        return profit;
    }
    vector<vector<int>> dp(k+1,vector<int>(n));

    for(int K=1; K<=k; K++){
        int minPrice = prices[0];
        for(int i=1; i<n; i++){
            minPrice = min(minPrice, prices[i] - dp[K-1][i-1]);
            dp[K][i] = max(dp[K][i-1],prices[i] - minPrice);
        }
    }

    return dp[k][n-1];
}
