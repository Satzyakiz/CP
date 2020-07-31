//MCM Variation

// Given n balloons, indexed from 0 to n-1. Each balloon is painted with a
// number on it represented by array nums. You are asked to burst all the
// balloons. If the you burst balloon i you will get
// nums[left] * nums[i] * nums[right] coins. Here left and right
// are adjacent indices of i. After the burst, the left and right then
// becomes adjacent.
//
// Find the maximum coins you can collect by bursting the balloons wisely.
//
// Example:
//
// Input: [3,1,5,8]
// Output: 167
// Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
//              coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167

int maxCoins(vector<int>& nums) {
    int n = nums.size();
    if(n == 0)
        return 0;
    nums.emplace_back(1);
    n += 1;
    vector<vector<int>> dp(n,vector<int>(n));

    for(int len = 2; len <= n; len++){
        for(int left = 0; left < n-len+1; left++){
            int right = left+len-1;
            for(int k = left; k < right; k++){
                int temp = dp[left][k] + dp[k+1][right];
                temp += (left == 0) ? nums[k]*nums[right] : nums[left-1]*nums[k]*nums[right];
                dp[left][right] = max(temp,dp[left][right]);
            }
        }
    }
    return dp[0][n-1];
}
