// You are given a list of non-negative integers,
// a1, a2, ..., an, and a target, S. Now you have 2 symbols
// + and -. For each integer, you should choose one from + and -
// as its new symbol.
//
// Find out how many ways to assign symbols to make sum of
// integers equal to target S.
//
// Example 1:
// Input: nums is [1, 1, 1, 1, 1], S is 3.
// Output: 5
// Explanation:
//
// -1+1+1+1+1 = 3
// +1-1+1+1+1 = 3
// +1+1-1+1+1 = 3
// +1+1+1-1+1 = 3
// +1+1+1+1-1 = 3
//
// There are 5 ways to assign symbols to make the sum of nums be target 3.
//Extension of subset with given difference problem

// **************************************
// Do not initialize the 1st row
// **************************************
int findTargetSumWays(vector<int>& nums, int S) {
        int total = 0;
        for(int x: nums) total += x;
        if(total < S) return 0;
        if((total + S) % 2) return 0; //If sum is odd,then subset impossible
        int target = (total + S)/2;
        vector<vector<int>> dp(nums.size()+1,vector<int>(target+1));

        for(int i=0; i<nums.size()+1; i++)
          dp[i][0] = 1;
        for(int i=1; i<nums.size()+1; i++){
            for(int j=0; j<target+1; j++){
                if(nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[nums.size()][target];
    }
