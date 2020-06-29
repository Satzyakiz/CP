

// Example 1:
// Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
// Output: 8
// Explanation: The maximum profit can be achieved by:
// Buying at prices[0] = 1
// Selling at prices[3] = 8
// Buying at prices[4] = 4
// Selling at prices[5] = 9
// The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.


int maxProfit(vector<int>& prices, int fee) {
    int s0, s1;
    s0 = 0, s1 = INT_MIN;
    for(int p: prices){
        int temp = s0;
        s0 = max(s0, s1+p);
        s1 = max(s1, temp-p-fee);
    }
    return s0;
}
