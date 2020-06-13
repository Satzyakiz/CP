// Given a set of distinct positive integers, find the largest
// subset such that every pair (Si, Sj) of elements in this subset satisfies:
//
// Si % Sj = 0 or Sj % Si = 0.
//
// If there are multiple solutions, return any subset is fine.
//
// Example 1:
//
// Input: [1,2,3]
// Output: [1,2] (of course, [1,3] will also be ok)
// Example 2:
//
// Input: [1,2,4,8]
// Output: [1,2,4,8]

vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n == 1 || n==0)
            return nums;
        vector<int> dp(n,1);
        vector<int> parent(n,-1);
        int maxLength = 1,index=0;
        for(int i=0; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(nums[i] % nums[j] == 0 && dp[i] < 1 + dp[j]){
                    dp[i] = 1+dp[j];
                    parent[i] = j;
                }
            }
            if(dp[i] > maxLength){
                index = i;
                maxLength = dp[i];
            }
        }
        if(maxLength == 1)
            return {nums[0]};
        vector<int> ans;
        while(index != -1){
            ans.emplace_back(nums[index]);
            index = parent[index];
        }
        return ans;
    }
